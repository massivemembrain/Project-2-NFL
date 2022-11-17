#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "admin.h"
#include"displayWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_displayWindow_clicked();

private:
    Ui::MainWindow *ui;
    Admin* adminWindow = NULL;
    displayWindow* d = NULL;

};
#endif // MAINWINDOW_H
