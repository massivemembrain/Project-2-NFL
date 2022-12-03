#include "mainwindow.h"
#include "qsqlfootballClass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Initialize football database
    QSqlFootball::initDB();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
