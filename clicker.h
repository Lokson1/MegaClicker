#ifndef CLICKER_H
#define CLICKER_H

#include "mainwindow.h"
#include "menu.h"

#include <QWidget>
#include <QShortcut>

class Clicker : public QWidget
{
	Q_OBJECT
public:
	Clicker(QWidget *parent = nullptr);
	~Clicker();

private:
	int m_points;			// Game score
	int m_timeInterval; 	// time for appending new points
	int m_regularPoints; 	// points that we add every "m_timeInterval"

	MainWindow* m_mainWindow;
	Menu* m_menu;
	QShortcut* m_esc;

private slots:
	void switchWinMode();

};

#endif // CLICKER_H
