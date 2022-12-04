#include "tripWindow.h"
#include "ui_tripWindow.h"

TripWindow::TripWindow(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::TripWindow)
{
    ui->setupUi(this);
}

TripWindow::~TripWindow()
{
    delete ui;
}
