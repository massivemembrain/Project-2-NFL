#ifndef TRIPCREATEDIALOGUE_H
#define TRIPCREATEDIALOGUE_H

#include <QDialog>

namespace Ui {
class TripCreateDialogue;
}

class TripCreateDialogue : public QWidget
{
    Q_OBJECT

public:
    explicit TripCreateDialogue(QWidget *parent = nullptr);
    ~TripCreateDialogue();

private:
    Ui::TripCreateDialogue *ui;
};

#endif // TRIPCREATEDIALOGUE_H
