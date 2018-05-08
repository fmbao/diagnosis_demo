#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 开启一个1秒定时器，返回其ID
    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(3000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    // 判断是哪个定时器
    if(event->timerId() == id1){
        qDebug() << "timer1";
    }
    else if(event->timerId() == id2){
        qDebug() << "timer2";
    }
    else{
        qDebug() << "timer3";
    }
}
