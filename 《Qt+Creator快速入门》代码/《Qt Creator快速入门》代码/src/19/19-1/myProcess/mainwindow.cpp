#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&myProcess, SIGNAL(readyRead()), this, SLOT(showResult()));
    connect(&myProcess, SIGNAL(stateChanged(QProcess::ProcessState)),
            this, SLOT(showState(QProcess::ProcessState)));
    connect(&myProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(showError()));
    connect(&myProcess, SIGNAL(finished(int,QProcess::ExitStatus)),
            this, SLOT(showFinished(int, QProcess::ExitStatus)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 启动进程按钮
void MainWindow::on_pushButton_clicked()
{
    QString program = "cmd.exe";
    QStringList arguments;
    arguments << "/c dir&pause";
    myProcess.start(program, arguments);
}

// 显示运行结果
void MainWindow::showResult()
{
    qDebug() << "showResult: " << endl << QString(myProcess.readAll());
}

// 显示状态变化
void MainWindow::showState(QProcess::ProcessState state)
{
    qDebug() << "showState: ";
    if (state == QProcess::NotRunning) {
        qDebug() << "Not Running";
    } else if (state == QProcess::Starting) {
        qDebug() << "Starting";
    }  else {
        qDebug() << "Running";
    }
}

// 显示错误
void MainWindow::showError()
{
    qDebug() << "showError: " << endl << myProcess.errorString();
}

// 显示结束信息
void MainWindow::showFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "showFinished: " << endl << exitCode << exitStatus;
}


