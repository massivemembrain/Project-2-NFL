#ifndef TRIPCREATEWIDGET_H
#define TRIPCREATEWIDGET_H

#include <QWidget>

namespace Ui {
class TripCreateWidget;
}

class TripCreateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TripCreateWidget(QWidget *parent = nullptr);
    ~TripCreateWidget();

private:
    Ui::TripCreateWidget *ui;
};

#endif // TRIPCREATEWIDGET_H
