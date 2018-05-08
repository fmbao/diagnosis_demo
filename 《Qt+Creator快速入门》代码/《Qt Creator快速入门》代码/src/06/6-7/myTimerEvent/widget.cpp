#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 开启一个1秒定时器，返回其ID
    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(3000);

    // 创建一个新的定时器
    QTimer *timer = new QTimer(this);
    // 关联定时器的溢出信号到我们的槽函数上
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    // 设置溢出时间为1秒，并启动定时器
    timer->start(1000);

    // 为随机数设置初值
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QTimer::singleShot(10000,this,SLOT(close()));
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

// 定时器溢出处理
void Widget::timerUpdate()
{
    // 获取当前时间
    QTime time = QTime::currentTime();
    // 转换为字符串
    QString text = time.toString("hh:mm");

    // 注意单引号间要输入一个空格
    // 每隔一秒就将“：”显示为空格
    if((time.second()%2) == 0) text[2]=' ';
    ui->lcdNumber->display(text);

    // 产生300以内的正整数
    int rand = qrand()%300;
    ui->lcdNumber->move(rand,rand);
}


