#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer;
    picId = 2;

    QImage img;
    img.load("D:\\My_Files\\EmbeddedSystem\\Qt_Project\\p5_2timer\\q5_2timer\\1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));

    //定时器时间到，发出timerout信号
    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    timer->start(TIMEOUT);
}

void Widget::timeoutSlot()
{
    QString path("D:\\My_Files\\EmbeddedSystem\\Qt_Project\\p5_2timer\\q5_2timer\\");
    path += QString::number(picId);
    path += ".jpg";

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));

    picId++;
    if(picId == 4)
        picId = 1;
}

void Widget::on_pushButton_2_clicked()
{
    timer->stop();
}

