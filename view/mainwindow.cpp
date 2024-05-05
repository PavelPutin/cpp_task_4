//
// Created by RobotComp.ru on 05.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
    MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent), Ui_MainWindow() {
        setupUi(this);
    }
}
