#pragma once

#include <QWidget>

class I_SolarCarWindow : public QWidget
{
	Q_OBJECT
public:
	virtual ~I_SolarCarWindow() {}

	virtual void hideHeaderBar() = 0;
};