#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "kpart.h"
#include "klabel.h"
#include "glanim.h"
#include "perftimer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void timer1_func();

private slots:
    void more_weight_clicked();
    void less_weight_clicked();
    void logout_btn_clicked();
    void start_btn_clicked();
    void scroller_value_changed(double value);
    void scroll_up_clicked();
    void scroll_dn_clicked();

    void on_actionExit_triggered();
    void on_actionAbout_triggered();

    void on_actionLoad_texture_now_triggered();
    void on_actionRepaint_OpenGL_triggered();

    void start_up_clicked();

    void on_actionShow_hardware_Controls_triggered();

private:

    Ui::MainWindow *ui;
    KLabel* start_app_btn;

    QTimer* exercice_timer;
    KLabel* scrollup_btn;
    KLabel* scrolldn_btn;
    DragablePart* scroller;
    KLabel* logout_btn;
    KLabel* start_btn;
    KLabel* more_weight;
    KLabel* less_weight;
    GLAnim* anim1;

    PerfTimer* perftimer1;

private:
    int loops_count; //loops user did in exercice
    bool exercising;
    int weight;
    int exercice_remaining_time;
    void UpdateWeight();
    void UpdateExerciceTime();
    void StartExcercice();
    void StopExcercice();

    void CenterApp();
};

#endif // MAINWINDOW_H
