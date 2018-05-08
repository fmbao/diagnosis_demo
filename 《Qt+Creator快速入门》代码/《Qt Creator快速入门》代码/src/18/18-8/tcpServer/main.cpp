#include <QtGui/QApplication>
#include "server.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Server w;
    w.show();

    return a.exec();
}
