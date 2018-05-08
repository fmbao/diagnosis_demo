#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置pushButton的背景为黄色
    //ui->pushButton->setStyleSheet("background:yellow");
    // 设置horizontalSlider的背景为蓝色
    //ui->horizontalSlider->setStyleSheet("background:blue");
    //setStyleSheet("QPushButton{background:yellow}QSlider{background:blue}");

    QFile file(":/qss/my.qss");
    // 只读方式打开该文件
    file.open(QFile::ReadOnly); 
    // 读取文件全部内容，使用tr()函数将其转换为QString类型
    QString styleSheet = tr(file.readAll());
    // 为QApplication设置样式表
    qApp->setStyleSheet(styleSheet); 
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file(":/qss/my1.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    qApp->setStyleSheet(styleSheet);
}
