
#include <QtWidgets/QApplication>
#include <QStyleFactory>
#include "loginwidget.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	LoginWidget login_widget;
	
	login_widget.show();
	//w.show();
	//w.showFullScreen();
	return a.exec();
}
