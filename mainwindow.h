#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLCDNumber>
#include <QPushButton>
#include <QGridLayout>

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();

private:
	QLCDNumber* m_lcdNumber;
	int m_points;
	int m_regular_points;

	void fileReading();

private slots:
	void showPoints();

signals:
	void pointsSet();
};

#endif // MAINWINDOW_H
