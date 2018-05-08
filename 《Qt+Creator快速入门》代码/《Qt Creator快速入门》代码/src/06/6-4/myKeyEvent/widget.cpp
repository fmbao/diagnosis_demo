#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// 键盘按下事件
void Widget::keyPressEvent(QKeyEvent *event)
{
    // 是否按下Ctrl键
    if(event->modifiers() == Qt::ControlModifier){

        // 是否按下M键
        if(event->key() == Qt::Key_M)
            // 窗口最大化
            setWindowState(Qt::WindowMaximized);
    }
    else QWidget::keyPressEvent(event);
}

// 按键释放事件
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    //其他操作
}
