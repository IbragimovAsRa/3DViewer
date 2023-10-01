/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "GLViewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_selectFile;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    GLViewer *openGLWidget;
    QWidget *widget;
    QGroupBox *groupBox_rotate;
    QSlider *horizontalSlider_rotate_x;
    QLabel *qlabel_rotate_x;
    QSlider *horizontalSlider_rotate_y;
    QLabel *qlabel_rotate_y;
    QSlider *horizontalSlider_rotate_z;
    QLabel *qlabel_rotate_z;
    QDoubleSpinBox *doubleSpinBox_rotate_x;
    QDoubleSpinBox *doubleSpinBox_rotate_y;
    QDoubleSpinBox *doubleSpinBox_rotate_z;
    QGroupBox *groupBox_position;
    QSlider *horizontalSlider_position_z;
    QSlider *horizontalSlider_position_x;
    QDoubleSpinBox *doubleSpinBox_position_y;
    QLabel *qlabel_position_z;
    QLabel *qlabel_position_y;
    QDoubleSpinBox *doubleSpinBox_position_z;
    QSlider *horizontalSlider_position_y;
    QLabel *qlabel_position_x;
    QDoubleSpinBox *doubleSpinBox_position_x;
    QGroupBox *groupBox_scale;
    QSlider *horizontalSlider_scale;
    QDoubleSpinBox *doubleSpinBox_scale;
    QGroupBox *groupBox_info;
    QLabel *label_vertex;
    QLabel *label_vertex_count;
    QLabel *label_edge_count;
    QLabel *label_edge;
    QLabel *label_file;
    QLabel *label_filename;
    QGroupBox *groupBox_projection;
    QRadioButton *radioButton_central;
    QRadioButton *radioButton_parallel;
    QGroupBox *groupBox_setting_edge;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_edgeThickness;
    QComboBox *comboBox_edgeType;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_color;
    QGroupBox *groupBox_setting_edge_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_vertexSize;
    QComboBox *comboBox_vertexType;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_vertexColor;
    QGroupBox *groupBox_setting_edge_3;
    QLabel *label_9;
    QPushButton *pushButton_backColor;
    QMenuBar *menubar;
    QMenu *menu_file;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1186, 844);
        action_selectFile = new QAction(MainWindow);
        action_selectFile->setObjectName(QString::fromUtf8("action_selectFile"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openGLWidget = new GLViewer(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(500, 500));

        horizontalLayout->addWidget(openGLWidget);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(580, 770));
        widget->setMaximumSize(QSize(580, 770));
        groupBox_rotate = new QGroupBox(widget);
        groupBox_rotate->setObjectName(QString::fromUtf8("groupBox_rotate"));
        groupBox_rotate->setGeometry(QRect(12, 200, 276, 230));
        groupBox_rotate->setMinimumSize(QSize(0, 230));
        horizontalSlider_rotate_x = new QSlider(groupBox_rotate);
        horizontalSlider_rotate_x->setObjectName(QString::fromUtf8("horizontalSlider_rotate_x"));
        horizontalSlider_rotate_x->setGeometry(QRect(10, 60, 261, 25));
        horizontalSlider_rotate_x->setMinimum(-360);
        horizontalSlider_rotate_x->setMaximum(360);
        horizontalSlider_rotate_x->setSingleStep(1);
        horizontalSlider_rotate_x->setValue(0);
        horizontalSlider_rotate_x->setTracking(false);
        horizontalSlider_rotate_x->setOrientation(Qt::Horizontal);
        horizontalSlider_rotate_x->setTickPosition(QSlider::NoTicks);
        horizontalSlider_rotate_x->setTickInterval(1);
        qlabel_rotate_x = new QLabel(groupBox_rotate);
        qlabel_rotate_x->setObjectName(QString::fromUtf8("qlabel_rotate_x"));
        qlabel_rotate_x->setGeometry(QRect(10, 30, 21, 16));
        horizontalSlider_rotate_y = new QSlider(groupBox_rotate);
        horizontalSlider_rotate_y->setObjectName(QString::fromUtf8("horizontalSlider_rotate_y"));
        horizontalSlider_rotate_y->setGeometry(QRect(10, 130, 261, 25));
        horizontalSlider_rotate_y->setMinimum(-360);
        horizontalSlider_rotate_y->setMaximum(360);
        horizontalSlider_rotate_y->setSingleStep(1);
        horizontalSlider_rotate_y->setValue(0);
        horizontalSlider_rotate_y->setTracking(false);
        horizontalSlider_rotate_y->setOrientation(Qt::Horizontal);
        horizontalSlider_rotate_y->setTickPosition(QSlider::NoTicks);
        horizontalSlider_rotate_y->setTickInterval(1);
        qlabel_rotate_y = new QLabel(groupBox_rotate);
        qlabel_rotate_y->setObjectName(QString::fromUtf8("qlabel_rotate_y"));
        qlabel_rotate_y->setGeometry(QRect(10, 100, 31, 16));
        horizontalSlider_rotate_z = new QSlider(groupBox_rotate);
        horizontalSlider_rotate_z->setObjectName(QString::fromUtf8("horizontalSlider_rotate_z"));
        horizontalSlider_rotate_z->setGeometry(QRect(10, 200, 261, 25));
        horizontalSlider_rotate_z->setMinimum(-360);
        horizontalSlider_rotate_z->setMaximum(360);
        horizontalSlider_rotate_z->setSingleStep(1);
        horizontalSlider_rotate_z->setValue(0);
        horizontalSlider_rotate_z->setTracking(false);
        horizontalSlider_rotate_z->setOrientation(Qt::Horizontal);
        horizontalSlider_rotate_z->setTickPosition(QSlider::NoTicks);
        horizontalSlider_rotate_z->setTickInterval(1);
        qlabel_rotate_z = new QLabel(groupBox_rotate);
        qlabel_rotate_z->setObjectName(QString::fromUtf8("qlabel_rotate_z"));
        qlabel_rotate_z->setGeometry(QRect(10, 170, 21, 16));
        doubleSpinBox_rotate_x = new QDoubleSpinBox(groupBox_rotate);
        doubleSpinBox_rotate_x->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_x"));
        doubleSpinBox_rotate_x->setGeometry(QRect(30, 30, 62, 22));
        doubleSpinBox_rotate_x->setMinimum(-360.000000000000000);
        doubleSpinBox_rotate_x->setMaximum(360.000000000000000);
        doubleSpinBox_rotate_x->setSingleStep(0.500000000000000);
        doubleSpinBox_rotate_y = new QDoubleSpinBox(groupBox_rotate);
        doubleSpinBox_rotate_y->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_y"));
        doubleSpinBox_rotate_y->setGeometry(QRect(30, 100, 62, 22));
        doubleSpinBox_rotate_y->setMinimum(-360.000000000000000);
        doubleSpinBox_rotate_y->setMaximum(360.000000000000000);
        doubleSpinBox_rotate_y->setSingleStep(0.500000000000000);
        doubleSpinBox_rotate_z = new QDoubleSpinBox(groupBox_rotate);
        doubleSpinBox_rotate_z->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_z"));
        doubleSpinBox_rotate_z->setGeometry(QRect(30, 170, 62, 22));
        doubleSpinBox_rotate_z->setMinimum(-360.000000000000000);
        doubleSpinBox_rotate_z->setMaximum(360.000000000000000);
        doubleSpinBox_rotate_z->setSingleStep(0.500000000000000);
        groupBox_position = new QGroupBox(widget);
        groupBox_position->setObjectName(QString::fromUtf8("groupBox_position"));
        groupBox_position->setGeometry(QRect(12, 430, 276, 230));
        groupBox_position->setMinimumSize(QSize(0, 230));
        horizontalSlider_position_z = new QSlider(groupBox_position);
        horizontalSlider_position_z->setObjectName(QString::fromUtf8("horizontalSlider_position_z"));
        horizontalSlider_position_z->setGeometry(QRect(10, 200, 261, 25));
        horizontalSlider_position_z->setMinimum(-100);
        horizontalSlider_position_z->setMaximum(100);
        horizontalSlider_position_z->setSingleStep(1);
        horizontalSlider_position_z->setValue(-10);
        horizontalSlider_position_z->setTracking(false);
        horizontalSlider_position_z->setOrientation(Qt::Horizontal);
        horizontalSlider_position_z->setTickPosition(QSlider::NoTicks);
        horizontalSlider_position_z->setTickInterval(1);
        horizontalSlider_position_x = new QSlider(groupBox_position);
        horizontalSlider_position_x->setObjectName(QString::fromUtf8("horizontalSlider_position_x"));
        horizontalSlider_position_x->setGeometry(QRect(10, 60, 261, 25));
        horizontalSlider_position_x->setMinimum(-100);
        horizontalSlider_position_x->setMaximum(100);
        horizontalSlider_position_x->setSingleStep(1);
        horizontalSlider_position_x->setValue(0);
        horizontalSlider_position_x->setTracking(false);
        horizontalSlider_position_x->setOrientation(Qt::Horizontal);
        horizontalSlider_position_x->setTickPosition(QSlider::NoTicks);
        horizontalSlider_position_x->setTickInterval(1);
        doubleSpinBox_position_y = new QDoubleSpinBox(groupBox_position);
        doubleSpinBox_position_y->setObjectName(QString::fromUtf8("doubleSpinBox_position_y"));
        doubleSpinBox_position_y->setGeometry(QRect(30, 100, 62, 22));
        doubleSpinBox_position_y->setMinimum(-100.000000000000000);
        doubleSpinBox_position_y->setMaximum(100.000000000000000);
        doubleSpinBox_position_y->setSingleStep(0.500000000000000);
        qlabel_position_z = new QLabel(groupBox_position);
        qlabel_position_z->setObjectName(QString::fromUtf8("qlabel_position_z"));
        qlabel_position_z->setGeometry(QRect(10, 170, 21, 16));
        qlabel_position_y = new QLabel(groupBox_position);
        qlabel_position_y->setObjectName(QString::fromUtf8("qlabel_position_y"));
        qlabel_position_y->setGeometry(QRect(10, 100, 31, 16));
        doubleSpinBox_position_z = new QDoubleSpinBox(groupBox_position);
        doubleSpinBox_position_z->setObjectName(QString::fromUtf8("doubleSpinBox_position_z"));
        doubleSpinBox_position_z->setGeometry(QRect(30, 170, 62, 22));
        doubleSpinBox_position_z->setMinimum(-100.000000000000000);
        doubleSpinBox_position_z->setMaximum(100.000000000000000);
        doubleSpinBox_position_z->setSingleStep(0.500000000000000);
        doubleSpinBox_position_z->setValue(-10.000000000000000);
        horizontalSlider_position_y = new QSlider(groupBox_position);
        horizontalSlider_position_y->setObjectName(QString::fromUtf8("horizontalSlider_position_y"));
        horizontalSlider_position_y->setGeometry(QRect(10, 130, 261, 25));
        horizontalSlider_position_y->setMinimum(-100);
        horizontalSlider_position_y->setMaximum(100);
        horizontalSlider_position_y->setSingleStep(1);
        horizontalSlider_position_y->setValue(0);
        horizontalSlider_position_y->setTracking(false);
        horizontalSlider_position_y->setOrientation(Qt::Horizontal);
        horizontalSlider_position_y->setTickPosition(QSlider::NoTicks);
        horizontalSlider_position_y->setTickInterval(1);
        qlabel_position_x = new QLabel(groupBox_position);
        qlabel_position_x->setObjectName(QString::fromUtf8("qlabel_position_x"));
        qlabel_position_x->setGeometry(QRect(10, 30, 21, 16));
        doubleSpinBox_position_x = new QDoubleSpinBox(groupBox_position);
        doubleSpinBox_position_x->setObjectName(QString::fromUtf8("doubleSpinBox_position_x"));
        doubleSpinBox_position_x->setGeometry(QRect(30, 30, 62, 22));
        doubleSpinBox_position_x->setMinimum(-100.000000000000000);
        doubleSpinBox_position_x->setMaximum(100.000000000000000);
        doubleSpinBox_position_x->setSingleStep(0.500000000000000);
        groupBox_scale = new QGroupBox(widget);
        groupBox_scale->setObjectName(QString::fromUtf8("groupBox_scale"));
        groupBox_scale->setGeometry(QRect(12, 660, 276, 101));
        horizontalSlider_scale = new QSlider(groupBox_scale);
        horizontalSlider_scale->setObjectName(QString::fromUtf8("horizontalSlider_scale"));
        horizontalSlider_scale->setGeometry(QRect(10, 60, 261, 25));
        horizontalSlider_scale->setMinimum(1);
        horizontalSlider_scale->setMaximum(100);
        horizontalSlider_scale->setSingleStep(1);
        horizontalSlider_scale->setValue(1);
        horizontalSlider_scale->setTracking(false);
        horizontalSlider_scale->setOrientation(Qt::Horizontal);
        horizontalSlider_scale->setTickPosition(QSlider::NoTicks);
        horizontalSlider_scale->setTickInterval(1);
        doubleSpinBox_scale = new QDoubleSpinBox(groupBox_scale);
        doubleSpinBox_scale->setObjectName(QString::fromUtf8("doubleSpinBox_scale"));
        doubleSpinBox_scale->setGeometry(QRect(30, 30, 62, 22));
        doubleSpinBox_scale->setMinimum(1.000000000000000);
        doubleSpinBox_scale->setMaximum(100.000000000000000);
        doubleSpinBox_scale->setSingleStep(0.100000000000000);
        doubleSpinBox_scale->setValue(1.000000000000000);
        groupBox_info = new QGroupBox(widget);
        groupBox_info->setObjectName(QString::fromUtf8("groupBox_info"));
        groupBox_info->setGeometry(QRect(12, 0, 276, 191));
        label_vertex = new QLabel(groupBox_info);
        label_vertex->setObjectName(QString::fromUtf8("label_vertex"));
        label_vertex->setGeometry(QRect(10, 100, 151, 16));
        label_vertex_count = new QLabel(groupBox_info);
        label_vertex_count->setObjectName(QString::fromUtf8("label_vertex_count"));
        label_vertex_count->setGeometry(QRect(10, 120, 251, 16));
        label_edge_count = new QLabel(groupBox_info);
        label_edge_count->setObjectName(QString::fromUtf8("label_edge_count"));
        label_edge_count->setGeometry(QRect(10, 170, 251, 16));
        label_edge = new QLabel(groupBox_info);
        label_edge->setObjectName(QString::fromUtf8("label_edge"));
        label_edge->setGeometry(QRect(10, 150, 151, 16));
        label_file = new QLabel(groupBox_info);
        label_file->setObjectName(QString::fromUtf8("label_file"));
        label_file->setGeometry(QRect(10, 30, 151, 16));
        label_filename = new QLabel(groupBox_info);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));
        label_filename->setGeometry(QRect(10, 50, 251, 41));
        label_filename->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox_projection = new QGroupBox(widget);
        groupBox_projection->setObjectName(QString::fromUtf8("groupBox_projection"));
        groupBox_projection->setGeometry(QRect(300, 0, 276, 111));
        radioButton_central = new QRadioButton(groupBox_projection);
        radioButton_central->setObjectName(QString::fromUtf8("radioButton_central"));
        radioButton_central->setGeometry(QRect(10, 40, 151, 20));
        radioButton_central->setChecked(true);
        radioButton_parallel = new QRadioButton(groupBox_projection);
        radioButton_parallel->setObjectName(QString::fromUtf8("radioButton_parallel"));
        radioButton_parallel->setGeometry(QRect(10, 70, 151, 20));
        groupBox_setting_edge = new QGroupBox(widget);
        groupBox_setting_edge->setObjectName(QString::fromUtf8("groupBox_setting_edge"));
        groupBox_setting_edge->setGeometry(QRect(300, 120, 276, 161));
        label = new QLabel(groupBox_setting_edge);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 71, 16));
        doubleSpinBox_edgeThickness = new QDoubleSpinBox(groupBox_setting_edge);
        doubleSpinBox_edgeThickness->setObjectName(QString::fromUtf8("doubleSpinBox_edgeThickness"));
        doubleSpinBox_edgeThickness->setGeometry(QRect(90, 30, 62, 22));
        doubleSpinBox_edgeThickness->setMinimum(1.000000000000000);
        doubleSpinBox_edgeThickness->setMaximum(25.000000000000000);
        doubleSpinBox_edgeThickness->setSingleStep(0.500000000000000);
        comboBox_edgeType = new QComboBox(groupBox_setting_edge);
        comboBox_edgeType->addItem(QString());
        comboBox_edgeType->addItem(QString());
        comboBox_edgeType->setObjectName(QString::fromUtf8("comboBox_edgeType"));
        comboBox_edgeType->setGeometry(QRect(90, 70, 171, 32));
        label_2 = new QLabel(groupBox_setting_edge);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 71, 16));
        label_3 = new QLabel(groupBox_setting_edge);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 71, 16));
        pushButton_color = new QPushButton(groupBox_setting_edge);
        pushButton_color->setObjectName(QString::fromUtf8("pushButton_color"));
        pushButton_color->setGeometry(QRect(90, 110, 100, 32));
        groupBox_setting_edge_2 = new QGroupBox(widget);
        groupBox_setting_edge_2->setObjectName(QString::fromUtf8("groupBox_setting_edge_2"));
        groupBox_setting_edge_2->setGeometry(QRect(300, 280, 276, 161));
        label_4 = new QLabel(groupBox_setting_edge_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 30, 71, 16));
        doubleSpinBox_vertexSize = new QDoubleSpinBox(groupBox_setting_edge_2);
        doubleSpinBox_vertexSize->setObjectName(QString::fromUtf8("doubleSpinBox_vertexSize"));
        doubleSpinBox_vertexSize->setGeometry(QRect(90, 30, 62, 22));
        doubleSpinBox_vertexSize->setMinimum(1.000000000000000);
        doubleSpinBox_vertexSize->setMaximum(25.000000000000000);
        doubleSpinBox_vertexSize->setSingleStep(0.500000000000000);
        comboBox_vertexType = new QComboBox(groupBox_setting_edge_2);
        comboBox_vertexType->addItem(QString());
        comboBox_vertexType->addItem(QString());
        comboBox_vertexType->addItem(QString());
        comboBox_vertexType->setObjectName(QString::fromUtf8("comboBox_vertexType"));
        comboBox_vertexType->setGeometry(QRect(90, 70, 171, 32));
        label_5 = new QLabel(groupBox_setting_edge_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 80, 71, 16));
        label_6 = new QLabel(groupBox_setting_edge_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 120, 71, 16));
        pushButton_vertexColor = new QPushButton(groupBox_setting_edge_2);
        pushButton_vertexColor->setObjectName(QString::fromUtf8("pushButton_vertexColor"));
        pushButton_vertexColor->setGeometry(QRect(90, 110, 100, 32));
        groupBox_setting_edge_3 = new QGroupBox(widget);
        groupBox_setting_edge_3->setObjectName(QString::fromUtf8("groupBox_setting_edge_3"));
        groupBox_setting_edge_3->setGeometry(QRect(300, 450, 276, 71));
        label_9 = new QLabel(groupBox_setting_edge_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 37, 71, 16));
        pushButton_backColor = new QPushButton(groupBox_setting_edge_3);
        pushButton_backColor->setObjectName(QString::fromUtf8("pushButton_backColor"));
        pushButton_backColor->setGeometry(QRect(90, 30, 100, 32));

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1186, 24));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_file->menuAction());
        menu_file->addAction(action_selectFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        action_selectFile->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        groupBox_rotate->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260 \302\260", nullptr));
        qlabel_rotate_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        qlabel_rotate_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        qlabel_rotate_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        groupBox_position->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        qlabel_position_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        qlabel_position_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        qlabel_position_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        groupBox_scale->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        groupBox_info->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        label_vertex->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        label_vertex_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_edge_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_edge->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\265\320\261\320\265\321\200:", nullptr));
        label_file->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        label_filename->setText(QString());
        groupBox_projection->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217", nullptr));
        radioButton_central->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        radioButton_parallel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        groupBox_setting_edge->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\200\320\265\320\261\320\265\321\200:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", nullptr));
        comboBox_edgeType->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\276\320\271", nullptr));
        comboBox_edgeType->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\321\213\320\271", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        pushButton_color->setText(QString());
        groupBox_setting_edge_2->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \302\240\320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        comboBox_vertexType->setItemText(0, QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        comboBox_vertexType->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        comboBox_vertexType->setItemText(2, QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        pushButton_vertexColor->setText(QString());
        groupBox_setting_edge_3->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \302\240\321\204\320\276\320\275\320\260:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        pushButton_backColor->setText(QString());
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
