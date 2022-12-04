#ifndef TRIPPROGRESSWIDGET_H
#define TRIPPROGRESSWIDGET_H

#include <QWidget>

namespace Ui {
class TripProgressWidget;
}

class TripProgressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TripProgressWidget(QWidget *parent = nullptr);
    ~TripProgressWidget();

private:
    Ui::TripProgressWidget *ui;
};

#endif // TRIPPROGRESSWIDGET_H
