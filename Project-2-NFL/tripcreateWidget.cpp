#include "tripcreateWidget.h"
#include "ui_tripcreateWidget.h"

TripCreateWidget::TripCreateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripCreateWidget)
{
    ui->setupUi(this);
}

TripCreateWidget::~TripCreateWidget()
{
    delete ui;
}
