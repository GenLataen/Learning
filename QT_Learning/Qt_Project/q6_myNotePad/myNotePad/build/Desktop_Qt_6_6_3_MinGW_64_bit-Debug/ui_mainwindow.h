/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_B;
    QMenu *menu_B_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(463, 440);
        newAction = new QAction(MainWindow);
        newAction->setObjectName("newAction");
        openAction = new QAction(MainWindow);
        openAction->setObjectName("openAction");
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName("saveAction");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 463, 22));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName("menu_F");
        menu_B = new QMenu(menubar);
        menu_B->setObjectName("menu_B");
        menu_B_2 = new QMenu(menubar);
        menu_B_2->setObjectName("menu_B_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_B->menuAction());
        menubar->addAction(menu_B_2->menuAction());
        menu_F->addAction(newAction);
        menu_F->addAction(openAction);
        menu_F->addAction(saveAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newAction->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\357\274\210&N\357\274\211", nullptr));
        openAction->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\357\274\210&O\357\274\211", nullptr));
        saveAction->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272\357\274\210&S\357\274\211", nullptr));
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\357\274\210&F\357\274\211", nullptr));
        menu_B->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\257\221\357\274\210&B\357\274\211", nullptr));
        menu_B_2->setTitle(QCoreApplication::translate("MainWindow", "\346\236\204\345\273\272\357\274\210&B\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
