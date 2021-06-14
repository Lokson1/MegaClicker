#include "menu.h"

#include <QFont>
#include <QApplication>

Menu::Menu(QWidget *parent) : QWidget(parent)
{
	m_label = new QLabel("Mega Clicker", this);
	m_label->setFont(QFont("Arial", 16, QFont::Bold));

	m_returnToGame = new QPushButton("Resume game", this);

	m_goToSettings = new QPushButton("Settings", this);
	connect(m_goToSettings, &QPushButton::clicked, this, &Menu::goToSettingsWin);

	// TODO make statistics module
	m_statistics = new QPushButton("Statistics", this);

	QPushButton* quit = new QPushButton("Quit", this);
	connect(quit, &QPushButton::clicked, QApplication::instance(), &QApplication::exit);

	QGridLayout* grid = new QGridLayout(this);
	grid->addWidget(m_label, 0, 0);
	grid->addWidget(m_returnToGame, 1, 0);
	grid->addWidget(m_goToSettings, 2, 0);
	grid->addWidget(m_statistics, 3, 0);
	grid->addWidget(quit, 4, 0);

	setLayout(grid);
}

/// Connects "resume game" button with mainWindow
void Menu::setMainWin(QWidget *win)
{
	m_mainWindow = win;
	connect(m_returnToGame, &QPushButton::clicked, this, &Menu::goToMainWin);
}

void Menu::setSettingsWin(QWidget *win)
{
	m_settings = win;
	connect(m_goToSettings, &QPushButton::clicked, this, &Menu::goToSettingsWin);
}

void Menu::goToMainWin()
{
	if (m_mainWindow) {
		this->hide();
		m_mainWindow->show();
	}
}

void Menu::goToSettingsWin()
{
	if (m_settings) {
		this->hide();
		m_settings->show();
	}
}
