#ifndef TRIPDIALOGUE_H
#define TRIPDIALOGUE_H

#include <QDialog>

namespace Ui {
class TripDialogue;
}

class TripDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit TripDialogue(QWidget *parent = nullptr);
    ~TripDialogue();

private:
    Ui::TripDialogue *ui;
};

#endif // TRIPDIALOGUE_H
