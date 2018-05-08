#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QMotifStyle>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(new QMotifStyle);
    MainWindow w;
    w.show();

    return a.exec();
}
