#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QTimer;

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
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
    QTimer *timer;
    int angle;
};

#endif // WIDGET_H
