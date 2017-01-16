#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifdef QT_DEBUG
#include "qdebug.h"
#endif

#include <QPixmap>
#include <QFile>
#include <QMessageBox>

#include <QStyle>
#include <QDesktopWidget>
#include <sstream>

#include <QKeyEvent>

#define MAX_WEIGHT          50
#define MIN_WEIGHT          1

#define STARTING_TIME       59 * 1000 //59s
#define EXERCISE_TIMER_STEP           125

#define PROGRESS_STEP       14/1000

#define BALL_HALF_HEIGHT    24.5
#define WAVE_HALF_HEIGHT    128.5


//----------------------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //start app btn
    start_app_btn = new KLabel("",this);
    start_app_btn->setGeometry(QRect(410,480,204,73));
    start_app_btn->setStyleSheet("background-image: url(:/p1/res/signin_btn.png);");
    connect(start_app_btn,SIGNAL(clicked()),this,SLOT(start_up_clicked()));

    //inits
    exercising = false;
    weight = 1;
    loops_count = 0;
    app_started = false;

    ui->training_progress->setVisible(false);

    //scroll up btn
    scrollup_btn = new KLabel("",this);
    scrollup_btn->setGeometry(QRect(1270,196,41,35));
    scrollup_btn->setStyleSheet("background-image: url(:/p1/res/up0.png);");
    connect(scrollup_btn,SIGNAL(clicked()),this,SLOT(scroll_up_clicked()));

    //scroller
    scroller = new DragablePart("",this);
    scroller->setGeometry(QRect(1270,432,41,35));
    scroller->setStyleSheet("background-image: url(:/p1/res/pos0.png);");
    scroller->setDragVerticalLimits(229,631);
    connect(scroller,SIGNAL(ValueChanged(double)),this,SLOT(scroller_value_changed(double)));

    //scroll down btn
    scrolldn_btn = new KLabel("",this);
    scrolldn_btn->setGeometry(QRect(1270,665,41,35));
    scrolldn_btn->setStyleSheet("background-image: url(:/p1/res/down0.png);");
    connect(scrolldn_btn,SIGNAL(clicked()),this,SLOT(scroll_dn_clicked()));

    //clock icon
    QPixmap pix(":/p1/res/clock.png");
    ui->clock->setPixmap(pix.scaled(60,60,Qt::KeepAspectRatio));

    //logout btn
    logout_btn = new KLabel("",this);
    logout_btn->setGeometry(QRect(850,40,154,63));
    logout_btn->setStyleSheet("background-image: url(:/p1/res/signout.png);");
    connect(logout_btn,SIGNAL(clicked()),this,SLOT(logout_btn_clicked()));

    //+ btn
    more_weight = new KLabel("",this);
    more_weight->setGeometry(QRect(890,240,112,112));
    more_weight->setStyleSheet("background-image: url(:/p1/res/+.png);");
    connect(more_weight,SIGNAL(clicked()),this,SLOT(more_weight_clicked()));

    //- btn
    less_weight = new KLabel("",this);
    less_weight->setGeometry(QRect(890,505,112,112));
    less_weight->setStyleSheet("background-image: url(:/p1/res/-.png);");
    connect(less_weight,SIGNAL(clicked()),this,SLOT(less_weight_clicked()));

    //start / stop btn
    start_btn = new KLabel("",this);
    start_btn->setGeometry(QRect(760,690,244,66));
    start_btn->setStyleSheet("background-image: url(:/p1/res/start_exercice.png);");
    connect(start_btn,SIGNAL(clicked()),this,SLOT(start_btn_clicked()));

    //animation
    anim1 = new GLAnim(this,865,485);
    anim1->setGeometry(QRect(5000,165,865,485));//set it away from screen
    anim1->anim_speed = (double) 1 / (7 * 1000);

    /* timers */

    //exercice timer
    exercice_timer = new QTimer(this);
    exercice_timer->setInterval(EXERCISE_TIMER_STEP);
    connect(exercice_timer,SIGNAL(timeout()),this,SLOT(timer1_func()));

    //user performance timer
    perftimer1 = new PerfTimer();
  //perftimer1->setInterval(PERF_TIMER_STEP);
    perftimer1->TimeSpentLabel = ui->time_spent;//for printout
    perftimer1->LastTimeLabel = ui->last_time;//for printout
    perftimer1->OverTimeLabel = ui->target_time;//for printout
    connect(perftimer1,SIGNAL(perfect_timing_report()),anim1,SLOT(perfect_timing_report()));


    logout_btn_clicked();
}

//----------------------------------------
void MainWindow::start_up_clicked()
{
#ifdef QT_DEBUG
    qDebug() << "start app click";
#endif

    app_started = true;
    //anim1->initializeGL();
    ui->g1->setStyleSheet("background-image: url(:/p1/res/1.png);");
    ui->label->show();
    ui->training_title->show();
    ui->training_progress->show();
    ui->training_status->show();
    ui->sek->show();
    ui->time->show();
    ui->weight_label->show();
    ui->loops_counter->show();
    ui->kg->show();
    ui->name->show();
    ui->star->show();
    ui->hardware_controls_label->show();
    ui->sensor1->show();
    ui->scroller_bgn->show();
    ui->scroller_ticks->show();
    ui->lever_pos->show();
    ui->lever_pos_2->show();
    ui->time_spent->show();
    start_btn->show();
    anim1->setGeometry(QRect(5,165,865,485));//set it back to the scren
    less_weight->show();
    more_weight->show();
    logout_btn->show();
    ui->clock->show();
    scrollup_btn->show();
    scrolldn_btn->show();
    scroller->show();
    start_app_btn->hide();
}
//----------------------------------------
void MainWindow::logout_btn_clicked()
{
    app_started = false;
    this->setFixedWidth(1021);
    ui->g1->setStyleSheet("background-image: url(:/p1/res/0.png);");
    ui->label->hide();
    ui->training_title->hide();
    ui->training_progress->hide();
    ui->training_status->hide();
    ui->sek->hide();
    ui->time->hide();
    ui->weight_label->hide();
    ui->loops_counter->hide();
    ui->kg->hide();
    ui->name->hide();
    ui->star->hide();
    ui->hardware_controls_label->hide();
    ui->sensor1->hide();
    ui->scroller_bgn->hide();
    ui->scroller_ticks->hide();
    ui->lever_pos->hide();
    ui->lever_pos_2->hide();
    ui->time_spent->hide();

    start_btn->hide();

    less_weight->hide();
    more_weight->hide();
    logout_btn->hide();
    ui->clock->hide();
    scrollup_btn->hide();
    scrolldn_btn->hide();
    scroller->hide();
    start_app_btn->show();
    anim1->setGeometry(QRect(5000,165,865,485));//set it back to the scren

    if(exercising)
    {
        StopExcercice();
    }

    CenterApp();
}
//----------------------------------------
void MainWindow::StartExcercice()
{
    exercice_timer->start();
    anim1->Start();

    exercice_remaining_time = STARTING_TIME;
    exercising = true;
    loops_count = 0;
    start_btn->setStyleSheet("background-image: url(:/p1/res/end_exercice.png);");
    ui->training_progress->setVisible(true);
    ui->training_status->setText(QString("Training"));
    perftimer1->Start();
}
//----------------------------------------
void MainWindow::StopExcercice()
{
    exercice_timer->stop();
    anim1->Stop();

    exercice_remaining_time = 0;
    exercising = false;
    start_btn->setStyleSheet("background-image: url(:/p1/res/start_exercice.png);");
    ui->training_progress->setVisible(false);
    ui->training_status->setText(QString("Pause"));
    perftimer1->Stop();
}
//----------------------------------------
void MainWindow::start_btn_clicked()//start / stop exercice
{
    if(exercising)
    {
        StopExcercice();
    }else
    {
        StartExcercice();
    }

    UpdateExerciceTime();
}
//----------------------------------------
void MainWindow::more_weight_clicked()// + btn
{
    if(weight < MAX_WEIGHT)
        weight += 1;

    UpdateWeight();
}
//----------------------------------------
void MainWindow::less_weight_clicked()// - btn
{
    if(weight > MIN_WEIGHT)
        weight -= 1;

    UpdateWeight();
}
//----------------------------------------
void MainWindow::UpdateWeight()// display current weight
{
    ui->weight_label->setText(QString::number(weight));
}
//----------------------------------------
void MainWindow::timer1_func()//exercice timer
{
    if(exercice_remaining_time == 0)
    {  
        StopExcercice();

    }else
    {        
        exercice_remaining_time -= EXERCISE_TIMER_STEP;
        UpdateExerciceTime();
    }
#ifdef QT_DEBUG
    qDebug() << "Update...";
#endif
}
//----------------------------------------
void MainWindow::UpdateExerciceTime()
{
    ui->training_progress->setFixedWidth(exercice_remaining_time * PROGRESS_STEP);
    ui->time->setText( QString::number(exercice_remaining_time / 1000));
}
//----------------------------------------
void MainWindow::scroller_value_changed(double value)//sensor 1 scroller
{
    int going_up = 0;
    double new_y = ((100 - value) * 2.28) + WAVE_HALF_HEIGHT - BALL_HALF_HEIGHT;

    if( new_y > anim1->ball_y )
        going_up = 1;//up

    if( new_y < anim1->ball_y )
        going_up = -1;//down

    if(going_up != 0)
    if(perftimer1->up != going_up)//sens changed
    {
        perftimer1->up = going_up;
        perftimer1->FlipSens();
        loops_count++;
        ui->loops_counter->setText("x"+QString::number(loops_count / 2));
       // perftimer1->Reset();
    }

    anim1->ball_y = new_y;
    ui->lever_pos->setText(QString::number(value,'f',2)+"%");

#ifdef QT_DEBUG
    qDebug() << "scroller val changed";
#endif
}
//----------------------------------------
void MainWindow::scroll_up_clicked()
{
    scroller->scroll_up();
}
//----------------------------------------
void MainWindow::scroll_dn_clicked()
{
    scroller->scroll_down();
}
//----------------------------------------
void MainWindow::on_actionExit_triggered()//close app
{
    qApp->quit();
}
//----------------------------------------
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox Msgbox;

    Msgbox.setText("\nEgym demo 1 task 2     \n\nby Djibril Djeradi 2017        \n");
    Msgbox.exec();
}
//----------------------------------------
void MainWindow::on_actionLoad_texture_now_triggered()
{
}
//----------------------------------------
void MainWindow::on_actionRepaint_OpenGL_triggered()
{
    anim1->paintGL();
    anim1->repaint();
}
//----------------------------------------
void MainWindow::on_actionShow_hardware_Controls_triggered()//show / hide hardware controlls
{
   if(this->width() < 1532)
   {
        ui->actionShow_hardware_Controls->setText("Hide Hardware controls");
        setFixedWidth(1532);
   }
   else
   {
        ui->actionShow_hardware_Controls->setText("Show Hardware controls");
        setFixedWidth(1021);
   }

   CenterApp();
}
//----------------------------------------
void MainWindow::CenterApp()
{
   //center app in screen
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
}
//----------------------------------------
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F1)
    {
        if(app_started)
            on_actionShow_hardware_Controls_triggered();
    }
}
//----------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
