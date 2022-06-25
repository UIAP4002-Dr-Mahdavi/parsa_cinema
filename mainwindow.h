#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "temp.h"
#include "user.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_log_in_clicked();

    void on_log_out_clicked();

    void on_registration_clicked();

    void on_add_Film_clicked();

    void on_edit_clicked();

    void on_removeFilm_clicked();

    void on_buy_ticket_clicked();

    void on_pushButton_list_clicked();

    void on_pushButton_history_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::MainWindow *ui;
    FILE* fptr;
    bool filecheck;
    user personf;
    bool checkName(user);
    bool checkLogin(user);
};

#endif // MAINWINDOW_H
