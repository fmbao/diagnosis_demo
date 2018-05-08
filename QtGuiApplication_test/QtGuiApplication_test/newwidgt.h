#pragma once
#ifndef NEWWIDGT_H
#define NEWWIDGT_H

#include <QWidget>
#include <QApplication>
namespace Ui {
	class newwidgt :public QWidget {};
}
class newwidgt : public QWidget {
	Q_OBJECT
public:
	explicit newwidgt(QWidget *parent = 0);
	~newwidgt();
private:
	Ui::newwidgt * ui;
public slots:
	void fileselect_1();
	
private slots:
	void on_push_button_clicked();
};



#endif // !NEWWIDGT_H

