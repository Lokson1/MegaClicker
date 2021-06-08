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

	void setMainWindow(QWidget* win);

private:
	QLabel* m_label;
	QPushButton* m_returnToGame;
	QPushButton* m_settings;
	QWidget* m_mainWindow;

private slots:
	void goToMainWin();
};

#endif // MENU_H
