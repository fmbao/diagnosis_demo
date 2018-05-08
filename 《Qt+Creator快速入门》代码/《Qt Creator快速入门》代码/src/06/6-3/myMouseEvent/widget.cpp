#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置鼠标跟踪
   // setMouseTracking(true);

    // 创建光标对象
    QCursor cursor;
    // 设置光标形状
    cursor.setShape(Qt::OpenHandCursor);
    // 使用光标
    setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

// 鼠标按下事件
void Widget::mousePressEvent(QMouseEvent *event)
{
    // 如果是鼠标左键按下
    if(event->button() == Qt::LeftButton){

        // 使鼠标指针暂时变为小手抓取的样子
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);

        // 获取指针位置和窗口位置的差值，以便移动时使用
        offset = event->globalPos() - pos();
    }

    // 如果是鼠标右键按下
    else if(event->button() == Qt::RightButton){

        // 使用自定义的图片作为鼠标指针
        QCursor cursor(QPixmap("../yafeilinux.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

// 鼠标移动事件
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    // 这里必须使用buttons()
    if(event->buttons() & Qt::LeftButton){

        // 我们使用鼠标指针当前的位置减去差值，就得到了窗口应该移动的位置
        QPoint temp;
        temp = event->globalPos() - offset;
        move(temp);
    }
}

// 鼠标释放事件
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    // 恢复鼠标指针形状
    QApplication::restoreOverrideCursor();
}

// 鼠标双击事件
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 如果是鼠标左键按下
    if(event->button() == Qt::LeftButton){

        // 如果现在不是全屏，将窗口设置为全屏
        if(windowState() != Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);

        // 如果现在已经是全屏状态，那么恢复以前的大小
        else setWindowState(Qt::WindowNoState);

    }
}

// 滚轮事件
void Widget::wheelEvent(QWheelEvent *event)
{
    // 当滚轮远离使用者时进行放大，当滚轮向使用者方向旋转时进行缩小
    if(event->delta() > 0){
        ui->textEdit->zoomIn();
    }else{
        ui->textEdit->zoomOut();
    }
}
