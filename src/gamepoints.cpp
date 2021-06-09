#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QDebug>

#include "gamepoints.h"

int GamePoints::s_points = 0;
int GamePoints::s_regPoints = 0;
GamePoints* GamePoints::s_object = nullptr;

/// The only way to create object of this class
GamePoints* GamePoints::initPoints()
{
	if (s_object == nullptr)
		s_object = new GamePoints();
	return s_object;
}

/// It is safe way to delete GamePoints and save data
void GamePoints::tryToRm()
{
	if (s_object != nullptr)
		delete s_object;
}

/// Initializating preveous points
GamePoints::GamePoints()
{
	QFile data("score");
	data.open(QIODevice::ReadOnly | QIODevice::ExistingOnly);
	QTextStream file(&data);

	file >> s_points;
	file >> s_regPoints;
	data.close();

	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &GamePoints::regularIncr);
	timer->start(1000);
}

GamePoints::~GamePoints()
{
	QFile data("score");
	data.open(QIODevice::WriteOnly);
	QTextStream file(&data);

	// TODO make regPoints save
	if (data.isOpen()) {
		file << s_points << Qt::endl;
		file << s_regPoints;
	}
	data.close();

	// clearing data
	s_object = nullptr;
}

int GamePoints::getPoints() { return s_points; }
int GamePoints::getRegPoints() { return s_regPoints; }

/// Increase s_points on amount
void GamePoints::operator+= (int amount) { s_points += amount; emit pointsIncr(); }
/// Decrease s_points on amount
void GamePoints::operator-= (int amount) { s_points -= amount; emit pointsIncr(); }
/// Increase s_regPoints on amount
void GamePoints::incrRegPoints(int amount) { s_regPoints += amount; }

void GamePoints::regularIncr() { s_points += s_regPoints; emit pointsIncr(); }
