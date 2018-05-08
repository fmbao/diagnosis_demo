#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include <QVector>
#include <QStringList>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QStringList list;
    list << "one" << "two" << "three";

    qDebug() << QObject::tr("qCopy()算法：");
    QVector<QString> vect(3);

    // 将list中所有项目复制到vect中
    qCopy(list.begin(), list.end(), vect.begin());
    // 结果为one,two,three
    qDebug() << vect;

    qDebug() << endl << QObject::tr("qEqual()算法：");

    // 从list的开始到结束的所有项目与vect的开始及其后面的等数量的项目进行比较，全部相同则返回true
    bool ret1 = qEqual(list.begin(), list.end(), vect.begin());
    // 结果为true
    qDebug() << "euqal: " << ret1;

    qDebug() << endl << QObject::tr("qFind()算法：");
    // 从list中查找"two",返回第一个对应的值的迭代器，如果没有找到则返回end()
    QList<QString>::iterator i = qFind(list.begin(), list.end(), "two");
    // 结果为"two"
    qDebug() << *i;

    qDebug() << endl << QObject::tr("qFill()算法：");
    // 将list中的所有项目填充为"eleven"
    qFill(list.begin(), list.end(), "eleven");
    qDebug() << list; //结果eleven,eleven,eleven


    QList<int> list1;
    list1 << 3 << 3 << 6 << 6 << 6 << 8;

    qDebug() << endl << QObject::tr("qCount()算法：");
    int countOf6 = 0;
    // 查找6的个数
    qCount(list1.begin(), list1.end(), 6, countOf6);
    // 结果为3
    qDebug() << "countOf6: " << countOf6;

    qDebug() << endl << QObject::tr("qLowerBound()算法：");
    // 返回第一个出现5的位置，如果没有5，则返回5应该在的位置，list1被查找范围的项目必须是升序
    QList<int>::iterator j = qLowerBound(list1.begin(), list1.end(), 5);

    list1.insert(j, 5);
    // 结果3,3,5,6,6,6,8
    qDebug() << list1;


    QList<int> list2;
    list2 << 33 << 12 << 68 << 6 << 12;

    qDebug() << endl << QObject::tr("qSort()算法：");
    // 使用快速排序算法对list2进行升序排序，排序后两个12的位置不确定
    qSort(list2.begin(), list2.end());
    // 结果6,12,12,33,68
    qDebug() << list2;

    qDebug() << endl << QObject::tr("qStableSort()算法：");
    // 使用一种稳定排序算法对list2进行升序排序，排序前在前面的12排序后依然在前面
    qStableSort(list2.begin(), list2.end());
    // 结果6,12,12,33,68
    qDebug() << list2;

    qDebug() << endl << QObject::tr("qGreater()算法：");
    // 可以在qSort()算法中使其反向排序
    qSort(list2.begin(), list2.end(), qGreater<int>());
    // 结果68,33,12,12,6
    qDebug() << list2;


    qDebug() << endl << QObject::tr("qSwap()算法：");
    double pi = 3.14;
    double e = 2.71;
    // 交换pi和e的值
    qSwap(pi, e);
    // 结果pi=2.71,e=3.14
    qDebug() << "pi:" << pi << "e:" << e;

    return a.exec();
}
