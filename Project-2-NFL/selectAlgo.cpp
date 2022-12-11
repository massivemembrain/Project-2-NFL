#include "selectAlgo.h"
#include "ui_selectAlgo.h"

selectAlgo::selectAlgo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectAlgo)
{
    ui -> setupUi(this);
}

selectAlgo::~selectAlgo()
{
    delete ui;
}

//void selectAlgo::on_pushButton_go_clicked()
//{
//    plan = new TravelPlan;
//}

//void selectAlgo::on_go_clicked()
//{
//    custom = new TripCreateWidget;
//    custom->show();
//}

