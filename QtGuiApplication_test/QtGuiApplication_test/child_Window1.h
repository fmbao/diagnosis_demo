#pragma once
#ifndef CHILD_WINDOW1_H
#define CHILD_WINDOW1_H
#include <QWidget>
#include <QToolButton>
#include <QComboBox>
#include <QCommandLinkButton>
#include<QLabel>
#include "ui_childwindow1.h"
namespace Ui {
	class child_Window1;
}
class child_window1 :public QWidget {
	Q_OBJECT
public:
	explicit child_window1(QWidget *parent = 0);
	//~child_window1();
signals:   //信号 定义在这个标号下
	void showmainwindow();
public slots:  // 槽函数
	//void sendmysignal();
	void on_backtomainwindow_clicked();
private:
	Ui::Form *ui1;
	QLabel label, label_2;
	QCommandLinkButton backtomainwindow;
	QComboBox comboBox, comboBox_2;
	QToolButton toolButton, toolButton_2;
};


#endif // !CHILD_WINDOW1_H

