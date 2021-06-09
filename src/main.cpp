#include "clicker.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Clicker window(app.applicationDirPath());
	window.show();
	window.resize(170, 200);
	return app.exec();
}
