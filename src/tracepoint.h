#ifndef TRACEPOINT_H
#define TRACEPOINT_H

#include <QGLWidget>
#include <QTime>

class TracePoint
{
public:
    double x,y;
    int elapsed_time;

public:
    TracePoint(double x, double y);

    void Draw();
    void MoveTo(double x,double y);
    void MoveLeft();

};

#endif // TRACEPOINT_H
