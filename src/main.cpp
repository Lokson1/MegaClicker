#include "clicker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Clicker window;
	window.show();
	window.resize(170, 200);
	return app.exec();
}
