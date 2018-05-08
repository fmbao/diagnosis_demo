#include <QtGui/QApplication>
#include "mainwindow.h"
#include "connection.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 这两行代码要写在创建连接之前
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    if (!createConnection()) return 1;
    MainWindow w;
    w.show();

    return a.exec();
}
