#ifndef GAMEPOINTS_H
#define GAMEPOINTS_H

#include <QObject>

class GamePoints : public QObject
{
	Q_OBJECT
public:
	static GamePoints* initPoints();
	// It is safe way to delete GamePoints and save data
	static void tryToRm();

	static int getPoints();
	static int getRegPoints();

	// Increase and decrease s_points on amount
	void operator+= (int amount);
	void operator-= (int amount);
	// Increase s_regPoints on amount
	void incrRegPoints(int amount);

private:
	GamePoints();
	~GamePoints();
	static GamePoints* s_object;
	static int s_points;		// Game Points
	static int s_regPoints;		// Regular increasing of m_points

private slots:
	void regularIncr();

signals:
	void pointsIncr();
};

#endif // GAMEPOINTS_H
