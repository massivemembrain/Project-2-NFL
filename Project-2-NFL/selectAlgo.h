#ifndef SELECTALGO_H
#define SELECTALGO_H

#include <iostream>
#include <iomanip>
#include <QWidget>
#include <QString>
#include <QObject>
#include <QDebug>
#include "ui_selectAlgo.h"
#include "travelplanClass.h"

namespace Ui
{
    class selectAlgo;
}

class selectAlgo : public QWidget
{
    Q_OBJECT
public:
    explicit selectAlgo(QWidget *parent = nullptr);
    ~selectAlgo();

private slots:
    void on_pushButton_go_clicked();

private:
    Ui::selectAlgo *ui;
    QStackedWidget* tripWindow = NULL;
    TravelPlan* plan = nullptr;

};

#endif // SELECTALGO_H
