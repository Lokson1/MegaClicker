#include "gamebutton.h"
#include <QDebug>
#include <QTimer>

GameButton::GameButton(QString printOnButton, int* points, QWidget* parent)
	: QPushButton(printOnButton, parent)
{
	m_pPoints = points;
}

///////////////////////////////////////////////////////////////////////////////
// Main clicker implementation
///////////////////////////////////////////////////////////////////////////////

MainClicker::MainClicker(QString printOnButton, int* points, QWidget* parent)
	: GameButton(printOnButton, points, parent)
{
	connect(this, &QPushButton::clicked, this, &MainClicker::incrPoints);
}

void MainClicker::incrPoints()
{
	(*m_pPoints)++;
	emit changedPoints(*m_pPoints);
}

///////////////////////////////////////////////////////////////////////////////
// Plus five button implementation
///////////////////////////////////////////////////////////////////////////////

RepeatingIncrease::RepeatingIncrease(int increase, int* points,
									 int cost, QWidget* parent)
	: GameButton(QString("Auto: +%1 per sec.\nCost: %2").arg(increase).arg(cost),points, parent),
	  m_increase(increase), m_cost(cost)
{
	m_regularIncr = 0;
	this->setEnabled(false);

	connect(this, &QPushButton::clicked, this, &RepeatingIncrease::autoClickPlusFive);

	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &RepeatingIncrease::autoPlusFive);
	timer->start(1000);
}

void RepeatingIncrease::autoClickPlusFive()
{
	if (*m_pPoints >= m_cost) {
		*m_pPoints -= m_cost;
		m_regularIncr += m_increase;
		emit changedPoints(*m_pPoints);
	}
}

void RepeatingIncrease::autoPlusFive()
{
	*m_pPoints += m_regularIncr;
	emit changedPoints(*m_pPoints);
}

void RepeatingIncrease::isClickable()
{
	if (*m_pPoints >= m_cost)
		this->setEnabled(true);
	else
		this->setEnabled(false);
}
