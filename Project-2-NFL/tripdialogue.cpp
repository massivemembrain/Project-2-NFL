#include "tripdialogue.h"
#include "ui_tripdialogue.h"

TripDialogue::TripDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripDialogue)
{
    ui->setupUi(this);
}

TripDialogue::~TripDialogue()
{
    delete ui;
}
