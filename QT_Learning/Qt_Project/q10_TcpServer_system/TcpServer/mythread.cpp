#include "mythread.h"

myThread::myThread(QTcpSocket *s)
{
    socket = s;
}


void myThread::run()
{
    connect(socket, &QTcpSocket::readyRead,this, &myThread::clientInfoSlot);

}


void myThread::clientInfoSlot()
{
    qDebug() << socket->readAll();

}
