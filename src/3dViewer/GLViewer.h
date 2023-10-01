#ifndef GLVIEWER_H
#define GLVIEWER_H

#include <QOpenGLWidget>

#include "../Parser/parser.h"
#include "../Transformer/transformer.h"
#include "mainwindow.h"

enum class EdgeType { solid = 0, dotted = 1 };
enum class VertexType { circle = 0, square = 1, disable = 2 };

class GLViewer : public QOpenGLWidget {
public:
  GLViewer();
  GLViewer(QWidget *parent = nullptr);

public slots:
  void setRotateX(GLfloat x, bool isAdd);
  void setRotateY(GLfloat y, bool isAdd);
  void setRotateZ(GLfloat z, bool isAdd);

  void setPositionX(GLfloat x);
  void setPositionY(GLfloat y);
  void setPositionZ(GLfloat z);

  void setScale(GLfloat scale);

  void setModel(object newModel);

  void setProjection(bool isCentral);

  void setEdgeType(EdgeType type);
  void setEdgeThickness(GLfloat thickness);
  void setEdgeColor(QColor color);

  void setVertexType(VertexType type);
  void setVertexSize(GLfloat size);
  void setVertexColor(QColor color);

  void setBackColor(QColor color);

  object model;

protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  // void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
  void drawModel();
  float m_tmp[16];

  GLfloat rotationX;
  GLfloat rotationY;
  GLfloat rotationZ;
  GLfloat rotateScale;

  GLfloat positionX;
  GLfloat positionY;
  GLfloat positionZ;

  GLfloat scale;

  QPoint lastPos;
  MainWindow *mw;

  GLfloat diagonal;
  bool isCentral;

  EdgeType edgeType;
  GLfloat edgeThickness;
  QColor edgeColor;

  VertexType vertexType;
  GLfloat vertexSize;
  QColor vertexColor;

  QColor backColor;
};

#endif // GLVIEWER_H
