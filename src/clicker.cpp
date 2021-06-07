#include "clicker.h"

#include <QDebug>

Clicker::Clicker(QWidget *parent) : QWidget(parent)
{
	m_mainWindow = new MainWindow(this);

	m_menu = new Menu(this);
	m_menu->hide();

	m_esc = new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(switchWinMode()));
}

void Clicker::switchWinMode()
{
	if (m_mainWindow->isHidden()) {
		m_mainWindow->show();
		m_menu->hide();
	}
	else {
		m_mainWindow->hide();
		m_menu->show();
	}
}

Clicker::~Clicker()
{
}
