#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include <QKeyEvent>
#include <QFontDatabase>
#include <QDir>
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
    setupEscapeDialog();

    QTabWidget* tabBar = createTabWidget();

    escapeDialog_->setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout* overlordLayout = new QVBoxLayout;
    overlordLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(overlordLayout);
    setWindowIcon(QIcon(":/Resources/Solar Car Team Icon.ico"));
    setStyleSheet("background-color: rgb(30,30,30);");

    overlordLayout->addWidget(tabBar);

    addFonts();

    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    showFullScreen();
}

OverlordWidget::~OverlordWidget()
{
}

void OverlordWidget::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Escape){
        escapeDialog_->show();
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
    QDir fontDirectory = QDir(":/Resources/Fonts/");

    QStringList fonts =  fontDirectory.entryList();
    foreach(QString font, fonts){
        QFontDatabase::addApplicationFont(":/Resources/Fonts/" + font);
    }
}
void OverlordWidget::setupEscapeDialog()
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    escapeDialog_->resize(width, height);
    escapeDialog_->hide();
    escapeDialog_->setParent(this, Qt::Popup | Qt::CustomizeWindowHint);
    escapeDialog_->move(QApplication::desktop()->screen()->rect().center()
                        - escapeDialog_->rect().center());
}

QTabWidget* OverlordWidget::createTabWidget()
{
    QTabWidget* tabBar = new QTabWidget();
    foreach(I_SolarCarWindow* window, viewWindows_){
        tabBar->addTab(window, window->windowTitle());
        window->hideHeaderBar();
    }
    tabBar->setStyleSheet("QTabBar::tab { height: 40px;\n width: 175px;\nbackground-image: url(:/Resources/MainTitleBar.png);font-family: \"AvenirLTStd\";\nfont-size: 20px;\ncolor: white;"

                          "border: 1px solid rgb(30,30,30);border-left: 1px solid rgb(120,120,120) }");
    return tabBar;
}

// void OverlordWidget::showSettings()
// {
// }
