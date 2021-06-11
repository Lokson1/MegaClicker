#include "settings.h"

#include <QPushButton>
#include <QGridLayout>

Settings::Settings(QWidget* parent) : QWidget(parent)
{
	this->hide();

	QGridLayout* grid = new QGridLayout(this);

	QPushButton* returnToMenu = new QPushButton("Return to menu", this);

	grid->addWidget(returnToMenu, 1, 0);
	setLayout(grid);
}
