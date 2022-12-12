#ifndef TRIPPROGRESSWIDGET_H
#define TRIPPROGRESSWIDGET_H

#include <QWidget>
#include <QSqlQueryModel>
#include "TotalHolder.h"
#include <list>

using namespace std;

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

    //iterator that goes through the teams in vector during the souvenir

    double totalCost;

    vector<pair<QString, double>> cityTotal;





private slots:
    void on_pushButton_buy_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_done_clicked();

    void on_pushButton_total_clicked();

private:
    Ui::TripProgressWidget *ui;
};


#endif // TRIPPROGRESSWIDGET_H
