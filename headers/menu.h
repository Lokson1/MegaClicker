#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class Menu : public QWidget
{
	Q_OBJECT
public:
	Menu(QWidget *parent);

	void setMainWin(QWidget* win);
	void setSettingsWin(QWidget* win);

private:
	QLabel* m_label;

	QPushButton* m_returnToGame;
	QWidget* m_mainWindow;

	QPushButton* m_goToSettings;
	QWidget* m_settings;

	QPushButton* m_statistics;


private slots:
	void goToMainWin();
	void goToSettingsWin();
};

#endif // MENU_H
