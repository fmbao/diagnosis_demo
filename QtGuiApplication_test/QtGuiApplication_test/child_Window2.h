#pragma once
#ifndef CHILDE_WINDOW2_H
#define CHILDE_WINDOW2_H
#include<QWidget>

namespace Ui {
	class child_window2;
}
class child_window2 :public QWidget {
	Q_OBJECT
public:
	explicit child_window2(QWidget *parent = 0);
	



private:
	Ui::child_window2 *ui;
};



#endif // !CHILDE_WINDOW2_H

