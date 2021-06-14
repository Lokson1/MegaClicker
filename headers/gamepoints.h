#ifndef GAMEPOINTS_H
#define GAMEPOINTS_H

#include <QObject>
#include <QString>

/*!
 * \class GamePoints
 * \brief This class used for managing data through whole project.
 * 		  Objects of this class are connected and have the same data.
*/
class GamePoints : public QObject
{
	Q_OBJECT
public:
	/// The only way to create object of this class
	static GamePoints* instance();
	/// It is safe way to delete GamePoints and save data
	static void tryToRm();

	static int getPoints();
	static int getRegPoints();
	static int getClickIncr();

	/// Increase s_points on amount
	void operator+= (int amount);
	/// Decrease s_points on amount
	void operator-= (int amount);
	/// Increase s_regPoints on amount
	void incrRegPoints(int amount);
	/// Initialize s_clickIncr with amount
	void incrClickIncr();
	/// clearing all data
	void clearData();

private:
	GamePoints();
	~GamePoints();

	static GamePoints* s_object;
	static int s_points;		// Game Points
	static int s_regPoints;		// Regular increasing of m_points
	static int s_clickIncr;		// Increasing points by on click

private slots:
	void regularIncr();

signals:
	void pointsIncr();
};

#endif // GAMEPOINTS_H
