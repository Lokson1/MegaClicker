#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include "gamepoints.h"

#include <QPushButton>
#include <QString>

///////////////////////////////////////////////////////////////////////////////
/// \brief The GameButton class
///
class GameButton : public QPushButton
{
	Q_OBJECT

public:
	GameButton(QString printOnButton, QWidget* parent = 0);
	~GameButton();

protected:
	GamePoints* s_points;		// Points at game score

signals:
	void changedPoints(int value);
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The MainClicker class detects user click and increase points.
///
class MainClicker : public GameButton
{
	Q_OBJECT

public:
	MainClicker(QString printOnButton, QWidget* parent = 0);

public slots:
	void incrPoints();
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The RepeatingIncrease class automatically increase points
///
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
