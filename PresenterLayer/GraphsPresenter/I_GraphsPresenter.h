#pragma once 

#include <QObject>

class I_GraphsPresenter : public QObject
{
	Q_OBJECT
public:
	virtual ~I_GraphsPresenter() {}
	
	virtual void startUpdating() = 0;
	virtual void stopUpdating() = 0;

public slots:
	virtual void updateGraphData() = 0;
};	