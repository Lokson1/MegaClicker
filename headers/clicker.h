#ifndef CLICKER_H
#define CLICKER_H

#include "mainwindow.h"
#include "menu.h"

#include <QWidget>
#include <QShortcut>

/*!
 * \class Clicker
 * \brief This is main class of the game that managing swapping between windows.
*/
class Clicker : public QWidget
{
	Q_OBJECT

public:
	Clicker(QWidget *parent = nullptr);

private:
	MainWindow* m_mainWindow;
	Menu* m_menu;
	QShortcut* m_esc;

private slots:
	void switchWinMode();
};

#endif // CLICKER_H
