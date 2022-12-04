#ifndef TRIPPROGRESSDIALOGUE_H
#define TRIPPROGRESSDIALOGUE_H

#include <QDialog>

namespace Ui {
class TripProgressDialogue;
}

class TripProgressDialogue : public QDialogue
{
    Q_OBJECT

public:
    explicit TripProgressDialogue(QWidget *parent = nullptr);
    ~TripProgressDialogue();

private:
    Ui::TripProgressDialogue *ui;
};

#endif // TRIPPROGRESSDIALOGUE_H
