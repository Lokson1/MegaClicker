#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QMessageBox>

class Settings : public QWidget
{
	Q_OBJECT

public:
	Settings(QWidget* parent);

	void setMenu(QWidget* win);

private:
	QMessageBox* m_checkForReset;
	QWidget* m_menu;

private slots:
	void goToMenu();
	void makeMessage();
};

#endif // SETTINGS_H
