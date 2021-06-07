#include "clicker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Clicker window;
	window.resize(250, 200);
	window.show();
	return app.exec();
}
