#include "menu.h"

#include <QFont>

///////////////////////////////////////////////////////////////////////////////
/// \brief menu::menu
/// \param parent
///
Menu::Menu(QWidget *parent) : QWidget(parent)
{
	m_label = new QLabel("Mega Clicker", this);
	m_label->setFont(QFont("Arial", 16, QFont::Bold));

	m_returnToGame = new QPushButton("Resume game", this);
	connect(m_returnToGame, &QPushButton::clicked, this, &Menu::goToMainWin);

	// TODO make button to work
	m_settings     = new QPushButton("Settings", this);

	QGridLayout* grid = new QGridLayout(this);
	grid->addWidget(m_label, 0, 0);
	grid->addWidget(m_returnToGame, 1, 0);
	grid->addWidget(m_settings, 2, 0);

	setLayout(grid);
}

void Menu::setMainWindow(QWidget *win) { m_mainWindow = win; }

void Menu::goToMainWin()
{
	if (m_mainWindow) {
		this->hide();
		m_mainWindow->show();
	}
}
