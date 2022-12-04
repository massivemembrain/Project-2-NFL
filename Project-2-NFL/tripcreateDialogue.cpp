#include "tripcreateDialoguee.h"
#include "ui_tripcreateDialogue.h"

TripCreateDialogue::TripCreateDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripCreateDialogue)
{
    ui->setupUi(this);
}

TripCreateDialogue::~TripCreateDialogue()
{
    delete ui;
}
