#ifndef TRIPSUMMARYWIDGET_H
#define TRIPSUMMARYWIDGET_H

#include <QWidget>

namespace Ui {
class TripSummaryWidget;
}

class TripSummaryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TripSummaryWidget(QWidget *parent = nullptr);
    ~TripSummaryWidget();

private:
    Ui::TripSummaryWidget *ui;
};

#endif // TRIPSUMMARYWIDGET_H
