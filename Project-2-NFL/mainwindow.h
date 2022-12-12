#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include "admin.h"
#include"displayWindow.h"
#include"mst.h"
#include "bfs.h"
#include "dfs.h"
#include "travelplanClass.h"
#include "login_mainwindow.h"
#include "shortestDistance.h"
#include "dijkstra.h"
#include "tripprogressWidget.h"
#include "orderedtrip.h"
#include "plantrip.h"
/*****************************************************************//**
 * \file   mainwindow.h
 * \brief  our MainWindow
 *
 *
 * \date   December 2022
 *********************************************************************/

QT_BEGIN_NAMESPACE
/**
 *  \namespace Ui
 */
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * \class MainWindow
 * \public QMainWindow
 * \brief our main window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); /*!< constructor*/
    ~MainWindow(); /*!< destructor */

//public slots:
//    void on_login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_displayWindow_clicked();

    void on_pushButton_MST_clicked();

    void on_pushButton_BFS_clicked();

    void on_pushButton_trip_clicked();


    void on_pushButton_DFS_clicked();

    void on_pushButton_shortdist_clicked();

    void on_pushButton_dijkstra_clicked();

    void on_pushButton_souvenir_clicked();

    void on_pushButton_orderTrip_clicked();

    void on_pushButton_customTrip_clicked();


private:
    Ui::MainWindow *ui; /*!< an Ui variable*/
    //Admin* adminWindow = NULL;
    displayWindow* d = NULL; /*!< displayWindow object*/

    MST* mst= NULL; /*!< MST object*/
    BFS* bfs = NULL; /*!< BFS object*/
    DFS* dfs = NULL; /*!< DFS object*/

    Login* login = NULL; /*!< Login object*/

    QStackedWidget* tripWindow = NULL; /*!< QStackedWidget object*/
    TravelPlan* plan = nullptr; /*!< TravelPlan object*/

    Dijkstra* dij = NULL; /*!< Dijkstra object*/


    shortestDistance* sh = NULL; /*!< shortestDistance object*/

    TripProgressWidget * t = NULL;

    OrderedTrip * ordered = NULL;

    planTrip* planTrip = NULL;



};
#endif // MAINWINDOW_H
