#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H

#include <QStackedWidget>

namespace Ui {
class TripWindow;
}

class TripWindow : public QStackedWidget
{
    Q_OBJECT

public:
    explicit TripWindow(QWidget *parent = nullptr);
    ~TripWindow();

private:
    Ui::TripWindow *ui;
};

#endif // TRIPWINDOW_H
