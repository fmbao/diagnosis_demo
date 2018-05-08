#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale()); //在字符串中可以使用中文

    Widget w;
    w.show();

    return a.exec();
}
