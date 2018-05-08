#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <phonon>
class QMenu;
class QAction;

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void createContextMenu();
    void showContextMenu(const QPoint &pos);
    void aspectChanged(QAction* action);
    void scaleChanged(QAction* action);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

private:
    Ui::Widget *ui;
    Phonon::VideoWidget *videoWidget;
    QMenu *mainMenu;
};

#endif // WIDGET_H
