#include "view/mainwindow.h"
#include <QApplication>
#include <filesystem>
#include <qfile.h>
#include <QScopedPointer>
#include <QTextStream>
#include <QDateTime>
#include <QLoggingCategory>

QScopedPointer<QFile> logFile;
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
std::filesystem::path getLogFilePath(char *programName);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    logFile.reset(new QFile(getLogFilePath(argv[0]).string().c_str()));
    logFile.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(messageHandler);

    auto* mainWindow = new Ui::MainWindow();
    mainWindow->show();
    qInfo() << "Application started";
    return QApplication::exec();
}

std::filesystem::path getLogFilePath(char *programName) {
    std::filesystem::path program(programName);
    std::filesystem::path logFileParent = program.parent_path().parent_path();
    std::filesystem::path logFilename = program.filename().replace_extension(".log");
    return logFileParent / logFilename;
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QTextStream out(logFile.data());
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    switch (type)
    {
        case QtInfoMsg:     out << "INF "; break;
        case QtDebugMsg:    out << "DBG "; break;
        case QtWarningMsg:  out << "WRN "; break;
        case QtCriticalMsg: out << "CRT "; break;
        case QtFatalMsg:    out << "FTL "; break;
    }
    out << context.category << ": "
        << msg << Qt::endl;
    out.flush();
}
