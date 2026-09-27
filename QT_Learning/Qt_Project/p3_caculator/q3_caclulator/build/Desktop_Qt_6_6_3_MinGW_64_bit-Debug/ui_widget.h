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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *mainLineEdit;
    QPushButton *clearButton;
    QPushButton *addButton;
    QPushButton *subButton;
    QPushButton *delButton;
    QPushButton *sevenButtton;
    QPushButton *eightButton;
    QPushButton *nineButton;
    QPushButton *mulButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *sixButton;
    QPushButton *divButton;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *equalButton;
    QPushButton *leftButton;
    QPushButton *zeroButton;
    QPushButton *rightButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(214, 292);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 10, 180, 272));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mainLineEdit = new QLineEdit(widget);
        mainLineEdit->setObjectName("mainLineEdit");
        mainLineEdit->setMinimumSize(QSize(0, 40));
        mainLineEdit->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(mainLineEdit, 0, 0, 1, 4);

        clearButton = new QPushButton(widget);
        clearButton->setObjectName("clearButton");
        clearButton->setMinimumSize(QSize(40, 40));
        clearButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(clearButton, 1, 0, 1, 1);

        addButton = new QPushButton(widget);
        addButton->setObjectName("addButton");
        addButton->setMinimumSize(QSize(40, 40));
        addButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(addButton, 1, 1, 1, 1);

        subButton = new QPushButton(widget);
        subButton->setObjectName("subButton");
        subButton->setMinimumSize(QSize(40, 40));
        subButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(subButton, 1, 2, 1, 1);

        delButton = new QPushButton(widget);
        delButton->setObjectName("delButton");
        delButton->setMinimumSize(QSize(40, 40));
        delButton->setMaximumSize(QSize(40, 40));
        delButton->setIconSize(QSize(30, 30));

        gridLayout->addWidget(delButton, 1, 3, 1, 1);

        sevenButtton = new QPushButton(widget);
        sevenButtton->setObjectName("sevenButtton");
        sevenButtton->setMinimumSize(QSize(40, 40));
        sevenButtton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(sevenButtton, 2, 0, 1, 1);

        eightButton = new QPushButton(widget);
        eightButton->setObjectName("eightButton");
        eightButton->setMinimumSize(QSize(40, 40));
        eightButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(eightButton, 2, 1, 1, 1);

        nineButton = new QPushButton(widget);
        nineButton->setObjectName("nineButton");
        nineButton->setMinimumSize(QSize(40, 40));
        nineButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(nineButton, 2, 2, 1, 1);

        mulButton = new QPushButton(widget);
        mulButton->setObjectName("mulButton");
        mulButton->setMinimumSize(QSize(40, 40));
        mulButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(mulButton, 2, 3, 1, 1);

        fourButton = new QPushButton(widget);
        fourButton->setObjectName("fourButton");
        fourButton->setMinimumSize(QSize(40, 40));
        fourButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(fourButton, 3, 0, 1, 1);

        fiveButton = new QPushButton(widget);
        fiveButton->setObjectName("fiveButton");
        fiveButton->setMinimumSize(QSize(40, 40));
        fiveButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(fiveButton, 3, 1, 1, 1);

        sixButton = new QPushButton(widget);
        sixButton->setObjectName("sixButton");
        sixButton->setMinimumSize(QSize(40, 40));
        sixButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(sixButton, 3, 2, 1, 1);

        divButton = new QPushButton(widget);
        divButton->setObjectName("divButton");
        divButton->setMinimumSize(QSize(40, 40));
        divButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(divButton, 3, 3, 1, 1);

        oneButton = new QPushButton(widget);
        oneButton->setObjectName("oneButton");
        oneButton->setMinimumSize(QSize(40, 40));
        oneButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(oneButton, 4, 0, 1, 1);

        twoButton = new QPushButton(widget);
        twoButton->setObjectName("twoButton");
        twoButton->setMinimumSize(QSize(40, 40));
        twoButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(twoButton, 4, 1, 1, 1);

        threeButton = new QPushButton(widget);
        threeButton->setObjectName("threeButton");
        threeButton->setMinimumSize(QSize(40, 40));
        threeButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(threeButton, 4, 2, 1, 1);

        equalButton = new QPushButton(widget);
        equalButton->setObjectName("equalButton");
        equalButton->setMinimumSize(QSize(40, 40));
        equalButton->setMaximumSize(QSize(40, 100));

        gridLayout->addWidget(equalButton, 4, 3, 2, 1);

        leftButton = new QPushButton(widget);
        leftButton->setObjectName("leftButton");
        leftButton->setMinimumSize(QSize(40, 40));
        leftButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(leftButton, 5, 0, 1, 1);

        zeroButton = new QPushButton(widget);
        zeroButton->setObjectName("zeroButton");
        zeroButton->setMinimumSize(QSize(40, 40));
        zeroButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(zeroButton, 5, 1, 1, 1);

        rightButton = new QPushButton(widget);
        rightButton->setObjectName("rightButton");
        rightButton->setMinimumSize(QSize(40, 40));
        rightButton->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(rightButton, 5, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        clearButton->setText(QCoreApplication::translate("Widget", "C", nullptr));
        addButton->setText(QCoreApplication::translate("Widget", "+", nullptr));
        subButton->setText(QCoreApplication::translate("Widget", "-", nullptr));
        delButton->setText(QString());
        sevenButtton->setText(QCoreApplication::translate("Widget", "7", nullptr));
        eightButton->setText(QCoreApplication::translate("Widget", "8", nullptr));
        nineButton->setText(QCoreApplication::translate("Widget", "9", nullptr));
        mulButton->setText(QCoreApplication::translate("Widget", "*", nullptr));
        fourButton->setText(QCoreApplication::translate("Widget", "4", nullptr));
        fiveButton->setText(QCoreApplication::translate("Widget", "5", nullptr));
        sixButton->setText(QCoreApplication::translate("Widget", "6", nullptr));
        divButton->setText(QCoreApplication::translate("Widget", "/", nullptr));
        oneButton->setText(QCoreApplication::translate("Widget", "1", nullptr));
        twoButton->setText(QCoreApplication::translate("Widget", "2", nullptr));
        threeButton->setText(QCoreApplication::translate("Widget", "3", nullptr));
        equalButton->setText(QCoreApplication::translate("Widget", "=", nullptr));
        leftButton->setText(QCoreApplication::translate("Widget", "(", nullptr));
        zeroButton->setText(QCoreApplication::translate("Widget", "0", nullptr));
        rightButton->setText(QCoreApplication::translate("Widget", ")", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
