#include "gamebutton.h"
#include <QDebug>
#include <QTimer>

GameButton::GameButton(QString printOnButton, QWidget* parent)
	: QPushButton(printOnButton, parent), s_points(GamePoints::instance())
{
}

GameButton::~GameButton() { s_points->tryToRm(); }

void GameButton::changePrint(QString newPrint) { this->setText(newPrint); }

/* MainClicker implementation */

MainClicker::MainClicker(QString printOnButton, QWidget* parent)
	: GameButton(printOnButton, parent), m_increase(1)
{
	m_increase = GamePoints::getClickIncr();
	connect(this, &QPushButton::clicked, this, &MainClicker::incrPoints);
}

void MainClicker::incrIncr(int newValue) { m_increase = newValue; }

void MainClicker::incrPoints()
{
	m_increase = GamePoints::getClickIncr();
	// Pointer is necessary
	*s_points += m_increase;
	emit changedPoints(m_increase);
}

/* PurchaseButton implementation */

PurchaseButton::PurchaseButton(QString print, QWidget* parent)
	: GameButton(print, parent)
{
}

void PurchaseButton::isClickable()
{
	if (s_points->getPoints() >= m_cost)
		this->setEnabled(true);
	else
		this->setEnabled(false);
}

/* RepeatingIncrease implementation */

RepeatingIncrease::RepeatingIncrease(int increase, int cost, QWidget* parent)
	: PurchaseButton(QString("Auto: +%1 per sec.\nCost: %2").arg(increase).arg(cost), parent)
{
	this->setEnabled(false);
	m_cost = cost;

	connect(this, &QPushButton::clicked, this, &RepeatingIncrease::byingAutoIncr);
	connect(s_points, &GamePoints::pointsIncr, this, &RepeatingIncrease::autoPointsIncr);
}

void RepeatingIncrease::byingAutoIncr()
{
	if (s_points->getPoints() >= m_cost) {
		*s_points -= m_cost;
		s_points->incrRegPoints(m_increase);
		emit changedPoints(s_points->getPoints());
	}
}

void RepeatingIncrease::autoPointsIncr() { emit changedPoints(s_points->getPoints()); }

/* implementation IncreaseCLickPoints */

int getPriceForClickIncr(int clickIncr)
{
	if (clickIncr != 1 && clickIncr != 0)
		return clickIncr * 100 - 100 / clickIncr;
	return 100;
}

IncreaseCLickPoints::IncreaseCLickPoints(QWidget* parent)
	: PurchaseButton(QString("Increase click me button on %1\nCost: %2")
				 .arg(GamePoints::getClickIncr()).arg(getPriceForClickIncr(GamePoints::getClickIncr())), parent)
{
	this->setEnabled(false);

	connect(this, &QPushButton::clicked, this, &IncreaseCLickPoints::byingClickIncr);
	m_cost = getPriceForClickIncr(GamePoints::getClickIncr());
}

void IncreaseCLickPoints::byingClickIncr()
{
	if (s_points->getPoints() >= m_cost) {
		*s_points -= m_cost;
		s_points->incrClickIncr();
		int increase = s_points->getClickIncr();

		m_cost = increase * 100 - 100 / increase;
		this->changePrint(QString("Increase click me button on %1\n"
								  "Cost: %2").arg(increase).arg(m_cost));
		emit changeClickMeButton(increase);
		emit changedPoints(s_points->getPoints());
	}
}
