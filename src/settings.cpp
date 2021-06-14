#include "settings.h"
#include "gamepoints.h"

#include <QPushButton>
#include <QGridLayout>

Settings::Settings(QWidget* parent) : QWidget(parent)
{
	this->hide();

	QGridLayout* grid = new QGridLayout(this);

	QPushButton* returnToMenu = new QPushButton("Return to menu", this);
	connect(returnToMenu, &QPushButton::clicked, this, &Settings::goToMenu);

	m_checkForReset = new QMessageBox(this);
	m_checkForReset->setText("Are you sure you want to reset points");
	m_checkForReset->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	m_checkForReset->setDefaultButton(QMessageBox::No);

	// TODO make slot in settings for message and clearing data
	QPushButton* resetPoints = new QPushButton("Reset Points", this);
	connect(resetPoints, &QPushButton::clicked, this, &Settings::makeMessage);

	grid->addWidget(resetPoints, 0, 0);
	grid->addWidget(returnToMenu, 1, 0);
	setLayout(grid);
}

void Settings::setMenu(QWidget* win)
{
	m_menu = win;
}

void Settings::goToMenu()
{
	if (m_menu) {
		this->hide();
		m_menu->show();
	}
}

void Settings::makeMessage()
{
	int rt = m_checkForReset->exec();
	if (rt == QMessageBox::Yes)
		GamePoints::instance()->clearData();
}
