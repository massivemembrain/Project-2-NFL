#include "tripsummaryWidget.h"
#include "ui_tripsummaryWidget.h"

TripSummaryWidget::TripSummaryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripSummaryWidget)
{
    ui->setupUi(this);
}

TripSummaryWidget::~TripSummaryWidget()
{
    delete ui;
}
