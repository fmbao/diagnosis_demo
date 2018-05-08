#include <QApplication>
#include "myglwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MyGLWidget w;
    w.resize(400, 300);
    w.show();
    return app.exec();
}
