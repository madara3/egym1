#ifndef DRAGABLEPART_H
#define DRAGABLEPART_H

#include <QLabel>
#include <QMouseEvent>

class DragablePart : public QLabel
{
    Q_OBJECT

    public:
        double value;

        DragablePart( const QString& text="", QWidget* parent=0 );
        ~DragablePart();
        void setDragVerticalLimits(int y_min,int y_max);

   signals:
        void clicked();
        void ValueChanged(double value);
        void mouseRelease(QMouseEvent* event);

    public slots:
        void scroll_up();
        void scroll_down();

    private:
        bool draging;
        QPoint old_mouse_pos,widget_old_pos;
        int min_y, max_y;
        int vertical_step;

    protected:
        void mousePressEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
};

#endif // DRAGABLEPART_H
