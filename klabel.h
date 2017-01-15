#ifndef KLABEL_H
#define KLABEL_H

#include<QLabel>

class KLabel : public QLabel
{
Q_OBJECT

public:
    KLabel( const QString& text="", QWidget* parent=0 );
    ~KLabel();

signals:
    void mousePress(QMouseEvent* event);
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // KLABEL_H
