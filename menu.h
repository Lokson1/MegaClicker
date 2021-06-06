#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QLabel>

class Menu : public QWidget
{
	Q_OBJECT
public:
	Menu(QWidget *parent = nullptr);

private:
	QLabel* m_label;

signals:

};

#endif // MENU_H
