#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::Widget *ui;
    //缓冲区
    QPixmap pix;
    //临时缓冲区
    QPixmap tempPix;
    QPoint startPoint;
    QPoint endPoint;
    //是否正在绘图的标志
    bool isDrawing;
};

#endif // WIDGET_H
