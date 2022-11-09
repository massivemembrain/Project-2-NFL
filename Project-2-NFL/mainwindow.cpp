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
    QTableView* team_view = new QTableView(parent);
    team_view->setModel(db_wrapper.getTeams());
    team_view->show();
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

