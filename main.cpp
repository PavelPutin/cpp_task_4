#include "view/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto* MainWindow = new Ui::MainWindow();

    return QApplication::exec();
}
