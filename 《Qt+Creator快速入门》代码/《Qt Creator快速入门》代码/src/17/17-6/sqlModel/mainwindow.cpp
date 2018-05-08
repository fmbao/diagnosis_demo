#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select * from student");
    model->setHeaderData(0, Qt::Horizontal, tr("Ñ§ºÅ"));
    model->setHeaderData(1, Qt::Horizontal, tr("ÐÕÃû"));
    model->setHeaderData(2, Qt::Horizontal, tr("¿Î³Ì"));
    QTableView *view = new QTableView(this);
    view->setModel(model);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
