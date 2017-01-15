#include "tracepoint.h"
//#include <gl/GL.h>

#define TRACE_PIXELS_PER_MS    (double)415.5 / 3500
#define TRACE_POINT_SIZE    1

//---------------------------------
TracePoint::TracePoint(double x, double y)
{
    this->x = x;
    this->y = y;
}
//---------------------------------
void TracePoint::Draw()
{
    glColor4f(0.0f,0.0f,0.0f,1.0f);

    glBegin(GL_QUADS);
        glVertex2d(x,y);
        glVertex2d(x + TRACE_POINT_SIZE,y);
        glVertex2d(x + TRACE_POINT_SIZE,y + TRACE_POINT_SIZE);
        glVertex2d(x,y + TRACE_POINT_SIZE);
    glEnd();
}
//---------------------------------
void TracePoint::MoveTo(double x, double y)
{
    this->x = x;
    this->y = y;
}
//---------------------------------
void TracePoint::MoveLeft()
{
    this->x  -= TRACE_PIXELS_PER_MS * elapsed_time;
}
