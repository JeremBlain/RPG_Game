/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *layoutGame;
    QMenuBar *menuBar;
    QMenu *menuBouton;
    QMenu *menuBouton2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1302, 819);
        MainWindow->setMinimumSize(QSize(1260, 819));
        MainWindow->setMaximumSize(QSize(1302, 819));
        MainWindow->setCursor(QCursor(Qt::CrossCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        layoutGame = new QVBoxLayout();
        layoutGame->setSpacing(6);
        layoutGame->setObjectName(QStringLiteral("layoutGame"));

        verticalLayout->addLayout(layoutGame);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1302, 21));
        menuBouton = new QMenu(menuBar);
        menuBouton->setObjectName(QStringLiteral("menuBouton"));
        menuBouton2 = new QMenu(menuBar);
        menuBouton2->setObjectName(QStringLiteral("menuBouton2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuBouton->menuAction());
        menuBar->addAction(menuBouton2->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Game", 0));
        menuBouton->setTitle(QApplication::translate("MainWindow", "Bouton", 0));
        menuBouton2->setTitle(QApplication::translate("MainWindow", "Bouton2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
