#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    // 创建按钮
    QPushButton *button = new QPushButton(this);

    // 指定按钮的对象名
    button->setObjectName("myButton");

    // 要在定义了部件以后再调用这个函数
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// 使用自动关联
void Widget::on_myButton_clicked()
{
    close();
}
