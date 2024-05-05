#include "view/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto* mainWindow = new Ui::MainWindow();
    mainWindow->show();
    return QApplication::exec();
}
