#include "tripprogressDialogue.h"
#include "ui_tripProgressDialogue.h"

TripProgressDialogue::TripProgressDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripProgressDialogue)
{
    ui->setupUi(this);
}

TripProgressDialogue::~TripProgressDialogue()
{
    delete ui;
}
