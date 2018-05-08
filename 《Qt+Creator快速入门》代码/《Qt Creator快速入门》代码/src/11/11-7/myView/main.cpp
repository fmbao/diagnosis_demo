#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QGLWidget>

int main(int argc,char* argv[ ])
{
    QApplication app(argc,argv);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QGraphicsScene scene;
    scene.setSceneRect(-200, -150, 400, 300);
    for(int i = 0; i < 5; ++i) {
        MyItem *item = new MyItem;
        item->setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
        item->setPos(i * 50 - 90, -50);
        scene.addItem(item);
    }

    MyView view;
    //使用OpenGL进行渲染
    view.setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    view.setScene(&scene);
    view.setBackgroundBrush(QPixmap("../myView/background.png"));
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(300);

    MyItem *item1 = new MyItem;
    item1->setColor(Qt::blue);
    MyItem *item2 = new MyItem;
    item2->setColor(Qt::green);
    QGraphicsItemGroup *group = new QGraphicsItemGroup;
    group->addToGroup(item1);
    group->addToGroup(item2);
    group->setFlag(QGraphicsItem::ItemIsMovable);
    item2->setPos(30, 0);
    scene.addItem(group);

    QPixmap pixmap(400, 300);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    view.render(&painter);
    painter.end();
    pixmap.save("view.png");


    return app.exec();
}

