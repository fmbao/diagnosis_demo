#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QWebView;
class QLineEdit;

#include <QModelIndex>
class QListWidget;


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
    QWebView *view;
    QLineEdit *locationEdit;
    int progress;

    QListWidget *historyList;

protected slots:
    void changeLocation(); // 改变路径
    void setProgress(int); // 更新进度
    void adjustTitle();    // 更新标题显示
    void finishLoading(bool); // 加载完成后进行处理
    void changeIcon(); // 更改网站图标

    void showHistory(); // 显示历史记录
    void gotoHistory(QModelIndex); // 转到历史记录
};

#endif // MAINWINDOW_H
