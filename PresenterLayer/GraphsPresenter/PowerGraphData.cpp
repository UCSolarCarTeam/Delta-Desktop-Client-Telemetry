#include "PowerGraphData.h"

PowerGraphData::PowerGraphData()
{
}

PowerGraphData::PowerGraphData(int numberOfIntervals, 
                               double intervalSize, 
                               int numberOfDataSets)
{
    xData_ = QVector<double>(numberOfIntervals);
    for(double i = 0; i < numberOfIntervals; i++)
    {
        xData_.prepend(i * intervalSize);
    }

    yDataSets_ = QList<QVector<double> >();
    foreach(QVector<double> dataSet, yDataSets_)
    {
        dataSet = QVector<double>(numberOfIntervals, 0);
    }
}

QVector<double> PowerGraphData::xData()
{
    return xData_;
}

QList<QVector<double> > PowerGraphData::yDataSets()
{
    return yDataSets_;
}

void PowerGraphData::addData(double datum[])
{
    foreach(QVector<double> dataSet, yDataSets_)
    {
        dataSet.removeLast();
        yDataSets_ .prepend(dataSet);
    }
}


