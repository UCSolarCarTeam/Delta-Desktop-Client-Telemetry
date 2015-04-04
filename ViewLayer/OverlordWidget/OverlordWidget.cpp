#include <QVBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include "OverlordWidget.h"
#include "../I_SolarCarWindow/I_SolarCarWindow.h"

OverlordWidget::OverlordWidget(QList<I_SolarCarWindow*> viewWindows,
							   QWidget *parent)
: QWidget(parent)
, viewWindows_(viewWindows)
, state_("Single")
// , settingsWindow_(settings)
// , escWindow_(escWindow)
{
	QVBoxLayout* overlordLayout = new QVBoxLayout;
	setWindowIcon(QIcon(":/Resources/Solar Car Team Icon.ico"));
	QTabWidget* tabBar = new QTabWidget();
	overlordLayout->setContentsMargins(0, 0, 0, 0);
	foreach(I_SolarCarWindow* window, viewWindows_){
		tabBar->addTab(window, window->windowTitle());
		window->hideHeaderBar();
	}
    tabBar->setStyleSheet("QTabBar::tab { height: 40px;\n width: 175px;\nbackground-image: url(:/Resources/MainTitleBar.png);\nfont-size: 20px;\ncolor: white;"
                          "border: 1px solid rgb(30,30,30);border-left: 1px solid rgb(120,120,120) }");
    setStyleSheet("background-color: rgb(30,30,30);");
    overlordLayout->addWidget(tabBar);
	setLayout(overlordLayout);
    showFullScreen();
}

OverlordWidget::~OverlordWidget()
{
}

QString OverlordWidget::changeState()
{
	if(state_ .compare("Single") == 0){
		state_ = "Multi";
	}
	else if(state_.compare("Multi") == 0){
		state_ = "Single";
	}
	return state_;
}

QString OverlordWidget::getState()
{
	return state_;
}

// void OverlordWidget::showSettings()
// {
// }
