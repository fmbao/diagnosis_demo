#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTableView;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTableView *tableView;
};

#endif // MAINWINDOW_H
