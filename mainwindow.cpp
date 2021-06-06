#include "mainwindow.h"
#include "gamebutton.h"
#include <QTextStream>
#include <QFile>
#include <QtDebug>
#include <QKeyEvent>

void MainWindow::showPoints()
{
	m_lcdNumber->display(m_points);
	emit pointsSet();
}

// initializating preveous points
void MainWindow::fileReading()
{
	QFile data("score");
	data.open(QIODevice::ReadOnly | QIODevice::ExistingOnly);
	QTextStream file(&data);
	file >> m_points;
	data.close();
}

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
	fileReading();

	// Configurating buttons
	MainClicker* mainClicker = new MainClicker("Click me", &m_points, this);
	RepeatingIncrease*	autoPlusOne = new RepeatingIncrease(1, &m_points, 600, this);
	RepeatingIncrease*  autoPlusTwo = new RepeatingIncrease(2, &m_points, 1000, this);

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

MainWindow::~MainWindow()
{
	QFile data("score");
	data.open(QIODevice::WriteOnly);
	QTextStream file(&data);

	if (data.isOpen()) {
		file << m_points;
	}
	else
		qDebug() << "File is not opened";
	data.close();
}
