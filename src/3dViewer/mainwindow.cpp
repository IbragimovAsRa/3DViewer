#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QDataStream>
#include <QDoubleValidator>
#include <QFileDialog>
#include <QMetaType>
#include <QSettings>
#include <QStandardPaths>
#include <QVariant>

#include "../Parser/parser.h"

Q_DECLARE_METATYPE(QList<int>)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  qRegisterMetaType<QList<int>>("QList<int>");

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  float rotateX = settings.value("rotateX", 0).toFloat();
  float rotateY = settings.value("rotateY", 0).toFloat();
  float rotateZ = settings.value("rotateZ", 0).toFloat();

  float positionX = settings.value("positionX", 0).toFloat();
  float positionY = settings.value("positionY", 0).toFloat();
  float positionZ = settings.value("positionZ", -10).toFloat();

  float scale = settings.value("scale", 1).toFloat();

  bool isCentral = settings.value("isCentral", true).toBool();

  float edgeThickness = settings.value("edgeThickness", 1).toFloat();
  EdgeType edgeType = (EdgeType)settings.value("edgeType", 0).toInt();

  QList<int> defaultColor = {0, 0, 0};

  QList<int> edgeListColor =
      settings.value("edgeColor", QVariant::fromValue(defaultColor))
          .value<QList<int>>();
  QColor edgeColor =
      QColor::fromRgb(edgeListColor[0], edgeListColor[1], edgeListColor[2]);

  float vertexSize = settings.value("vertexSize", 1).toFloat();
  VertexType vertexType = (VertexType)settings.value("vertexType", 0).toInt();

  QList<int> vertexListColor =
      settings.value("vertexColor", QVariant::fromValue(defaultColor))
          .value<QList<int>>();
  QColor vertexColor = QColor::fromRgb(vertexListColor[0], vertexListColor[1],
                                       vertexListColor[2]);

  QList<int> defaultBack = {255, 255, 255};
  QList<int> listBackColor =
      settings.value("backColor", QVariant::fromValue(defaultBack))
          .value<QList<int>>();
  QColor backColor =
      QColor::fromRgb(listBackColor[0], listBackColor[1], listBackColor[2]);

  ui->openGLWidget->setRotateX(rotateX, false);
  ui->doubleSpinBox_rotate_x->setValue(rotateX);
  ui->horizontalSlider_rotate_x->setValue(rotateX);

  ui->openGLWidget->setRotateY(rotateY, false);
  ui->doubleSpinBox_rotate_z->setValue(rotateY);
  ui->horizontalSlider_rotate_z->setValue(rotateY);

  ui->openGLWidget->setRotateZ(rotateZ, false);
  ui->doubleSpinBox_rotate_z->setValue(rotateZ);
  ui->horizontalSlider_rotate_z->setValue(rotateZ);

  ui->openGLWidget->setPositionX(positionX);
  ui->doubleSpinBox_position_x->setValue(positionX);
  ui->horizontalSlider_position_x->setValue(positionX);

  ui->openGLWidget->setPositionY(positionY);
  ui->doubleSpinBox_position_y->setValue(positionY);
  ui->horizontalSlider_position_y->setValue(positionY);

  ui->openGLWidget->setPositionZ(positionZ);
  ui->doubleSpinBox_position_z->setValue(positionZ);
  ui->horizontalSlider_position_z->setValue(positionZ);

  ui->openGLWidget->setScale(scale);
  ui->doubleSpinBox_scale->setValue(scale);
  ui->horizontalSlider_scale->setValue(scale);

  ui->openGLWidget->setProjection(isCentral);
  ui->radioButton_parallel->setChecked(!isCentral);
  ui->radioButton_central->setChecked(isCentral);

  ui->openGLWidget->setEdgeThickness(edgeThickness);
  ui->doubleSpinBox_edgeThickness->setValue(edgeThickness);

  ui->openGLWidget->setEdgeType(edgeType);
  ui->comboBox_edgeType->setCurrentIndex((int)edgeType);

  ui->pushButton_color->setStyleSheet(
      QString("background-color: rgb(%1, %2, %3)")
          .arg(edgeColor.red())
          .arg(edgeColor.green())
          .arg(edgeColor.blue()));
  ui->openGLWidget->setEdgeColor(edgeColor);

  ui->openGLWidget->setVertexSize(vertexSize);
  ui->doubleSpinBox_vertexSize->setValue(vertexSize);

  ui->openGLWidget->setVertexType(vertexType);
  ui->comboBox_vertexType->setCurrentIndex((int)vertexType);

  ui->pushButton_vertexColor->setStyleSheet(
      QString("background-color: rgb(%1, %2, %3)")
          .arg(vertexColor.red())
          .arg(vertexColor.green())
          .arg(vertexColor.blue()));
  ui->openGLWidget->setVertexColor(vertexColor);

  ui->pushButton_backColor->setStyleSheet(
      QString("background-color: rgb(%1, %2, %3)")
          .arg(backColor.red())
          .arg(backColor.green())
          .arg(backColor.blue()));
  ui->openGLWidget->setBackColor(backColor);
}

MainWindow::~MainWindow() {

  if (ui->openGLWidget->model.amount_p != 0 ||
      ui->openGLWidget->model.amount_v != 0)
    free_object(&ui->openGLWidget->model);

  delete ui;
}

void MainWindow::on_action_selectFile_triggered() {

  QString desctopPath = QString("%1/autoexec.cfg")
                            .arg(QStandardPaths::writableLocation(
                                QStandardPaths::DesktopLocation));
  QString selfilter = tr("OBJ (*.obj)");
  QString filePath = QFileDialog::getOpenFileName(
      this, "Выберите файл модели", desctopPath, tr("OBJ (*.obj)"), &selfilter);

  QByteArray byteArray = filePath.toLocal8Bit();
  char *strFilePath = byteArray.data();

  ui->statusbar->showMessage("Загрузка модели", 10000);

  object model = parser(strFilePath);

  if (model.amount_p == 0 || model.amount_v == 0) {
    ui->statusbar->showMessage("Невалидная модель", 10000);
    return;
  }

  QStringList splitFilePath = filePath.split("/");
  if (splitFilePath.count() > 0)
    ui->label_filename->setText(splitFilePath.value(splitFilePath.count() - 1));
  ui->label_vertex_count->setText(QString::number(model.amount_v));
  ui->label_edge_count->setText(QString::number(model.amount_p));

  ui->openGLWidget->setModel(model);
  ui->openGLWidget->update();

  ui->statusbar->showMessage("Модель загружена", 1000);
}

/** Методы поворота модели **/

void MainWindow::SetViewRotateX(float rotateX) {
  if (!lock_doubleSpinBox_rotate_x)
    ui->doubleSpinBox_rotate_x->setValue(rotateX);

  lock_doubleSpinBox_rotate_x = false;

  if (!lock_horizontalSlider_rotate_x)
    ui->horizontalSlider_rotate_x->setValue((int)rotateX);

  lock_horizontalSlider_rotate_x = false;

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateX", QVariant::fromValue(rotateX));
}

void MainWindow::SetViewRotateY(float rotateY) {
  if (!lock_doubleSpinBox_rotate_y)
    ui->doubleSpinBox_rotate_y->setValue(rotateY);

  lock_doubleSpinBox_rotate_y = false;

  if (!lock_horizontalSlider_rotate_y)
    ui->horizontalSlider_rotate_y->setValue((int)rotateY);

  lock_horizontalSlider_rotate_y = false;

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateY", QVariant::fromValue(rotateY));
}

void MainWindow::SetViewRotateZ(float rotateZ) {
  if (!lock_doubleSpinBox_rotate_z)
    ui->doubleSpinBox_rotate_z->setValue(rotateZ);

  lock_doubleSpinBox_rotate_z = false;

  if (!lock_horizontalSlider_rotate_z)
    ui->horizontalSlider_rotate_z->setValue((int)rotateZ);

  lock_horizontalSlider_rotate_z = false;

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateZ", QVariant::fromValue(rotateZ));
}

void MainWindow::on_doubleSpinBox_rotate_x_valueChanged(double x) {
  lock_doubleSpinBox_rotate_x = true;
  ui->openGLWidget->setRotateX(x, false);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateX", QVariant::fromValue(x));
}

void MainWindow::on_doubleSpinBox_rotate_y_valueChanged(double y) {
  lock_doubleSpinBox_rotate_y = true;
  ui->openGLWidget->setRotateY(y, false);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateY", QVariant::fromValue(y));
}

void MainWindow::on_doubleSpinBox_rotate_z_valueChanged(double z) {
  lock_doubleSpinBox_rotate_z = true;
  ui->openGLWidget->setRotateZ(z, false);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateZ", QVariant::fromValue(z));
}

void MainWindow::on_horizontalSlider_rotate_x_sliderMoved(int x) {
  lock_horizontalSlider_rotate_x = true;
  ui->openGLWidget->setRotateX(x, false);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateX", QVariant::fromValue(x));
}

void MainWindow::on_horizontalSlider_rotate_y_sliderMoved(int y) {
  lock_horizontalSlider_rotate_y = true;
  ui->openGLWidget->setRotateY(y, false);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateY", QVariant::fromValue(y));
}

void MainWindow::on_horizontalSlider_rotate_z_sliderMoved(int z) {
  lock_horizontalSlider_rotate_z = true;
  ui->openGLWidget->setRotateZ(z, false);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("rotateZ", QVariant::fromValue(z));
}

/** Методы изменения позиций модели**/

void MainWindow::on_doubleSpinBox_position_x_valueChanged(double x) {
  ui->openGLWidget->setPositionX(x);
  ui->horizontalSlider_position_x->setValue(x);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("positionX", QVariant::fromValue(x));
}

void MainWindow::on_doubleSpinBox_position_y_valueChanged(double y) {
  ui->openGLWidget->setPositionY(y);
  ui->horizontalSlider_position_y->setValue(y);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("positionY", QVariant::fromValue(y));
}

void MainWindow::on_doubleSpinBox_position_z_valueChanged(double z) {
  ui->openGLWidget->setPositionZ(z);
  ui->horizontalSlider_position_z->setValue(z);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("positionZ", QVariant::fromValue(z));
}

void MainWindow::on_horizontalSlider_position_x_sliderMoved(int x) {
  ui->openGLWidget->setPositionX(x);
  ui->doubleSpinBox_position_x->setValue(x);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("positionX", QVariant::fromValue(x));
}

void MainWindow::on_horizontalSlider_position_y_sliderMoved(int y) {
  ui->openGLWidget->setPositionY(y);
  ui->doubleSpinBox_position_y->setValue(y);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("positionY", QVariant::fromValue(y));
}

void MainWindow::on_horizontalSlider_position_z_sliderMoved(int z) {
  ui->openGLWidget->setPositionZ(z);
  ui->doubleSpinBox_position_z->setValue(z);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("positionZ", QVariant::fromValue(z));
}

/** Методы изменения масштаба модели**/

void MainWindow::on_doubleSpinBox_scale_valueChanged(double scale) {
  ui->openGLWidget->setScale(scale);
  ui->horizontalSlider_scale->setValue(scale);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("scale", QVariant::fromValue(scale));
}

void MainWindow::on_horizontalSlider_scale_sliderMoved(int scale) {
  ui->openGLWidget->setScale(scale);
  ui->doubleSpinBox_scale->setValue(scale);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("scale", QVariant::fromValue(scale));
}

/** Методы изменения проекции*/

void MainWindow::on_radioButton_central_toggled(bool checked) {
  ui->openGLWidget->setProjection(checked);
  //    ui->openGLWidget->resize(ui->openGLWidget->width(),
  //    ui->openGLWidget->height()); ui->openGLWidget->resized();
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("isCentral", QVariant::fromValue(true));
}

void MainWindow::on_radioButton_parallel_toggled(bool checked) {
  ui->openGLWidget->setProjection(!checked);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("isCentral", QVariant::fromValue(false));
}

void MainWindow::on_doubleSpinBox_edgeThickness_valueChanged(double arg1) {
  ui->openGLWidget->setEdgeThickness(arg1);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("edgeThickness", QVariant::fromValue(arg1));
}

void MainWindow::on_comboBox_edgeType_currentIndexChanged(int index) {
  ui->openGLWidget->setEdgeType((EdgeType)index);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("edgeType", QVariant::fromValue(index));
}

void MainWindow::on_pushButton_color_clicked() {
  QColor colorEdge = QColorDialog::getColor(Qt::white, this, "Выберите цвет");

  colorEdge = colorEdge.convertTo(QColor::Rgb);

  QString qss = QString("background-color: rgb(%1, %2, %3)")
                    .arg(colorEdge.red())
                    .arg(colorEdge.green())
                    .arg(colorEdge.blue());

  ui->statusbar->showMessage(qss, 10000);
  ui->pushButton_color->setStyleSheet(qss);

  ui->openGLWidget->setEdgeColor(colorEdge);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  QList<int> edgeListColor = {colorEdge.red(), colorEdge.green(),
                              colorEdge.blue()};
  settings.setValue("edgeColor", QVariant::fromValue(edgeListColor));
}

void MainWindow::on_doubleSpinBox_vertexSize_valueChanged(double arg1) {
  ui->openGLWidget->setVertexSize(arg1);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("vertexSize", QVariant::fromValue(arg1));
}

void MainWindow::on_comboBox_vertexType_currentIndexChanged(int index) {
  ui->openGLWidget->setVertexType((VertexType)index);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  settings.setValue("vertexType", QVariant::fromValue(index));
}

void MainWindow::on_pushButton_vertexColor_clicked() {
  QColor colorVertex = QColorDialog::getColor(Qt::white, this, "Выберите цвет");

  colorVertex = colorVertex.convertTo(QColor::Rgb);

  QString qss = QString("background-color: rgb(%1, %2, %3)")
                    .arg(colorVertex.red())
                    .arg(colorVertex.green())
                    .arg(colorVertex.blue());

  ui->statusbar->showMessage(qss, 10000);
  ui->pushButton_vertexColor->setStyleSheet(qss);

  ui->openGLWidget->setVertexColor(colorVertex);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  QList<int> vertexListColor = {colorVertex.red(), colorVertex.green(),
                                colorVertex.blue()};
  settings.setValue("vertexColor", QVariant::fromValue(vertexListColor));
}

void MainWindow::on_pushButton_backColor_clicked() {
  QColor colorBack = QColorDialog::getColor(Qt::white, this, "Выберите цвет");

  colorBack = colorBack.convertTo(QColor::Rgb);

  QString qss = QString("background-color: rgb(%1, %2, %3)")
                    .arg(colorBack.red())
                    .arg(colorBack.green())
                    .arg(colorBack.blue());

  ui->statusbar->showMessage(qss, 10000);
  ui->pushButton_backColor->setStyleSheet(qss);

  ui->openGLWidget->setBackColor(colorBack);
  ui->openGLWidget->update();

  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Settings");

  QList<int> backListColor = {colorBack.red(), colorBack.green(),
                              colorBack.blue()};
  settings.setValue("backColor", QVariant::fromValue(backListColor));
}
