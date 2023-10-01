#include "GLViewer.h"
#include "mainwindow.h"

#include <QMouseEvent>

GLViewer::GLViewer() {}

/**
 * Конструктор используемый при размещении на форме
 * @brief GLViewer::GLViewer
 * @param parent
 */
GLViewer::GLViewer(QWidget *parent) : QOpenGLWidget(parent) {
  mw = static_cast<MainWindow *>(parent->parent());
}

void GLViewer::setModel(object newModel) { model = newModel; }

void GLViewer::initializeGL() {
  rotateScale = 1;
  glEnable(GL_CULL_FACE);
  model.amount_p = 0;
  model.amount_v = 0;
}

void GLViewer::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
  diagonal = GLfloat(width) / height;
}

/**
 * Эта функция вызывается при обновлении изображения
 */
void GLViewer::paintGL() {

  glClearColor(backColor.red() / 255.0, backColor.green() / 255.0,
               backColor.blue() / 255.0, 1.0f);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (isCentral)
    glFrustum((-diagonal) * 2, diagonal * 2, -2.0, 2.0, 6.0, 150.0);
  else
    glOrtho((-diagonal) * 2, diagonal * 2, -2.0, 2.0, 6.0, 150.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glGetFloatv(GL_MODELVIEW_MATRIX, m_tmp);

  s21_translate(m_tmp, positionX, positionY, positionZ);

  s21_rotate(m_tmp, rotationX, 1.0, 0.0, 0.0);
  s21_rotate(m_tmp, rotationY, 0.0, 1.0, 0.0);
  s21_rotate(m_tmp, rotationZ, 0.0, 0.0, 1.0);

  s21_scale(m_tmp, scale, scale, scale);

  glLoadMatrixf(m_tmp);

  glPointSize(vertexSize);
  glLineWidth(edgeThickness);

  if (model.amount_p != 0 || model.amount_v != 0)
    drawModel();
}

void GLViewer::drawModel() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  for (int i = 0; i < model.amount_p; i++) {
    glLoadName(i);
    glBegin(GL_POLYGON);
    glColor3d(0.65, 0.65, 0.65);

    for (int j = 0; j < model.p[i].amount_f; j++) {
      vertex vert = model.v[model.p[i].f[j] - 1];
      glVertex3f(vert.x, vert.y, vert.z);
    }
    glEnd();
  }

  // Рисуем ребра
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  if (edgeType == EdgeType::dotted) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(5, 58360);
  }

  for (int i = 0; i < model.amount_p; i++) {
    glLoadName(i);
    glBegin(GL_TRIANGLES);
    glColor3d(edgeColor.red() / 255.0, edgeColor.green() / 255.0,
              edgeColor.blue() / 255.0);

    for (int j = 0; j < model.p[i].amount_f; j++) {
      vertex vert = model.v[model.p[i].f[j] - 1];
      glVertex3f(vert.x, vert.y, vert.z);
    }
    glEnd();
  }

  if (edgeType == EdgeType::dotted)
    glDisable(GL_LINE_STIPPLE);

  if (vertexType != VertexType::disable) {
    // Рисуем вершины
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

    if (vertexType == VertexType::square)
      glDisable(GL_POINT_SMOOTH);
    else if (vertexType == VertexType::circle) {
      glEnable(GL_POINT_SMOOTH);
    }

    for (int i = 0; i < model.amount_p; i++) {
      glLoadName(i);
      glBegin(GL_TRIANGLES);
      glColor3d(vertexColor.red() / 255.0, vertexColor.green() / 255.0,
                vertexColor.blue() / 255.0);

      for (int j = 0; j < model.p[i].amount_f; j++) {
        vertex vert = model.v[model.p[i].f[j] - 1];
        glVertex3f(vert.x, vert.y, vert.z);
      }

      glEnd();
    }
  }
}

/** Методы поворота модели **/

void GLViewer::mousePressEvent(QMouseEvent *event) { lastPos = event->pos(); }

void GLViewer::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {

    setRotateX(180 / rotateScale * (GLfloat)(event->y() - lastPos.y()) /
                   height(),
               true);
    setRotateY(180 / rotateScale * (GLfloat)(event->x() - lastPos.x()) /
                   width(),
               true);
  } else if (event->buttons() & Qt::RightButton) {

    setRotateX(180 / rotateScale * (GLfloat)(event->y() - lastPos.y()) /
                   height(),
               true);
    setRotateZ(180 / rotateScale * (GLfloat)(event->x() - lastPos.x()) /
                   width(),
               true);
  }

  update();

  lastPos = event->pos();
}

void GLViewer::setRotateX(GLfloat x, bool isAdd) {
  if (isAdd)
    rotationX += x;
  else
    rotationX = x;

  if (rotationX > 360)
    rotationX -= 360;
  else if (rotationX < -360)
    rotationX += 360;

  mw->SetViewRotateX(rotationX);
}

void GLViewer::setRotateY(GLfloat y, bool isAdd) {

  if (isAdd)
    rotationY += y;
  else
    rotationY = y;

  if (rotationY > 360)
    rotationY -= 360;
  else if (rotationY < -360)
    rotationY += 360;

  mw->SetViewRotateY(rotationY);
}

void GLViewer::setRotateZ(GLfloat z, bool isAdd) {

  if (isAdd)
    rotationZ += z;
  else
    rotationZ = z;

  if (rotationZ > 360)
    rotationZ -= 360;
  else if (rotationZ < -360)
    rotationZ += 360;

  mw->SetViewRotateZ(rotationZ);
}

/** Методы изменения позиций модели**/

void GLViewer::setPositionX(GLfloat x) { positionX = x; }

void GLViewer::setPositionY(GLfloat y) { positionY = y; }

void GLViewer::setPositionZ(GLfloat z) { positionZ = z; }

/** Методы изменения масштаба модели**/

void GLViewer::setScale(GLfloat scale) { this->scale = scale; }

/**
 *  Задать проекцию пространства
 * @brief GLViewer::setProjection
 * @param isCentral
 */
void GLViewer::setProjection(bool isCentral) { this->isCentral = isCentral; }

void GLViewer::setEdgeType(EdgeType type) { edgeType = type; }

void GLViewer::setEdgeThickness(GLfloat thickness) {
  edgeThickness = thickness;
}

void GLViewer::setEdgeColor(QColor color) { edgeColor = color; }

void GLViewer::setVertexType(VertexType type) { vertexType = type; }

void GLViewer::setVertexSize(GLfloat size) { vertexSize = size; }

void GLViewer::setVertexColor(QColor color) { vertexColor = color; }

void GLViewer::setBackColor(QColor color) { backColor = color; }
