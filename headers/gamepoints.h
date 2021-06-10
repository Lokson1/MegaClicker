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
	static GamePoints* initPoints();
	/// It is safe way to delete GamePoints and save data
	static void tryToRm();

	static int getPoints();
	static int getRegPoints();
	static int getClickIncr();

	/// Set path for saving data. Gets fullPath to binary file
	static void setCurrentDir(QString fullPath) { s_path = fullPath; }

	/// Increase s_points on amount
	void operator+= (int amount);
	/// Decrease s_points on amount
	void operator-= (int amount);
	/// Increase s_regPoints on amount
	void incrRegPoints(int amount);
	/// Initialize s_clickIncr with amount
	void incrClickIncr();

private:
	GamePoints();
	~GamePoints();
	static QString s_path;
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
