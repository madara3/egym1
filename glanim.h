#ifndef GLANIM_H
#define GLANIM_H

#include <QList>
#include "ktexture.h"
#include "tracepoint.h"
#include <QTimer>
#include <QTime>

class GLAnim : public QGLWidget
{
    Q_OBJECT

public:
    int init_status; //0 = not initialized , 1 initializing , 2 initialized
    bool enabled;
    double anim_speed;
    double ball_x,ball_y;
    bool greetings_top,greetings_bottom;

    GLAnim(QWidget* parent = 0,int w = 0, int h = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);
    void AddTexture(QString name,double x,double y,int fade_mode = 0,int fade_status = 0, double opacity = 1);

    void Start();
    void Stop();

    ~GLAnim();

private slots:
    void perfect_timing_report();// 2 notify of perfect timing
    void anim_timer_func();

private:
    int width,height;
    int textures_count;
    KTexture* textures[10];
    QList<TracePoint*> Trace;
    void DrawBallTrace();

    QTime myTime;
    int elapsed_time_from_last_draw;

    QTimer* draw_timer;
};

#endif // GLANIM_H
