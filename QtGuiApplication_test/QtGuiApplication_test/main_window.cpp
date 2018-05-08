#include "ui_main_window.h"
#include "main_window.h"
#include <QDebug>
#include "child_Window1.h"
#include "child_Window2.h"
#include "child_Window3.h"
main_window::main_window(QWidget *parent):
	QMainWindow(parent),
	ui_main(new Ui::main_window)
{
	ui_main->setupUi(this);
	//fileselect.setParent(this);   //设置按钮父对象 是main_window
	//connect(&fileselect,&QPushButton::clicked,this,&main_window::ChangeToFileSelect);  //按钮绑定自定义的槽函数，当点击父窗口的按钮就会触发函数
	//connect(&cw1, &child_window1::mysignal, this, &main_window::show);
	/*functionkey.setParent(this);
	connect(&functionkey, &QPushButton::clicked, this, &main_window::ChangeToFunctionKey);
	report.setParent(this);
	connect(&report, &QPushButton::clicked, this, &main_window::ChangeToReport);*/
	
	
	connect(&cw1, &child_window1::showmainwindow, this, &main_window::show);
}

//显示子窗口 同时将主窗口 隐藏
void main_window::on_fileselect_clicked() {
	this->hide();
	cw1.show();
}


//void main_window::ChangeToFileSelect() {
//	this->hide();
//	cw1.show();
//}
//void main_window::ChangeToFunctionKey() {
//	this->hide();
//	cw2.show();
//}
//void main_window::ChangeToReport() {
//	this->hide();
//	cw3.show();
//}
main_window::~main_window() {
	delete ui_main;
}



//connect(ui->fileselect,SIGNAL(clicked()),this,SLOT())