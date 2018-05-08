#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include "child_Window1.h"    // 包含子窗口的头文件
#include "child_Window2.h"
#include "child_Window3.h"
namespace Ui {
	class main_window;
}
class main_window :public QMainWindow {
	Q_OBJECT
public:
	explicit main_window(QWidget *parent = 0);
	~main_window();
private slots:
	void on_fileselect_clicked();   //采用自动关联 
private:
	Ui::main_window *ui_main;
	child_window1 cw1;            //  创建子窗口的实例
	child_window2 cw2;
	child_window3 cw3;
	QPushButton fileselect;     // 创建的按钮 父窗口的一个成员
	QPushButton functionkey;    
	QPushButton report;
};


#endif // !MAIN_WINDOW_H

