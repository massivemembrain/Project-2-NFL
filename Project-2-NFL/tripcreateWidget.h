#ifndef TRIPCREATEWIDGET_H
#define TRIPCREATEWIDGET_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>



namespace Ui {
class TripCreateWidget;
}

class TripCreateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TripCreateWidget(QWidget *parent = nullptr);
    ~TripCreateWidget();

    void fullMap(QString start, int numberOfCities);

    void selectedAlgorithm();


    int count = 1;
    int addCity = 0;
    int nextCityCheck;
    bool notClicked = true;
    bool customTripNotClicked = true;


private slots:
    void on_proceedButtons_accepted();

    void on_proceedButtons_rejected();

    void on_pushButton_select_clicked();

    void on_pushButton_done_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::TripCreateWidget *ui;

    QSqlDatabase myDb;
};

#endif // TRIPCREATEWIDGET_H
