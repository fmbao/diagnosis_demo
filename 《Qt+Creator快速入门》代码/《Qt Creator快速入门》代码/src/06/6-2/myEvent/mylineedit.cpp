#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>
MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

// 键盘按下事件
void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyLineEdit键盘按下事件");
    // 执行QLineEdit类的默认事件处理
    QLineEdit::keyPressEvent(event);
    // 忽略该事件
    event->ignore();
}

// 事件
bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
        qDebug() << tr("MyLineEdit的event()函数");
    // 执行QLineEdit类event()函数的默认操作
    return QLineEdit::event(event);
}
