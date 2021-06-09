#ifndef GAMEPOINTS_H
#define GAMEPOINTS_H

#include <QObject>

/*!
 * \class GamePoints
 * \brief This class used for managing data through whole project.
 * 		  Objects of this class are connected and have the same data.
*/
class GamePoints : public QObject
{
	Q_OBJECT
public:
	static GamePoints* initPoints();
	static void tryToRm();

	static int getPoints();
	static int getRegPoints();

	void operator+= (int amount);
	void operator-= (int amount);
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
