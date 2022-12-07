#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <QSqlQueryModel>

/*****************************************************************//**
 * \file   displayWindow.h
 * \brief  displayWindow object to to display things
 *
 *
 * \date   December 2022
 *********************************************************************/

/**
 *  \namespace Ui
 */
namespace Ui
{
   class displayWindow;
}

/**
 * \class displayWindow
 * \public QWidget
 * \brief displayWindow that display all display requirements
 */
class displayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit displayWindow(QWidget *parent = nullptr); /*!< constructor*/
    ~displayWindow(); /*!< destructor */


private:
    Ui::displayWindow *ui; /*!< an Ui variable*/

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
    void on_pushButton_displaySouvenir_clicked();
    void on_pushButton_totalseatcapacity_clicked();
    void on_pushButton_bermudaGrass_clicked();
};

#endif // DISPLAYWINDOW_H
