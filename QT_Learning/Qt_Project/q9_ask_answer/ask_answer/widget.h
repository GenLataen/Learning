#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qprocess>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onSubmit();
    void onModelOutput();
private:
    Ui::Widget *ui;
    QProcess *modelProcess; // 用于调用大模型的进程
    // 声明过滤 ANSI 转义序列的函数
    QString filterAnsiEscapeSequences( QString& input);
};
#endif // WIDGET_H


