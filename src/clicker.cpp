#include "clicker.h"
#include "gamepoints.h"

#include <QDebug>
#include <QFile>
#include <QGridLayout>

Clicker::Clicker(QWidget *parent) : QWidget(parent)
{
	m_mainWindow = new MainWindow(this);
	m_mainWindow->hide();

	m_menu = new Menu(this);
	m_menu->setMainWindow(m_mainWindow);

	QGridLayout* clickerGrid = new QGridLayout(this);
	clickerGrid->addWidget(m_mainWindow, 0, 0);
	clickerGrid->addWidget(m_menu, 0, 0);

	m_esc = new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(switchWinMode()));
	setLayout(clickerGrid);
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
