#ifndef TRIPPROGRESSWIDGET_H
#define TRIPPROGRESSWIDGET_H

#include <QWidget>
#include <QSqlQueryModel>
#include "tripcreateWidget.h"
#include "TotalHolder.h"

class unordered{
  public:
    int hash(int kay);
    list<int>::iterator find(int key);
    void insert(int key, int val);
    void del(int key);
    void rehashIfNeeded();

  private:
    list<pair<int,int>> *buckets;
    int bucket_size;
    int total_elements;
    float max_load_factor;
};


namespace Ui {
class TripProgressWidget;
}

class TripProgressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TripProgressWidget(QWidget *parent = nullptr);
    ~TripProgressWidget();

    int teamTotal = 0;
    //iterator that goes through the teams in vector during the souvenir




private slots:
    void on_pushButton_buy_clicked();

private:
    Ui::TripProgressWidget *ui;
};


#endif // TRIPPROGRESSWIDGET_H
