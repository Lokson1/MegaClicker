#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QTimer>
#include <QApplication>

#include "gamepoints.h"

int GamePoints::s_points = 0;
int GamePoints::s_regPoints = 0;
int GamePoints::s_clickIncr = 1;
QString GamePoints::s_path = "";
GamePoints* GamePoints::s_object = nullptr;

GamePoints* GamePoints::initPoints()
{
	if (s_object == nullptr)
		s_object = new GamePoints();
	return s_object;
}

void GamePoints::tryToRm()
{
	if (s_object != nullptr)
		delete s_object;
}

/// Initializating preveous points
GamePoints::GamePoints()
{
	QFile data(QString("%1/score").arg(QApplication::applicationDirPath()));

	if (data.exists()) {
		data.open(QIODevice::ReadOnly | QIODevice::ExistingOnly);
		QTextStream file(&data);
		file >> s_points;
		file >> s_regPoints;
		file >> s_clickIncr;
	}
	else {
		data.open(QIODevice::WriteOnly | QIODevice::NewOnly);
		QTextStream file(&data);
		file << 0 << Qt::endl;
		file << 0 << Qt::endl;
		file << 0 << Qt::endl;
	}

	data.close();

	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &GamePoints::regularIncr);
	timer->start(1000);
}

GamePoints::~GamePoints()
{
	QFile data(QString("%1/score").arg(s_path));

	data.open(QIODevice::WriteOnly);

	QTextStream file(&data);
	if (data.isOpen()) {
		file << s_points << Qt::endl;
		file << s_regPoints << Qt::endl;
		file << s_clickIncr;
	}
	data.close();

	// clearing data
	s_object = nullptr;
}

int GamePoints::getPoints() { return s_points; }
int GamePoints::getRegPoints() { return s_regPoints; }
int GamePoints::getClickIncr() { return s_clickIncr; }

void GamePoints::operator+= (int amount) { s_points += amount; emit pointsIncr(); }
void GamePoints::operator-= (int amount) { s_points -= amount; emit pointsIncr(); }
void GamePoints::incrRegPoints(int amount) { s_regPoints += amount; }
void GamePoints::incrClickIncr() { s_clickIncr+= s_clickIncr; }

void GamePoints::regularIncr() { s_points += s_regPoints; emit pointsIncr(); }
