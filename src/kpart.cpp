#include "kpart.h"
#include <map>

#define SMALL_STEP          1

//------------------------------------------------------------------
DragablePart::DragablePart(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    draging = false;
    setText(text);
    value = 50;
    vertical_step = 1;
}
//------------------------------------------------------------------
void DragablePart::setDragVerticalLimits(int y_min, int y_max)
{
    this->min_y = y_min;
    this->max_y = y_max;
    vertical_step = (y_max - y_min) / 100;
}
//------------------------------------------------------------------
void DragablePart::scroll_up()
{
    if(value > 0)
    {
        value -= SMALL_STEP;
        emit ValueChanged(value);

        QPoint p = this->pos();
        this->move(p.x(),min_y + (value * vertical_step));
    }
}
//------------------------------------------------------------------
void DragablePart::scroll_down()
{
    if(value < 100)
    {
        value += SMALL_STEP;
        emit ValueChanged(value);

        QPoint p = this->pos();
        this->move(p.x(),min_y + (value * vertical_step));
    }
}
//------------------------------------------------------------------
void DragablePart::mousePressEvent(QMouseEvent* event)
{
    draging = true;
    old_mouse_pos = event->globalPos();
    widget_old_pos = this->pos();
}
//------------------------------------------------------------------
void DragablePart::mouseMoveEvent(QMouseEvent* event)
{
    QPoint n = event->globalPos();//new mouse pos

    int drag_dist = n.y() - old_mouse_pos.y();

    QPoint p = widget_old_pos;

    int new_y = p.y() + drag_dist;

    if(new_y > max_y)
        new_y = max_y;

    if(new_y < min_y)
        new_y = min_y;

    this->move(p.x(),new_y);

    //set value
    value = (double) (new_y - min_y) / vertical_step;

    if(value > 100)
        value = 100;

    emit ValueChanged(value);
}
//------------------------------------------------------------------
void DragablePart::mouseReleaseEvent(QMouseEvent* event)
{
    draging = false;
    emit mouseRelease(event);
}
//------------------------------------------------------------------
DragablePart::~DragablePart()
{
}
