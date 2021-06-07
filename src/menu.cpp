#include "menu.h"

#include <QFont>

///////////////////////////////////////////////////////////////////////////////
/// \brief menu::menu
/// \param parent
///
Menu::Menu(QWidget *parent) : QWidget(parent)
{
	m_label = new QLabel("Mega Clicker", this);
	m_label->setFont(QFont("Arial", 16, QFont::Bold));
}
