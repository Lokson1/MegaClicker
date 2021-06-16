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

	void changePrint(QString newPrint);

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
	void incrIncr(int newValue);

private:
	int m_increase;
};

/*!
 * \class PurchaseButton
 * \brief Abstract class that manages isClickable button and it's price
*/
class PurchaseButton : public GameButton
{
	Q_OBJECT

public:
	PurchaseButton(QString printOnButton, QWidget* parent);

public slots:
	void isClickable();

protected:
	long m_cost;
};

/*!
 * \class RepeatingIncrease
 * \brief Detects user click, checks price before purchase and increase
 * 		  s_regPoints
*/
class RepeatingIncrease: public PurchaseButton
{
	Q_OBJECT

public:
	RepeatingIncrease(int increase, int cost, QWidget* parent = 0);

private slots:
	void byingAutoIncr();
	void autoPointsIncr();

private:
	int m_increase;
};

class IncreaseCLickPoints : public PurchaseButton
{
	Q_OBJECT

public:
	IncreaseCLickPoints(QWidget* parent);

private slots:
	void byingClickIncr();

signals:
	void changeClickMeButton(int value);
};


#endif // GAMEBUTTON_H
