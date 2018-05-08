#include <QtGui/QApplication>
#include "receiver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Receiver w;
    w.show();

    return a.exec();
}
