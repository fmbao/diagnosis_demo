#include <QtCore/QCoreApplication>
#include <QMapIterator>
#include <QMutableMapIterator>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, QString> map;
    map.insert("Paris", "France");
    map.insert("Guatemala City", "Guatemala");
    map.insert("Mexico City", "Mexico");
    map.insert("Moscow", "Russia");

    QMapIterator<QString,QString> i(map);
    while(i.hasNext()) {
        i.next();
        qDebug() << i.key() << " : " << i.value();
    }

    // 向前查找键的值
    if(i.findPrevious("Mexico")) qDebug() << "find 'Mexico'";
    QMutableMapIterator<QString, QString> j(map);
    while (j.hasNext()) {

        // endsWith()是QString类的函数
        if (j.next().key().endsWith("City"))
            // 删除含有“City”结尾的键的项目
            j.remove();
    }
    while(j.hasPrevious()) {

        // 现在的键值对为(paris,France),(Moscow,Russia)
        j.previous();
        qDebug() << j.key() << " : " << j.value();
    }
    return a.exec();
}
