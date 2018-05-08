#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

// 确定按钮
void MyDialog::on_pushButton_clicked()
{
    // 获取输入的数值
    int value = ui->spinBox->value();
    // 发射信号
    emit dlgReturn(value);
    // 关闭对话框
    close();
}
