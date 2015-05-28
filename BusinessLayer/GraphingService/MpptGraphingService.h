#pragma once 
#include <QObject>
#include "../../../DataLayer/ArrayData/I_ArrayData.h"

class MpptGraphingService : public QObject
{
	Q_OBJECT
public:
	explicit MpptGraphingService(const I_ArrayData& arrayData);

private:
	const I_ArrayData& arrayData_; 
};