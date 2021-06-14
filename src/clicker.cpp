#include "clicker.h"
#include "gamepoints.h"

#include <QDebug>
#include <QFile>
#include <QGridLayout>

Clicker::Clicker(QWidget *parent) : QWidget(parent)
{
	m_mainWindow = new MainWindow(this);
	m_mainWindow->hide();

	m_settings = new Settings(this);

	m_menu = new Menu(this);
	m_menu->setMainWin(m_mainWindow);
	m_menu->setSettingsWin(m_settings);
	m_settings->setMenu(m_menu);

	QGridLayout* clickerGrid = new QGridLayout(this);
	clickerGrid->addWidget(m_mainWindow, 0, 0);
	clickerGrid->addWidget(m_menu, 0, 0);
	clickerGrid->addWidget(m_settings, 0, 0);

	m_esc = new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(switchWinMode()));
	setLayout(clickerGrid);
}

void Clicker::switchWinMode()
{
	m_menu->show();
	m_settings->hide();
	m_mainWindow->hide();
}
