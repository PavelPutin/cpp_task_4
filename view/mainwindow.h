//
// Created by RobotComp.ru on 05.05.2024.
//

#ifndef CPP_TASK4_MAINWINDOW_H
#define CPP_TASK4_MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
namespace Ui {
    class MainWindow : public QMainWindow, public Ui_MainWindow  {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
    };
}


#endif //CPP_TASK4_MAINWINDOW_H
