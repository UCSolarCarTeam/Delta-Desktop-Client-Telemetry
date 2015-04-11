#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include <QKeyEvent>
#include <QFontDatabase>
#include <QDebug>
#include "OverlordWidget.h"
#include "../I_SolarCarWindow/I_SolarCarWindow.h"
#include "../EscapeDialog/EscapeDialog.h"

OverlordWidget::OverlordWidget(QList<I_SolarCarWindow*> viewWindows,
                               EscapeDialog* escapeDialog,
                               QWidget *parent)
: QWidget(parent)
, viewWindows_(viewWindows)
, state_("Single")
// , settingsWindow_(settings)
, escapeDialog_(escapeDialog)
{
    escapeDialog_->hide();
    escapeDialog_->setParent(this, Qt::Popup | Qt::CustomizeWindowHint);
    escapeDialog_->move(QApplication::desktop()->screen()->rect().center() 
    					- escapeDialog_->rect().center());

    QVBoxLayout* overlordLayout = new QVBoxLayout;
	setWindowIcon(QIcon(":/Resources/Solar Car Team Icon.ico"));
	
	QTabWidget* tabBar = new QTabWidget();
	overlordLayout->setContentsMargins(0, 0, 0, 0);
	foreach(I_SolarCarWindow* window, viewWindows_){
		tabBar->addTab(window, window->windowTitle());
		window->hideHeaderBar();
	}
    addFonts();

    tabBar->setStyleSheet("QTabBar::tab { height: 40px;\n width: 175px;\nbackground-image: url(:/Resources/MainTitleBar.png);font-family: \"AvenirLTStd\";\nfont-size: 20px;\ncolor: white;"

                          "border: 1px solid rgb(30,30,30);border-left: 1px solid rgb(120,120,120) }");
    setStyleSheet("background-color: rgb(30,30,30);");
    overlordLayout->addWidget(tabBar);
	setLayout(overlordLayout);
    showFullScreen();
}

OverlordWidget::~OverlordWidget()
{
}

void OverlordWidget::keyPressEvent(QKeyEvent * event){
    if (event->key() == Qt::Key_Escape){
        escapeDialog_->show();
        escapeDialog_->setFocus();
    }
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

void OverlordWidget::addFonts(){
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-Black.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-BlackOblique.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-Book.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-BookOblique.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-Heavy.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-HeavyOblique.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-Light.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-LightOblique.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-Medium.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-MediumOblique.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-Oblique.otf");
    QFontDatabase::addApplicationFont(":/Resources/Fonts/AvenirLTStd-Roman.otf");
}

// void OverlordWidget::showSettings()
// {
// }
