#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

public slots:
  void SetViewRotateX(float rotateX);
  void SetViewRotateY(float rotateY);
  void SetViewRotateZ(float rotateZ);

private slots:
  void on_action_selectFile_triggered();

  void on_doubleSpinBox_rotate_x_valueChanged(double x);
  void on_doubleSpinBox_rotate_y_valueChanged(double y);
  void on_doubleSpinBox_rotate_z_valueChanged(double z);

  void on_horizontalSlider_rotate_x_sliderMoved(int x);
  void on_horizontalSlider_rotate_y_sliderMoved(int y);
  void on_horizontalSlider_rotate_z_sliderMoved(int z);

  void on_doubleSpinBox_position_x_valueChanged(double x);
  void on_doubleSpinBox_position_y_valueChanged(double y);
  void on_doubleSpinBox_position_z_valueChanged(double z);

  void on_horizontalSlider_position_x_sliderMoved(int x);
  void on_horizontalSlider_position_y_sliderMoved(int y);
  void on_horizontalSlider_position_z_sliderMoved(int z);

  void on_doubleSpinBox_scale_valueChanged(double scale);

  void on_horizontalSlider_scale_sliderMoved(int scale);

  void on_radioButton_central_toggled(bool checked);

  void on_radioButton_parallel_toggled(bool checked);

  void on_doubleSpinBox_edgeThickness_valueChanged(double arg1);

  void on_comboBox_edgeType_currentIndexChanged(int index);

  void on_pushButton_color_clicked();

  void on_doubleSpinBox_vertexSize_valueChanged(double arg1);

  void on_comboBox_vertexType_currentIndexChanged(int index);

  void on_pushButton_vertexColor_clicked();

  void on_pushButton_backColor_clicked();

private:
  Ui::MainWindow *ui;

  bool lock_doubleSpinBox_rotate_x;
  bool lock_doubleSpinBox_rotate_y;
  bool lock_doubleSpinBox_rotate_z;

  bool lock_horizontalSlider_rotate_x;
  bool lock_horizontalSlider_rotate_y;
  bool lock_horizontalSlider_rotate_z;
};

#endif // MAINWINDOW_H
