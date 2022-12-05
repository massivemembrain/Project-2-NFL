#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include "admin.h"
#include"displayWindow.h"
#include"mst.h"
#include "bfs.h"
#include "travelplanClass.h"
#include "login.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_displayWindow_clicked();

    void on_pushButton_MST_clicked();

    void on_pushButton_BFS_clicked();

    void on_pushButton_trip_clicked();

private:
    Ui::MainWindow *ui;
    Admin* adminWindow = NULL;
    displayWindow* d = NULL;
    MST* mst= NULL;

    BFS* bfs = NULL;

    Login* login = NULL;

    QStackedWidget* tripWindow = NULL;
    TravelPlan* plan = nullptr;
};
#endif // MAINWINDOW_H
