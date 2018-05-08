#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include <QDebug>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建按钮部件，指定widget为父部件
    MyButton *button = new MyButton(this);
    button->setText("button");

    MyButton *button2 = new MyButton;
    MyButton *button3 = new MyButton;

    // 在该窗口中使用布局管理器
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button2);
    layout->addWidget(button3);
    setLayout(layout);

    // 输出所有子部件的列表
    qDebug() << children();
}

Widget::~Widget()
{
    delete ui;
    qDebug() << "delete widget";
}

