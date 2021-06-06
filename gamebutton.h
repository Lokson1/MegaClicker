#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QPushButton>
#include <QString>

///////////////////////////////////////////////////////////////////////////////
/// \brief The GameButton class
///
class GameButton : public QPushButton
{
	Q_OBJECT

public:
	GameButton(QString printOnButton, int* points, QWidget* parent = 0);

protected:
	int* m_pPoints;		// Points at game score

signals:
	void changedPoints(int value);
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The MainClicker class detects user click and increase points.
///
class MainClicker : public GameButton
{
	Q_OBJECT

public:
	MainClicker(QString printOnButton, int* points, QWidget* parent = 0);

public slots:
	void incrPoints();
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The RepeatingIncrease class automatically increase points
///
class RepeatingIncrease: public GameButton
{
	Q_OBJECT

public:
	RepeatingIncrease(int increase, int* points, int cost, QWidget* parent = 0);

private slots:
	void autoClickPlusFive();
	void autoPlusFive();

public slots:
	void isClickable();

private:
	int m_increase;
	int m_regularIncr;	// Regular increasing points
	int m_cost;
};

#endif // GAMEBUTTON_H
