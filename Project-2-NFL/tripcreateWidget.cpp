#include "tripcreateWidget.h"
#include "ui_tripcreateWidget.h"

TripCreateWidget::TripCreateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripCreateWidget)
{
    ui->setupUi(this);
    ui->planType->addItem("Selected Order");
    ui->planType->addItem("Shortest Order");
}

TripCreateWidget::~TripCreateWidget()
{
    delete ui;
}

void TripCreateWidget::on_proceedButtons_accepted()
{

}


void TripCreateWidget::on_proceedButtons_rejected()
{
    close();
    parentWidget()->close();
}

