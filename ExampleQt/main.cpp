#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; // Create a MainWindow
    w.show(); // Set it as visible
    return a.exec(); // Enter the event loop
}
