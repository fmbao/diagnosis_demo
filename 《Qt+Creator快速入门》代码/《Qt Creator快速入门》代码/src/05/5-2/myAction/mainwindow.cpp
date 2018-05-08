#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myaction.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建MyAction
    MyAction *action = new MyAction;
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));

    // 添加菜单并且加入我们的action
    editMenu->addAction(action);

    // 将action的getText()信号和这里的setText()槽进行关联
    connect(action,SIGNAL(getText(QString)),this,SLOT(setText(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


// 插入文本
void MainWindow::setText(const QString &string)
{
    // 将获取的文本添加到编辑器中
    ui->textEdit->setText(string);
}


