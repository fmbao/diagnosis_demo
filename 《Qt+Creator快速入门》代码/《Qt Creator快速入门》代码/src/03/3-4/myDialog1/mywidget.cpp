#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>  //包含头文件

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    connect(ui->showChildButton,SIGNAL(clicked()),
            this,SLOT(showChildDialog()));
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}

