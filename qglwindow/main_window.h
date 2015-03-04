#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

// forward declaration(s)
QT_FORWARD_DECLARE_CLASS(QAction)
QT_FORWARD_DECLARE_CLASS(QCloseEvent)
QT_FORWARD_DECLARE_CLASS(QDockWidget)
QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(QToolBar)
QT_FORWARD_DECLARE_CLASS(QWidget)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void onNewAction();
    void onOpenAction();
    void onApplicationAbout();

private:
    void createActions();
    void createMenus();
    void createToolbars();
    void createStatusBar();
    void createDockWidgets();

    void loadSettings();
    void storeSettings();

    QAction* mNewAction;
    QAction* mOpenAction;
    QAction* mAppAboutAction;
    QAction* mQtAboutAction;
    QAction* mExitAction;

    QMenu* mFileMenu;
    QMenu* mHelpMenu;

    QToolBar* mFileToolBar;

    QDockWidget* mLeftDockWidget;
    QDockWidget* mRightDockWidget;

    QWidget* mLeftWidget;
    QWidget* mRightWidget;
};

#endif // MAIN_WINDOW_H
