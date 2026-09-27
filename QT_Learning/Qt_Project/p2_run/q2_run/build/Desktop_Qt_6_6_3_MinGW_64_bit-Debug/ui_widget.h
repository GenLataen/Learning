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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *cmdLineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *commitButton;
    QPushButton *cancelButton;
    QPushButton *browseButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(295, 159);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 10, 81, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Source Code Pro")});
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 54, 16));
        cmdLineEdit = new QLineEdit(Widget);
        cmdLineEdit->setObjectName("cmdLineEdit");
        cmdLineEdit->setGeometry(QRect(120, 50, 113, 31));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 110, 245, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        commitButton = new QPushButton(widget);
        commitButton->setObjectName("commitButton");

        horizontalLayout->addWidget(commitButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);

        browseButton = new QPushButton(widget);
        browseButton->setObjectName("browseButton");

        horizontalLayout->addWidget(browseButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">\350\257\267\350\276\223\345\205\245\345\221\275\344\273\244</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\357\274\232", nullptr));
        commitButton->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        browseButton->setText(QCoreApplication::translate("Widget", "\346\265\217\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
