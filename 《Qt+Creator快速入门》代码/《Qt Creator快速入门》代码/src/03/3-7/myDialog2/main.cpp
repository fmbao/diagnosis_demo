#include <QtGui/QApplication>
#include "mywidget.h"
#include <QTextCodec> //添加头文件
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale()); //使程序中可以使用中文
    MyWidget w;
    w.show();

    return a.exec();
}
