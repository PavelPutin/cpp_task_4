//
// Created by RobotComp.ru on 05.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <iostream>
#include <QFileDialog>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SynonymTableToStandardItemModelConverter.h"

namespace Ui {
    MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent), Ui_MainWindow() {
        setupUi(this);

        setupSynonymsTableTreeView();
    }

    void MainWindow::loadWordsList() {
        // todo: make only .txt file extension
        std::unique_ptr<QFileDialog> fileDialog = std::make_unique<QFileDialog>();
        QString fileName = fileDialog->getOpenFileName();
        if (not fileName.isNull()) {
            inputWordsListFilePathLabel->setText(fileName);

            WordsListFileReader fileReader(fileName.toStdString());
            try {
                inputWords = fileReader.read();
                emit inputWordsChanged();

                outputWords = nullptr;
                emit outputWordsChanged();
            } catch (std::invalid_argument &error) {
                emit errorOccured();
            }
        }
    }

    void MainWindow::updateInputWordsListView() {
        QStringList inputWordsList;
        std::for_each(inputWords->begin(), inputWords->end(), [&inputWordsList](std::string &word) {
            inputWordsList << QString(word.c_str());
        });
        inputWordsListModel->setStringList(inputWordsList);
        inputWordsListView->setModel(inputWordsListModel);
    }

    void MainWindow::loadSynonymsTable() {
        std::unique_ptr<QFileDialog> fileDialog = std::make_unique<QFileDialog>();
        QString fileName = fileDialog->getOpenFileName();
        if (not fileName.isNull()) {
            SynonymTableFileReader fileReader(fileName.toStdString());

            try {
                synonyms = fileReader.read();

                SynonymTableToStandardItemModelConverter converter(synonymsTableModel, synonyms);
                converter.convert();
                emit synonymsTableChanged();

                outputWords = nullptr;
                emit outputWordsChanged();
//                emit synonymizePushButton->enable
            } catch (std::invalid_argument &error) {
                emit errorOccured();
            }
        }
    }

    void MainWindow::saveWordsList() {
        std::unique_ptr<QFileDialog> fileDialog = std::make_unique<QFileDialog>();
        QString fileName = fileDialog->getSaveFileName();
        if (not fileName.isNull()) {
            WordsListFileWriter fileWriter(fileName.toStdString(), outputWords);
            try {
                fileWriter.write();
            } catch (std::invalid_argument &error) {
                emit errorOccured();
            }
        }
    }

    void MainWindow::synonymize() {
        if (inputWords == nullptr) {
            emit loadWordsList();
        }
        if (synonyms == nullptr) {
            emit loadSynonymsTable();
        }
        outputWords = inputWords->getSynonimizedList(synonyms);
        emit outputWordsChanged();
    }

    void MainWindow::updateOutputWordsListView() {
        QStringList inputWordsList;
        if (outputWords != nullptr) {
            std::for_each(outputWords->begin(), outputWords->end(), [&inputWordsList](std::string &word) {
                inputWordsList << QString(word.c_str());
            });
        }
        outputWordsListModel->setStringList(inputWordsList);
        outputWordsListView->setModel(outputWordsListModel);
    }

    void MainWindow::updateSynonymsTableTreeView() {
        synonymsTableTreeView->setModel(synonymsTableModel);
    }

    void MainWindow::showErrorDialog() {
        std::unique_ptr<QMessageBox> errorMessage = std::make_unique<QMessageBox>();
        errorMessage->critical(this, "Ошибка", "Произошла ошибка");
    }

    void MainWindow::setupSynonymsTableTreeView() {
        synonymsTableModel->setHorizontalHeaderLabels(QStringList{QString("Слово")});

        QStandardItem *parentItem = synonymsTableModel->invisibleRootItem();
        QStandardItem *item = new QStandardItem(QString("Пусто"));
        item->setEditable(false);
        parentItem->appendRow(item);
        synonymsTableTreeView->setModel(synonymsTableModel);
//        for (int i = 0; i < 4; i++) {
//            QStandardItem *item = new QStandardItem(QString("hello %0").arg(i));
//            parentItem->appendRow(item);
//            parentItem = item;
//        }
//
//        synonymsTableTreeView->setModel(synonymsTableModel);
    }
}
