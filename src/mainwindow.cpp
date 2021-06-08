#include "mainwindow.h"
#include "gamebutton.h"
#include <QTextStream>
#include <QFile>
#include <QtDebug>
#include <QKeyEvent>

void MainWindow::showPoints()
{
	m_lcdNumber->display(s_points->getPoints());
	emit pointsSet();
}

MainWindow::MainWindow(QWidget* parent) : QWidget(parent), s_points(GamePoints::initPoints())
{
	// Configurating buttons
	MainClicker* mainClicker = new MainClicker("Click me", this);
	RepeatingIncrease*	autoPlusOne = new RepeatingIncrease(1, 600, this);
	RepeatingIncrease*  autoPlusTwo = new RepeatingIncrease(2, 1000, this);

	// TODO fix bug with size of QGrid (it is small and doesn't fill all background)
	QGridLayout* grid = new QGridLayout(this);
	m_lcdNumber       = new QLCDNumber(this);
	m_lcdNumber->setDigitCount(11);

	grid->addWidget(m_lcdNumber, 0, 0);
	grid->addWidget(mainClicker, 1, 0);
	grid->addWidget(autoPlusOne, 2, 0);
	grid->addWidget(autoPlusTwo, 3, 0);

	setLayout(grid);

	connect(mainClicker, &MainClicker::changedPoints, this, &MainWindow::showPoints);

	connect(autoPlusOne, &MainClicker::changedPoints, this, &MainWindow::showPoints);
	connect(this, &MainWindow::pointsSet, autoPlusOne, &RepeatingIncrease::isClickable);
	connect(autoPlusTwo, &MainClicker::changedPoints, this, &MainWindow::showPoints);
	connect(this, &MainWindow::pointsSet, autoPlusTwo, &RepeatingIncrease::isClickable);
}
