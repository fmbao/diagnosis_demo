#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QPicture>
#include <QDebug>
#include <QDesktopWidget>
#include <QLabel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //截屏并显示在标签中
    QPixmap screen = QPixmap::grabWindow(QApplication::desktop()->winId());
    screen.save("../myDrawing3/screen.png");
    QLabel *label = new QLabel(this);
    label->resize(400, 200);
    QPixmap pix = screen.scaled(label->size(), Qt::KeepAspectRatio,
                                Qt::SmoothTransformation);
    label->setPixmap(pix);
    label->move(0, 100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../myDrawing3/yafeilinux.png");
    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
    painter.setBrush(QColor(255, 255, 255, 100));
    painter.drawRect(0, 0, pix.width(), pix.height());
    painter.drawPixmap(100, 0, pix.width(), pix.height(), pix);
    painter.setBrush(QColor(0, 0, 255, 100));
    painter.drawRect(100, 0, pix.width(), pix.height());                 
}
