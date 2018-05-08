#include<QApplication>
#include<QDialog>
#include <QLabel>
#include "main_window.h"
#include "child_Window1.h"
#include "child_Window2.h"
#include "child_Window3.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	main_window w;
	child_window1 cw1;
	child_window2 cw2;
	child_window3 cw3;
	
	//if(cw1.exec())
	w.show();

	return a.exec();
	

	
}
