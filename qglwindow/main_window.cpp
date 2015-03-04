#include "main_window.h"

#include <QAction>
#include <QApplication>
#include <QCloseEvent>
#include <QDockWidget>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPoint>
#include <QSettings>
#include <QSize>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
    createToolbars();
    createDockWidgets();
    createStatusBar();

    loadSettings();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    storeSettings();
    QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{

}

void MainWindow::onNewAction()
{
    // TODO
}

void MainWindow::onOpenAction()
{
    // TODO
}

void MainWindow::onApplicationAbout()
{
    QMessageBox::about(this, tr("About Application"),
                       tr("Qt project template for integrating OpenGL graphic in Qt MainWindow based applications."));
}

void MainWindow::createActions()
{
    mNewAction = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    mNewAction->setShortcuts(QKeySequence::New);
    mNewAction->setStatusTip(tr("mNewAction status tip"));
    connect(mNewAction, SIGNAL(triggered()), this, SLOT(onNewAction()));

    mOpenAction = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    mOpenAction->setShortcuts(QKeySequence::Open);
    mOpenAction->setStatusTip(tr("mOpenAction status tip"));
    connect(mOpenAction, SIGNAL(triggered()), this, SLOT(onOpenAction()));

    mAppAboutAction = new QAction(tr("&About"), this);
    mAppAboutAction->setStatusTip(tr("Show the application's About box"));
    connect(mAppAboutAction, SIGNAL(triggered()), this, SLOT(onApplicationAbout()));

    mQtAboutAction = new QAction(tr("About &Qt"), this);
    mQtAboutAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(mQtAboutAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    mExitAction = new QAction(tr("E&xit"), this);
    mExitAction->setShortcuts(QKeySequence::Quit);
    mExitAction->setStatusTip(tr("Exit the application"));
    connect(mExitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
    mFileMenu = menuBar()->addMenu(tr("&File"));
    mFileMenu->addAction(mNewAction);
    mFileMenu->addAction(mOpenAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mExitAction);

    mHelpMenu = menuBar()->addMenu(tr("&Help"));
    mHelpMenu->addAction(mQtAboutAction);
    mHelpMenu->addAction(mAppAboutAction);
}

void MainWindow::createToolbars()
{
    mFileToolBar = addToolBar(tr("File"));
    mFileToolBar->addAction(mNewAction);
    mFileToolBar->addAction(mOpenAction);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWidgets()
{
    mLeftDockWidget = new QDockWidget(tr("Settings1"), this);
    mLeftDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    mLeftWidget = new QWidget(mLeftDockWidget);
    mLeftDockWidget->setWidget(mLeftWidget);

    mRightDockWidget = new QDockWidget(tr("Settings2"), this);
    mRightDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    mRightWidget = new QWidget(mRightDockWidget);
    mRightDockWidget->setWidget(mRightWidget);

    addDockWidget(Qt::LeftDockWidgetArea, mLeftDockWidget);
    addDockWidget(Qt::RightDockWidgetArea, mRightDockWidget);
}

void MainWindow::loadSettings()
{
    QSettings settings;
    QPoint position = settings.value("main_window/position", QPoint(200, 200)).toPoint();
    QSize size = settings.value("main_window/size", QSize(600, 400)).toSize();

    resize(size);
    move(position);
}

void MainWindow::storeSettings()
{
    QSettings settings;
    settings.setValue("main_window/position", pos());
    settings.setValue("main_window/size", size());
}
