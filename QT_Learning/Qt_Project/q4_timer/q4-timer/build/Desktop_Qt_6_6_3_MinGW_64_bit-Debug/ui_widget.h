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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *startButton;
    QPushButton *pushBu;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(492, 289);
        startButton = new QPushButton(Widget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(90, 210, 75, 24));
        pushBu = new QPushButton(Widget);
        pushBu->setObjectName("pushBu");
        pushBu->setGeometry(QRect(320, 210, 75, 24));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 30, 291, 161));
        label->setScaledContents(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        startButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        pushBu->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
