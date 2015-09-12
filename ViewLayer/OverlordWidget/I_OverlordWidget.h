#pragma once

class I_OverlordWidget
{
public:
	virtual ~I_OverlordWidget() {}

    virtual void keyPressEvent(QKeyEvent * event) = 0;
    virtual QString changeState() = 0;
    virtual QString getState() = 0;
    virtual void addFonts() = 0;
    // virtual void showSettings() = 0;
};
