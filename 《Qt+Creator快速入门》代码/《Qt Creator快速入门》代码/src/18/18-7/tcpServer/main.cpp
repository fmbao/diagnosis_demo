#include <QtGui/QApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server w;
    w.show();

    return a.exec();
}
