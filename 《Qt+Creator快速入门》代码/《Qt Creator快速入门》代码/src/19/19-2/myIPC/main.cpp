#include <QtGui/QApplication>
#include "dialog.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Dialog w;
    w.show();

    return a.exec();
}
