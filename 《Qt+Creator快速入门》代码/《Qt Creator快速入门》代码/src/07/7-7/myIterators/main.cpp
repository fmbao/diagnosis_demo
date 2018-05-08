#include <QtCore/QCoreApplication>
#include <QList>
#include <QListIterator>
#include <QDebug>
#include <QMutableListIterator>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> list;
    list << "A" << "B" << "C" << "D";

    // 创建列表的只读迭代器，将list作为参数
    QListIterator<QString> i(list);

    // 正向遍历列表，结果为A，B，C，D
    qDebug()<< "the forward is :";
    while (i.hasNext())
        qDebug() << i.next();

    // 反向遍历列表，结果为D，C，B，A
    qDebug() << "the backward is :";
    while (i.hasPrevious())
        qDebug() << i.previous();

    QMutableListIterator<QString> j(list);
    // 返回列表尾部
    j.toBack();
    while (j.hasPrevious()) {
        QString str = j.previous();
        // 删除项目“B”
        if(str == "B") j.remove();
    }

    // 在列表最前面添加项目“Q”
    j.insert("Q");
    j.toBack();

    // 直接赋值
    if(j.hasPrevious()) j.previous() = "N";
    j.previous();

    // 使用setValue()进行赋值
    j.setValue("M");
    j.toFront();

    // 正向遍历列表，结果为Q，A，M，N
    qDebug()<< "the forward is :";
    while (j.hasNext())
        qDebug() << j.next();
    return a.exec();
}
