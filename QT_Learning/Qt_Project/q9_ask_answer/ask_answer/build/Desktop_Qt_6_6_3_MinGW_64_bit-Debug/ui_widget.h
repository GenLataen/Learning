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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *submitButton;
    QLineEdit *inputLineEdit;
    QLabel *label_2;
    QTextEdit *outputTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(428, 299);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 211, 16));
        submitButton = new QPushButton(Widget);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(290, 50, 75, 23));
        inputLineEdit = new QLineEdit(Widget);
        inputLineEdit->setObjectName("inputLineEdit");
        inputLineEdit->setGeometry(QRect(60, 50, 181, 21));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 160, 53, 15));
        outputTextEdit = new QTextEdit(Widget);
        outputTextEdit->setObjectName("outputTextEdit");
        outputTextEdit->setGeometry(QRect(80, 130, 171, 81));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\265\267\344\270\212\350\210\271\350\210\266\346\231\272\350\203\275\350\257\255\351\237\263\350\276\205\345\212\251\347\263\273\347\273\237", nullptr));
        submitButton->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\200\344\275\263\347\255\224\346\241\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
