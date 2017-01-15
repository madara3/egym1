#include <klabel.h>

#define Y_DISPLACEMENT 2

//------------------------------------------------------------------
KLabel::KLabel(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    setText(text);
}
//------------------------------------------------------------------
void KLabel::mousePressEvent(QMouseEvent* event)
{
    QPoint p = this->pos();
    p.setY(p.y() + Y_DISPLACEMENT);
    this->move(p);
    emit mousePress(event);
}
//------------------------------------------------------------------
void KLabel::mouseReleaseEvent(QMouseEvent* event)
{
    QPoint p = this->pos();
    p.setY(p.y() - Y_DISPLACEMENT);
    this->move(p);
    emit clicked();
}
//------------------------------------------------------------------
KLabel::~KLabel()
{
}

