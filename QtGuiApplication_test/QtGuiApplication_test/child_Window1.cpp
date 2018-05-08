#include "ui_childwindow1.h"
#include "child_Window1.h"


child_window1::child_window1(QWidget *parent) :
	QWidget(parent),
	ui1(new Ui::Form)
{
	//this->setWindowTitle("文件输入输出-文件夹选择");
	ui1->setupUi(this);
	//backtomainwindow.setParent(this);   //设置按钮的父对象为子窗口
	connect(&backtomainwindow, &QCommandLinkButton::clicked, this, &child_window1::on_backtomainwindow_clicked);
	
}

void child_window1::on_backtomainwindow_clicked() {
	
	emit showmainwindow();
	this->hide();
}

//void child_window1::sendmysignal()   //定义槽函数
//{
//	emit mysignal();
//	this->hide();
//}

