#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QDialog>

namespace Ui {
	class mydialog : public QDialog {};
}
class mydialog :public QDialog {
	Q_OBJECT
public:
	explicit mydialog(QWidget *parent = 0);
	~mydialog();

private slots:
void on_pushButton_clicked();

private:
	Ui::mydialog *ui;


};


#endif // !MYDIALOG_H
