#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QFtp;

// 以下代码在例程18-4中添加
#include <QHash>
class QFile;
class QUrlInfo;
class QTreeWidgetItem;

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
    QFtp *ftp;

    // 以下代码在例程18-4中添加

    // 用来存储一个路径是否为目录的信息
    QHash<QString, bool> isDirectory;
    // 用来存储现在的路径
    QString currentPath;
    // 用来表示下载的文件
    QFile *file;



private slots:
    void ftpCommandStarted(int);
    void ftpCommandFinished(int, bool);

    // 以下代码在例程18-4中添加

    // 更新进度条
    void updateDataTransferProgress(qint64, qint64 );
    // 将服务器上的文件添加到Tree Widget部件中
    void addToList(const QUrlInfo &urlInfo);
    // 双击一个目录时显示其内容
    void processItem(QTreeWidgetItem*, int);

    void on_connectButton_clicked();
    void on_cdToParentButton_clicked();
    void on_downloadButton_clicked();
};

#endif // MAINWINDOW_H
