#include <QtCore/QCoreApplication>
#include <QList>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> list;
    // 插入项目
    list << "aa" << "bb" << "cc";

    if(list[1] == "bb") list[1] = "ab";

    // 将“cc”换为“bc”
    list.replace(2,"bc");

    // 输出整个列表，现在列表为aa ab bc
    qDebug() << "the list is: ";
    for(int i=0; i<list.size(); ++i){
        qDebug() << list.at(i);
    }

    // 在列表尾部添加
    list.append("dd");
    // 在列表头部添加
    list.prepend("mm");

    // 从列表中删除第3个项目，并获取它
    QString str = list.takeAt(2);
    qDebug() << "at(2) item is: " << str;

    // 现在列表为mm aa bc dd
    qDebug() << "the list is: ";
    for(int i=0; i<list.size(); ++i)
    {
        qDebug() << list.at(i);
    }

    // 在位置2插入项目
    list.insert(2,"mm");

    // 交换项目1和项目3
    list.swap(1,3);

    // 现在列表为mm bc mm aa dd
    qDebug() << "the list is: ";
    for(int i=0; i<list.size(); ++i)
    {
        qDebug() << list.at(i);
    }

    // 列表中是否包含“mm”
    qDebug() << "contains 'mm' ?" << list.contains("mm");

    //包含“mm”的个数
    qDebug() << "the 'mm' count: " << list.count("mm");

    // 第一个”mm“的位置，默认从位置0开始往前查找，返回第一个匹配的项目的位置
    qDebug() << "the first 'mm' index: " <<list.indexOf("mm");

    //第二个”mm“的位置，我们指定从位置1开始往前查找
    qDebug() << "the second 'mm' index: " <<list.indexOf("mm",1);

    return a.exec();
}
