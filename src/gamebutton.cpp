#include "gamebutton.h"
#include <QDebug>
#include <QTimer>

GameButton::GameButton(QString printOnButton, QWidget* parent)
	: QPushButton(printOnButton, parent), s_points(GamePoints::initPoints())
{
}

GameButton::~GameButton() { s_points->tryToRm(); }

/* MainClicker implementation */

MainClicker::MainClicker(QString printOnButton, QWidget* parent)
	: GameButton(printOnButton, parent)
{
	connect(this, &QPushButton::clicked, this, &MainClicker::incrPoints);
}

void MainClicker::incrPoints()
{
	// Pointer is necessary
	*s_points += 1;
	emit changedPoints(1);
}

/* RepeatingIncrease implementation */

RepeatingIncrease::RepeatingIncrease(int increase, int cost, QWidget* parent)
	: GameButton(QString("Auto: +%1 per sec.\nCost: %2").arg(increase).arg(cost), parent),
	  m_cost(cost), m_increase(increase)
{
	this->setEnabled(false);

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

/// This slot makes button clickable when s_score is enough
void RepeatingIncrease::isClickable()
{
	if (s_points->getPoints() >= m_cost)
		this->setEnabled(true);
	else
		this->setEnabled(false);
}
