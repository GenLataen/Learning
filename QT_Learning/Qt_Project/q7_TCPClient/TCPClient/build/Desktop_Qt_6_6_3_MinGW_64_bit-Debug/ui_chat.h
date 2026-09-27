/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *clearButton;
    QPushButton *sendButton;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName("Chat");
        Chat->resize(400, 300);
        label = new QLabel(Chat);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 60, 71, 16));
        lineEdit = new QLineEdit(Chat);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 90, 211, 41));
        clearButton = new QPushButton(Chat);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(80, 170, 75, 24));
        sendButton = new QPushButton(Chat);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(220, 170, 75, 24));

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QCoreApplication::translate("Chat", "Form", nullptr));
        label->setText(QCoreApplication::translate("Chat", "\350\276\223\345\205\245\344\277\241\346\201\257\357\274\232", nullptr));
        clearButton->setText(QCoreApplication::translate("Chat", "\346\270\205\347\251\272", nullptr));
        sendButton->setText(QCoreApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
