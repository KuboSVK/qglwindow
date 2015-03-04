#include "main_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("Duraj");
    a.setApplicationName("qglviewer");

    MainWindow w;
    w.show();

    return a.exec();
}
