/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_speed;
    QSlider *horizontalSlider_speed;
    QPushButton *pushButton_direction;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_angle;
    QSlider *horizontalSlider_angle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_duration;
    QSpinBox *spinBox_duration;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_turns;
    QSlider *horizontalSlider_turns;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QMenuBar *menubar;
    QMenu *menuMotor_Kontrol;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(467, 393);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_speed = new QLabel(centralwidget);
        label_speed->setObjectName("label_speed");

        horizontalLayout->addWidget(label_speed);

        horizontalSlider_speed = new QSlider(centralwidget);
        horizontalSlider_speed->setObjectName("horizontalSlider_speed");
        horizontalSlider_speed->setMaximum(100);
        horizontalSlider_speed->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_speed);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_direction = new QPushButton(centralwidget);
        pushButton_direction->setObjectName("pushButton_direction");

        verticalLayout->addWidget(pushButton_direction);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_angle = new QLabel(centralwidget);
        label_angle->setObjectName("label_angle");

        horizontalLayout_2->addWidget(label_angle);

        horizontalSlider_angle = new QSlider(centralwidget);
        horizontalSlider_angle->setObjectName("horizontalSlider_angle");
        horizontalSlider_angle->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_angle);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_duration = new QLabel(centralwidget);
        label_duration->setObjectName("label_duration");

        horizontalLayout_3->addWidget(label_duration);

        spinBox_duration = new QSpinBox(centralwidget);
        spinBox_duration->setObjectName("spinBox_duration");

        horizontalLayout_3->addWidget(spinBox_duration);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_turns = new QLabel(centralwidget);
        label_turns->setObjectName("label_turns");

        horizontalLayout_4->addWidget(label_turns);

        horizontalSlider_turns = new QSlider(centralwidget);
        horizontalSlider_turns->setObjectName("horizontalSlider_turns");
        horizontalSlider_turns->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_turns);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName("pushButton_start");

        horizontalLayout_5->addWidget(pushButton_start);

        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName("pushButton_stop");

        horizontalLayout_5->addWidget(pushButton_stop);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 467, 25));
        menuMotor_Kontrol = new QMenu(menubar);
        menuMotor_Kontrol->setObjectName("menuMotor_Kontrol");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMotor_Kontrol->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(pushButton_start, &QPushButton::clicked, pushButton_start, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_speed->setText(QCoreApplication::translate("MainWindow", "H\304\261z : ", nullptr));
        pushButton_direction->setText(QCoreApplication::translate("MainWindow", "Y\303\266n", nullptr));
        label_angle->setText(QCoreApplication::translate("MainWindow", "A\303\247\304\261 :", nullptr));
        label_duration->setText(QCoreApplication::translate("MainWindow", "S\303\274re :", nullptr));
        label_turns->setText(QCoreApplication::translate("MainWindow", "Tur : ", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Ba\305\237lat", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Durdur", nullptr));
        menuMotor_Kontrol->setTitle(QCoreApplication::translate("MainWindow", "Motor Kontrol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
