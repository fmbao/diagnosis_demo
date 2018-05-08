#include "widget.h"
#include "ui_widget.h"
#include "myclass.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建MyClass类实例
    MyClass *my = new MyClass(this);

    // 关联MyClass类的信号到Widget类的槽函数上
    connect(my, SIGNAL(userNameChanged(QString)), this, SLOT(userChanged(QString)));

    // 设置属性的值
    my->setUserName("yafei");
    // 输出属性的值
    qDebug() << "userName:" << my->getUserName();


    // 使用QObject类的setProperty()函数设置属性的值
    my->setProperty("userName","linux");
    // 输出属性的值，这里使用了QObject类的property()函数，它返回值类型为QVariant
    qDebug() << "userName:" << my->property("userName").toString();

    // 动态属性，只对该实例有效
    my->setProperty("myValue",10);
    qDebug() << "myValue:" << my->property("myValue").toInt();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::userChanged(QString userName)
{
    qDebug() << "user changed:" << userName;
}
