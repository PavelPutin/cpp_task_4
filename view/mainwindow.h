//
// Created by RobotComp.ru on 05.05.2024.
//

#ifndef CPP_TASK4_MAINWINDOW_H
#define CPP_TASK4_MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include "ui_mainwindow.h"
#include "WordsListFileReader.h"
#include "WordsListFileWriter.h"
#include "SynonymTableFileReader.h"

namespace Ui {
    class MainWindow : public QMainWindow, public Ui_MainWindow  {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
    private:
        QStringListModel *inputWordsListModel = new QStringListModel(inputWordsListView);
        WordsList *inputWords = nullptr;
        QStringListModel *outputWordsListModel = new QStringListModel(outputWordsListView);
        WordsList *outputWords = nullptr;
        QStandardItemModel *synonymsTableModel = new QStandardItemModel();
        SynonymTable *synonyms = nullptr;

        void setupSynonymsTableTreeView();
    signals:
        void inputWordsChanged();
        void outputWordsChanged();
        void synonymsTableChanged();
    private slots:
        void loadWordsList();
        void loadSynonymsTable();
        void saveWordsList();
        void synonymize();
        void updateInputWordsListView();
        void updateOutputWordsListView();
        void updateSynonymsTableTreeView();
    };
}


#endif //CPP_TASK4_MAINWINDOW_H
