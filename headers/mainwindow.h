#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamepoints.h"

#include <QWidget>
#include <QLCDNumber>
#include <QPushButton>
#include <QGridLayout>

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = 0);

private:
	QLCDNumber* m_lcdNumber;
	GamePoints* s_points;

	void fileReading();

private slots:
	void showPoints();

signals:
	void pointsSet();
};

#endif // MAINWINDOW_H
