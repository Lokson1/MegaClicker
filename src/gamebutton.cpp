#include "gamebutton.h"
#include <QDebug>
#include <QTimer>

GameButton::GameButton(QString printOnButton, QWidget* parent)
	: QPushButton(printOnButton, parent), s_points(GamePoints::initPoints())
{
}

GameButton::~GameButton() { s_points->tryToRm(); }

void GameButton::changePrint(QString newPrint) { this->setText(newPrint); }

/* MainClicker implementation */

MainClicker::MainClicker(QString printOnButton, QWidget* parent)
	: GameButton(printOnButton, parent), m_increase(1)
{
	connect(this, &QPushButton::clicked, this, &MainClicker::incrPoints);
}

void MainClicker::incrIncr(int newValue) { m_increase = newValue; }

void MainClicker::incrPoints()
{
	// Pointer is necessary
	*s_points += m_increase;
	emit changedPoints(m_increase);
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

// TODO make this function virtual
/// This slot makes button clickable when s_score is enough
void RepeatingIncrease::isClickable()
{
	if (s_points->getPoints() >= m_cost)
		this->setEnabled(true);
	else
		this->setEnabled(false);
}

/* implementation IncreaseCLickPoints */

int getPriceForClickIncr(int clickIncr) { return clickIncr * 100 - 100 / clickIncr;}

IncreaseCLickPoints::IncreaseCLickPoints(QWidget* parent)
	: GameButton(QString("Increase click me button on %1\nCost: %2")
				 .arg(s_points->getClickIncr()).arg(getPriceForClickIncr(s_points->getClickIncr())), parent)
{
	this->setEnabled(false);

	connect(this, &QPushButton::clicked, this, &IncreaseCLickPoints::byingClickIncr);
	m_cost = 100;
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

void IncreaseCLickPoints::isClickable()
{
	if (s_points->getPoints() >= m_cost)
		this->setEnabled(true);
	else
		this->setEnabled(false);
}
