#include <QtGui/QApplication>
#include "client.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Client w;
    w.show();

    return a.exec();
}
