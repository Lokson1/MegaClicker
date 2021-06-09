#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include "gamepoints.h"

#include <QPushButton>
#include <QString>

/*!
 * \class GameButton
 * \brief The fundamental class class that provides interfase for other buttons
*/
class GameButton : public QPushButton
{
	Q_OBJECT

public:
	GameButton(QString printOnButton, QWidget* parent = 0);
	~GameButton();

protected:
	GamePoints* s_points;

signals:
	void changedPoints(int value);
};

/*!
 * \class MainClicker
 * \brief The MainClicker class detects user click and increase s_points.
*/
class MainClicker : public GameButton
{
	Q_OBJECT

public:
	MainClicker(QString printOnButton, QWidget* parent = 0);

public slots:
	void incrPoints();
};

/*!
 * \class RepeatingIncrease
 * \brief Detects user click, checks price before purchase and increase
 * 		  s_regPoints
*/
class RepeatingIncrease: public GameButton
{
	Q_OBJECT

public:
	RepeatingIncrease(int increase, int cost, QWidget* parent = 0);

private slots:
	void byingAutoIncr();
	void autoPointsIncr();

public slots:
	void isClickable();

private:
	int m_cost;
	int m_increase;
};

#endif // GAMEBUTTON_H
