#include "perftimer.h"
#include<qobject.h>

#ifdef QT_DEBUG
#include "qdebug.h"
#endif

#define TARGET_TIME 1500
#define REPORT_TIME_STEP 1500
#define INC_TIME_STEP 50

//--------------------------------------
PerfTimer::PerfTimer()
{
    t1 = new QTimer(this);
    t2 = new QTimer(this);

    t1->setInterval(REPORT_TIME_STEP);
    t2->setInterval(INC_TIME_STEP);

    up = 0;

    time_spent = extra_time = over_time = 0;
    QObject::connect(t1,SIGNAL(timeout()),this,SLOT(perf_report_func()));
    QObject::connect(t2,SIGNAL(timeout()),this,SLOT(perf_inc_time_func()));

#ifdef QT_DEBUG
    qDebug() << "Perf timer created";
#endif
}
//--------------------------------------
void PerfTimer::Start()
{
    time_spent = extra_time = 0;
    t1->start();
    t2->start();

#ifdef QT_DEBUG
    qDebug() << "Perf timer started";
#endif
}
//--------------------------------------
void PerfTimer::Stop()
{
    time_spent = extra_time = 0;
    t1->stop();
    t2->stop();

#ifdef QT_DEBUG
    qDebug() << "Perf timer stoped";
#endif
}
//--------------------------------------
void PerfTimer::Reset()
{
  time_spent = 0;

#ifdef QT_DEBUG
    qDebug() << "Perf timer reset";
#endif
}
//--------------------------------------
int PerfTimer::GetExtraTime()
{
    return(time_spent - 1500);
}
//--------------------------------------
int PerfTimer::GetSpentTime()
{
    return(time_spent);
}
//--------------------------------------
void PerfTimer::FlipSens()
{
    over_time = time_spent - TARGET_TIME;

    LastTimeLabel->setText("last time: "+QString::number(time_spent) + "ms");
    OverTimeLabel->setText("over time: "+QString::number(time_spent - TARGET_TIME) + "ms");
    time_spent = 0;

    if( over_time >= -100 && over_time <= 100 )
    {
        emit perfect_timing_report();
    }

#ifdef QT_DEBUG
    qDebug() << "Perf timer flip";
#endif
}
//--------------------------------------
void PerfTimer::perf_report_func()
{
#ifdef QT_DEBUG
    qDebug() << "perf report func";
#endif
}
//--------------------------------------
void PerfTimer::perf_inc_time_func()
{
    time_spent += INC_TIME_STEP;
    TimeSpentLabel->setText("time: "+QString::number(time_spent)+" ms");

#ifdef QT_DEBUG
    qDebug() << "perf inc func";
#endif
}
