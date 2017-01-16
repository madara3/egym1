#ifndef PERFTIMER_H
#define PERFTIMER_H

#include <QTimer>
#include "Qlabel.h"

class PerfTimer: public QObject
{
    Q_OBJECT

public:
    int ball_y;
    int up;
    QLabel* TimeSpentLabel;//just a pointer
    QLabel* LastTimeLabel;//just a pointer
    QLabel* OverTimeLabel;//just a pointer

private:
    QTimer* t1;
    QTimer* t2;

    int count;

    int time_spent;
    int extra_time;
    int over_time;

private slots:
    void perf_report_func();
    void perf_inc_time_func();

signals:
    void perfect_timing_report();

public:
    PerfTimer();

    void Start();
    void Stop();
    void Reset();

    int GetExtraTime();
    int GetSpentTime();

    void FlipSens();
};

#endif // PERFTIMER_H
