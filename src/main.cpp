#include "clicker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Clicker window;
	window.show();
	return app.exec();
}
