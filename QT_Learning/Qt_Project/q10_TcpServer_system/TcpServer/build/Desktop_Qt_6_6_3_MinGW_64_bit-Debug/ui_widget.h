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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLineEdit *ipLineEdit;
    QLineEdit *portLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *mainLineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(357, 325);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 30, 54, 16));
        ipLineEdit = new QLineEdit(Widget);
        ipLineEdit->setObjectName("ipLineEdit");
        ipLineEdit->setGeometry(QRect(180, 90, 113, 21));
        portLineEdit = new QLineEdit(Widget);
        portLineEdit->setObjectName("portLineEdit");
        portLineEdit->setGeometry(QRect(180, 160, 113, 21));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 90, 71, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 160, 61, 16));
        mainLineEdit = new QLineEdit(Widget);
        mainLineEdit->setObjectName("mainLineEdit");
        mainLineEdit->setGeometry(QRect(100, 210, 151, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\346\234\215\345\212\241\345\231\250</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257\345\234\260\345\235\200", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257\347\253\257\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
