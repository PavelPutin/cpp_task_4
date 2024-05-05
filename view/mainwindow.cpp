//
// Created by RobotComp.ru on 05.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <iostream>
#include <QFileDialog>
#include <QStringListModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
    MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent), Ui_MainWindow() {
        setupUi(this);
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
                std::cout << "Не удалось открыть файл " + fileName.toStdString() << std::endl;
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

                outputWords = nullptr;
                emit outputWordsChanged();
//                emit synonymizePushButton->enable
            } catch (std::invalid_argument &error) {
                std::cout << "Не удалось открыть файл " + fileName.toStdString() << std::endl;
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
                std::cout << "Не удалось открыть файл " + fileName.toStdString() << std::endl;
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
}
