#include "tripprogressWidget.h"
#include "ui_tripprogressWidget.h"

TripProgressWidget::TripProgressWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripProgressWidget)
{
    ui->setupUi(this);
}

TripProgressWidget::~TripProgressWidget()
{
    delete ui;
}
