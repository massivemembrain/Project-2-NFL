#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H


#include <QWidget>
#include <QSqlQueryModel>

namespace Ui
{
   class displayWindow;
}

class displayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit displayWindow(QWidget *parent = nullptr);
    ~displayWindow();

private:
    Ui::displayWindow *ui;

private slots:
    void on_pushButton_selectTeam_clicked();
    void on_pushButton_displayTeam_clicked();
    void on_pushButton_displayStadium_clicked();
    void on_pushButton_AFC_clicked();
    void on_pushButton_NFC_clicked();
    void on_pushButton_NFCNORTH_clicked();
    void on_pushButton_openRoof_clicked();
    void on_pushButton_stadiumByDate_clicked();
    void on_pushButton_stadiumByCapacity_clicked();
    void on_pushButton_teamsByConf_clicked();
};

#endif // DISPLAYWINDOW_H
