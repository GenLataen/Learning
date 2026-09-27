/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *ipLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *portLineEdit;
    QPushButton *cancelButton;
    QPushButton *connectButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(308, 269);
        ipLineEdit = new QLineEdit(Widget);
        ipLineEdit->setObjectName("ipLineEdit");
        ipLineEdit->setGeometry(QRect(120, 60, 131, 31));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 30, 54, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 71, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 130, 101, 16));
        portLineEdit = new QLineEdit(Widget);
        portLineEdit->setObjectName("portLineEdit");
        portLineEdit->setGeometry(QRect(120, 120, 131, 31));
        cancelButton = new QPushButton(Widget);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(40, 200, 75, 24));
        connectButton = new QPushButton(Widget);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(170, 200, 75, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\345\256\242\346\210\267\347\253\257</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267</span></p></body></html>", nullptr));
        cancelButton->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        connectButton->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
