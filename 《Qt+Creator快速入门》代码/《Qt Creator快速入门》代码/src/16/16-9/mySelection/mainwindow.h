#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTableView;
class QItemSelection;
class QModelIndex;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void getCurrentItemData();
    void toggleSelection();
    void updateSelection(const QItemSelection &selected,
                         const QItemSelection &deselected);
    void changeCurrent(const QModelIndex &current, const QModelIndex &previous);

private:
    Ui::MainWindow *ui;
    QTableView *tableView;
    QTableView *tableView2;
};

#endif // MAINWINDOW_H
