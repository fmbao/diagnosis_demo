#pragma once
#ifndef CHILDE_WINDOW3_H
#define CHILDE_WINDOW3_H
#include<QWidget>

namespace Ui {
	class child_window3;
}
class child_window3 :public QWidget {
	Q_OBJECT
public:
	explicit child_window3(QWidget *parent = 0);

	public slots:


private:
	Ui::child_window3 *ui;
};



#endif // !CHILDE_WINDOW3_H