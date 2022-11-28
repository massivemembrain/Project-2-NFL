#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qsqlfootball.h"
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlFootball db_wrapper;
    /*
     * db_wrapper.getTeams(); => all teams
     * * db_wrapper.getTeams("Chargers", "Team"); => all teams
     * db_wrapper.getTeams("SoFi Stadium", "Name");
     * db_wrapper.getTeams("NFC North", "Division");
     * db_wrapper.getTeams("American Football", "Conference");
     *
     * db_wrapper.getStadiums(); => all stadiums
     * db_wrapper.getStadiums("Retractable", "Roof Type");
     * db_wrapper.getStadiums("Bermuda Grass", "Surface");
     */

    QTableView* team_view = new QTableView(parent);

    QSqlQueryModel* souvenirModel = db_wrapper.getTeamSouvenirs("");
    team_view->setModel(souvenirModel);

    team_view->show();
    //delete souvenirModel;
    //delete team_view;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    adminWindow = new class::Admin;
    adminWindow->show();
}

void MainWindow::on_pushButton_displayWindow_clicked()
{
    d = new class::displayWindow;
    d->show();

}
void MainWindow::on_pushButton_MST_clicked()
{
    mst = new class::MST;
    mst->show();

}
