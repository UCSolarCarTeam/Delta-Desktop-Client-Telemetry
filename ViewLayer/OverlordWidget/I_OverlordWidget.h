#pragma once

class I_OverlordWidget
{
public:
	virtual ~I_OverlordWidget() {}

    virtual QString changeState() = 0;
    virtual QString getState() = 0;
    // virtual void showSettings() = 0;
};