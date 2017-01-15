#include "glanim.h"
#include <gl/GLU.h>

#ifdef QT_DEBUG
#include "qdebug.h"
#endif

#define BALL_HALF_SIZE  24.5
#define DRAW_TIMER_INTERVAL 5 // 40 FPS 25ms each

//-------------------------------------
void test_gl_error()
{
    GLenum err = glGetError();
#ifdef QT_DEBUG
    if(err != 0)
        qDebug() << "error gl: "+QString::number(err);
#endif
}
//-------------------------------------
GLAnim::GLAnim(QWidget* parent,int w, int h) : QGLWidget(parent)
{
    init_status = 0;
    enabled = false;
    width = w;
    height = h;
    textures_count = 0;
    anim_speed = 0;
    ball_x = 408;
    ball_y = 218;

    greetings_top = greetings_bottom = true;

    //anim timer
    draw_timer = new QTimer(this);
    draw_timer->setInterval(DRAW_TIMER_INTERVAL);
    connect(draw_timer,SIGNAL(timeout()),this,SLOT(anim_timer_func()));

    elapsed_time_from_last_draw = 0;
}
//-------------------------------------
void GLAnim::initializeGL()
{
    if(init_status > 0)
        return;
#ifdef QT_DEBUG
    qDebug() << "init gl " + QString::number(width)+" x "+ QString::number(height) ;
#endif
    init_status = 1;

    glClearColor(0.2,0.2,0.2,1);
    glViewport(0,0,width,height);

    glMatrixMode(GL_MODELVIEW);    
    glLoadIdentity();

    gluOrtho2D(0, width, 0, height);
    glDisable(GL_DEPTH_TEST);

    //load textures
    AddTexture(":/p1/res/2.png",0,0);//0
    AddTexture(":/p1/res/wave.png",0,128.5);//1
    textures[1]->SetTx(0.11);//fixes the waves pos
    AddTexture(":/p1/res/ball.png",0,218);//2
    AddTexture(":/p1/res/2mask.png",0,0);//3

    AddTexture(":/p1/res/plus.png",ball_x + 60,380,1,0,0);//4

    /*QGLFormat myFormat;// = new QGLFormat();
    myFormat.setDoubleBuffer(true);
    this->context()->setFormat(myFormat);*/

  //  TracePoint* t = new TracePoint();
   // Trace.append(t);
    init_status = 2;
#ifdef QT_DEBUG
    qDebug() << "init gl ended";
#endif
}
//----------------------------------------
void GLAnim::anim_timer_func()
{
#ifdef QT_DEBUG
    qDebug() << "calling paint gl";
#endif

    paintGL();
    swapBuffers();
}
//-------------------------------------
void GLAnim::paintGL()
{
    elapsed_time_from_last_draw = myTime.elapsed() ;//- elapsed_time_from_last_draw;
    myTime.restart();

#ifdef QT_DEBUG
    qDebug() << "paint gl";
#endif

    if(textures_count == 0)
        return;

    this->makeCurrent();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0f,1.0f,1.0f,1.0f);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glEnable(GL_TEXTURE_2D);

        //bgn
        textures[0]->Paint();

        //waves
        if(enabled)
        {
            textures[1]->MoveTextureLeft(anim_speed * elapsed_time_from_last_draw);
        }
        textures[1]->Paint();

        //bgn mask
        textures[3]->Paint();

        //ball
        textures[2]->MoveTo(ball_x,ball_y);
        textures[2]->Paint();

        //paint greetings
        if(greetings_top)
        {
            textures[4]->Paint();
        }

    glDisable(GL_TEXTURE_2D);


    //ball trace (no texturing)
    if(enabled)
    {
        DrawBallTrace();
    }

    glDisable(GL_BLEND);

#ifdef QT_DEBUG
    qDebug() << "paint gl";
#endif
}
//-------------------------------------
void GLAnim::resizeGL(int w, int h)
{
#ifdef QT_DEBUG
    qDebug() << "resize gl";
#endif

    width = w;
    height = h;

    glViewport(0,0,width,height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluOrtho2D(0, width, 0, height);

#ifdef QT_DEBUG
    qDebug() << "resize gl end";
#endif
}
//------------------------------------------------------
void GLAnim::AddTexture(QString name,double x,double y,int fade_mode,int fade_status, double opacity)
{
    textures[textures_count] = new KTexture(fade_mode,fade_status,opacity);
    textures[textures_count]->Load(name);
    textures[textures_count]->MoveTo(x,y);

    textures_count++;
}
//-------------------------------------
void GLAnim::Start()
{
    enabled = true;
    myTime.start();
    draw_timer->start();
}
//-------------------------------------
void GLAnim::Stop()
{
    enabled = false;
    myTime.restart();
    draw_timer->stop();
}
//-------------------------------------
void GLAnim::DrawBallTrace()
{
    Trace.append(new TracePoint(432.5,ball_y + BALL_HALF_SIZE));//add new point at current ball position

    int traces = Trace.count();

#ifdef QT_DEBUG
    qDebug() << "trace drawing "+QString::number(traces)+" points";
#endif

    glLineWidth(3.0f);

    //draw all points
    glColor4f((float)148 / 255  ,(float) 55 / 255 ,(float) 55 / 255 ,(float)165 / 255);

    glBegin(GL_LINES);

    for(int i = 0;i < traces - 1;i++)
    {
        glVertex2d(Trace[i]->x,Trace[i]->y);
        glVertex2d(Trace[i + 1]->x,Trace[i + 1]->y);
    }

    glEnd();

    //move all point 1 step to the left
    traces = Trace.count();

    for(int i = 0;i < traces; i++)
    {
        Trace[i]->elapsed_time = elapsed_time_from_last_draw;
        Trace[i]->MoveLeft();
    }

    //remove  first
    if(Trace[0]->x < 0)
    {
        Trace.removeFirst();
    }
}
//----------------------------------------
void GLAnim::perfect_timing_report()
{
    textures[4]->MoveYTo(ball_y);
    textures[4]->Flash();
}
//-------------------------------------
GLAnim::~GLAnim()
{
    for(int i = 0;i < textures_count;i++)
        delete textures[i];
}
