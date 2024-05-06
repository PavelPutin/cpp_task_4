/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *loadWordsListAction;
    QAction *loadSynonymsTableAction;
    QAction *saveWordsListAction;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *wordsListsTab;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *inputWordsListFilePathLabel;
    QListView *inputWordsListView;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *synonymizePushButton;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *outputWordsListFilePathLabel;
    QListView *outputWordsListView;
    QWidget *synonymsTableTab;
    QVBoxLayout *verticalLayout_4;
    QTreeView *synonymsTableTreeView;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(809, 532);
        loadWordsListAction = new QAction(MainWindow);
        loadWordsListAction->setObjectName(QString::fromUtf8("loadWordsListAction"));
        loadSynonymsTableAction = new QAction(MainWindow);
        loadSynonymsTableAction->setObjectName(QString::fromUtf8("loadSynonymsTableAction"));
        saveWordsListAction = new QAction(MainWindow);
        saveWordsListAction->setObjectName(QString::fromUtf8("saveWordsListAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        wordsListsTab = new QWidget();
        wordsListsTab->setObjectName(QString::fromUtf8("wordsListsTab"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(wordsListsTab->sizePolicy().hasHeightForWidth());
        wordsListsTab->setSizePolicy(sizePolicy1);
        horizontalLayout_3 = new QHBoxLayout(wordsListsTab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget = new QWidget(wordsListsTab);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        inputWordsListFilePathLabel = new QLabel(widget);
        inputWordsListFilePathLabel->setObjectName(QString::fromUtf8("inputWordsListFilePathLabel"));

        verticalLayout->addWidget(inputWordsListFilePathLabel);

        inputWordsListView = new QListView(widget);
        inputWordsListView->setObjectName(QString::fromUtf8("inputWordsListView"));

        verticalLayout->addWidget(inputWordsListView);


        horizontalLayout_3->addWidget(widget);

        widget_3 = new QWidget(wordsListsTab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        synonymizePushButton = new QPushButton(widget_3);
        synonymizePushButton->setObjectName(QString::fromUtf8("synonymizePushButton"));
        synonymizePushButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(synonymizePushButton);


        horizontalLayout_3->addWidget(widget_3);

        widget_2 = new QWidget(wordsListsTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        outputWordsListFilePathLabel = new QLabel(widget_2);
        outputWordsListFilePathLabel->setObjectName(QString::fromUtf8("outputWordsListFilePathLabel"));

        verticalLayout_2->addWidget(outputWordsListFilePathLabel);

        outputWordsListView = new QListView(widget_2);
        outputWordsListView->setObjectName(QString::fromUtf8("outputWordsListView"));

        verticalLayout_2->addWidget(outputWordsListView);


        horizontalLayout_3->addWidget(widget_2);

        tabWidget->addTab(wordsListsTab, QString());
        synonymsTableTab = new QWidget();
        synonymsTableTab->setObjectName(QString::fromUtf8("synonymsTableTab"));
        verticalLayout_4 = new QVBoxLayout(synonymsTableTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        synonymsTableTreeView = new QTreeView(synonymsTableTab);
        synonymsTableTreeView->setObjectName(QString::fromUtf8("synonymsTableTreeView"));

        verticalLayout_4->addWidget(synonymsTableTreeView);

        tabWidget->addTab(synonymsTableTab, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 809, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(tabWidget, inputWordsListView);
        QWidget::setTabOrder(inputWordsListView, outputWordsListView);
        QWidget::setTabOrder(outputWordsListView, synonymizePushButton);
        QWidget::setTabOrder(synonymizePushButton, synonymsTableTreeView);

        menubar->addAction(menu->menuAction());
        menu->addAction(loadWordsListAction);
        menu->addAction(loadSynonymsTableAction);
        menu->addAction(saveWordsListAction);

        retranslateUi(MainWindow);
        QObject::connect(loadWordsListAction, SIGNAL(triggered()), MainWindow, SLOT(loadWordsList()));
        QObject::connect(loadSynonymsTableAction, SIGNAL(triggered()), MainWindow, SLOT(loadSynonymsTable()));
        QObject::connect(saveWordsListAction, SIGNAL(triggered()), MainWindow, SLOT(saveWordsList()));
        QObject::connect(synonymizePushButton, SIGNAL(clicked()), MainWindow, SLOT(synonymize()));
        QObject::connect(MainWindow, SIGNAL(inputWordsChanged()), MainWindow, SLOT(updateInputWordsListView()));
        QObject::connect(MainWindow, SIGNAL(outputWordsChanged()), MainWindow, SLOT(updateOutputWordsListView()));
        QObject::connect(MainWindow, SIGNAL(synonymsTableChanged()), MainWindow, SLOT(updateSynonymsTableTreeView()));
        QObject::connect(MainWindow, SIGNAL(errorOccured()), MainWindow, SLOT(showErrorDialog()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadWordsListAction->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\260", nullptr));
#if QT_CONFIG(tooltip)
        loadWordsListAction->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\260 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        loadWordsListAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        loadSynonymsTableAction->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \321\201\320\270\320\275\320\276\320\275\320\270\320\274\320\276\320\262", nullptr));
#if QT_CONFIG(tooltip)
        loadSynonymsTableAction->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \321\201\320\270\320\275\320\276\320\275\320\270\320\274\320\276\320\262 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        loadSynonymsTableAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        saveWordsListAction->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\260", nullptr));
#if QT_CONFIG(tooltip)
        saveWordsListAction->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\260 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        saveWordsListAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        inputWordsListFilePathLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        synonymizePushButton->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        outputWordsListFilePathLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(wordsListsTab), QCoreApplication::translate("MainWindow", "\320\241\320\273\320\276\320\262\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(synonymsTableTab), QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\201\320\270\320\275\320\276\320\275\320\270\320\274\320\276\320\262", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

#endif // MAINWINDOW_H
