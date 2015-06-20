#pragma once

#include <QVector>

class PowerGraphData
{
public:
	PowerGraphData();
    PowerGraphData(int numberOfIntervals, 
    		       double intervalSize, 
    		       int numberOfDataSets);
    
    QVector<double> xData();
    QList<QVector<double> > yDataSets();
    void addData(double datum[]);

private:
    QVector<double> xData_;
    QList<QVector<double> > yDataSets_;
};