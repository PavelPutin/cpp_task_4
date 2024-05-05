//
// Created by RobotComp.ru on 05.05.2024.
//

#ifndef CPP_TASK4_MAINWINDOW_H
#define CPP_TASK4_MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //CPP_TASK4_MAINWINDOW_H
