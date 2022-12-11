#ifndef TRIPPROGRESSWIDGET_H
#define TRIPPROGRESSWIDGET_H

#include <QWidget>
#include <QSqlQueryModel>


namespace Ui {
class TripProgressWidget;
}

class TripProgressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TripProgressWidget(QWidget *parent = nullptr);
    ~TripProgressWidget();

private slots:
    void on_pushButton_buy_clicked();

private:
    Ui::TripProgressWidget *ui;
};

#endif // TRIPPROGRESSWIDGET_H
