#ifndef KTEXTURE_H
#define KTEXTURE_H

#include <QGLWidget>

enum FADING_MODES{
NO_FADING,
FADE_IN_OUT_ONCE,
FADE_IN_OUT_LOOP
};

enum FADING_STATUSES{
NOT_FADING,
FADING_IN,
FADING_OUT
};

class KTexture
{
private:
    GLuint Textures[1];//2d texture
    double tx,ty;//texture cooridinates
    double x, y;
    double width,height;
    double opacity;

    int fade_mode;
    int fade_status;


public:
    KTexture(int fade_m = 0,int fade_s = 0,double opacity = 1);

    void Load(QString name);

    void MoveTextureLeft(double step);
    void MoveLeft(double step);
    void MoveTo(double x, double y);
    void MoveYTo(double y);

    void SetTx(double v);

    void Flash(); //show the texture then hides it
    void Fade();

    void Paint();
    void PaintwithOpacity();

    ~KTexture();
};

#endif // KTEXTURE_H
