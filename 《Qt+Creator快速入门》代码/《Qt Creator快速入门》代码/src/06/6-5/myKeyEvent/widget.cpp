#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 使主界面获得焦点
    setFocus();

    // 初始化变量
    keyUp = false;
    keyLeft = false;
    move = false;
}

Widget::~Widget()
{
    delete ui;
}

// 键盘按下事件
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){

        // 按键重复时不做处理
        if(event->isAutoRepeat()) return;

        // 标记向上方向键已经按下
        keyUp = true;

    }else if(event->key() == Qt::Key_Left){
        if(event->isAutoRepeat()) return;
        keyLeft = true;
    }
}

// 按键释放事件
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat()) return;

        // 释放按键后将标志设置为false
        keyUp = false;

        // 如果已经完成了移动
        if(move){

            // 设置标志为false
            move = false;
            // 直接返回
            return;
        }

        // 如果向左方向键已经按下且没有释放
        if(keyLeft){

            // 斜移
            ui->pushButton->move(30,80);
            // 标记已经移动
            move = true;

        }else{

            // 否则直接上移
            ui->pushButton->move(120,80);
        }
    }
    else if(event->key() == Qt::Key_Left){
        if(event->isAutoRepeat()) return;
        keyLeft = false;
        if(move){
            move = false;
            return;
        }
        if(keyUp) {
            ui->pushButton->move(30,80);
            move = true;
        }else{
            ui->pushButton->move(30,120);
        }
   }
   // 使用向下方向键来还原按钮的位置
   else if(event->key() == Qt::Key_Down){
            ui->pushButton->move(120,120);
   }
}
