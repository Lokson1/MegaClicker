#include "clicker.h"

#include <QDebug>
#include <QFile>

Clicker::Clicker(QWidget *parent) : QWidget(parent)
{
	m_mainWindow = new MainWindow(this);
	m_mainWindow->hide();

	m_menu = new Menu(this);
	m_menu->setMainWindow(m_mainWindow);

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
