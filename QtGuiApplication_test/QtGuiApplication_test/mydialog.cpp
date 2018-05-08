#include "mydialog.h"
#include "ui_QtGuiApplication_test.h"
mydialog::mydialog(QWidget *parent /* = 0 */) : QDialog(parent), ui(new Ui::mydialog) {
	ui->setupUi(this);

}
mydialog::~mydialog() {
	delete ui;
}
void mydialog::on_pushButton_clicked() {
	accept();
}