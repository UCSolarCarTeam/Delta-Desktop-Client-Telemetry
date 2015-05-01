#pragma once

#include <QObject>
class I_ArrayData;

class MpptPresenter : public QObject
{
	Q_OBJECT
public:
	explicit MpptPresenter(const I_ArrayData& arrayData);

private:
	void relayArrayData();

	const I_ArrayData& arrayData_;

signals: 
};