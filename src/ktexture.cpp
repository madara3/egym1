#include "ktexture.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

#define OPACITY_STEP 0.10

//-------------------------------------
KTexture::KTexture(int fade_m,int fade_s, double opa)
{
    tx = ty = 0.0;
    x = y = 0.0;
    width = height = 0.0;
    opacity = opa;
    fade_mode = fade_m;
    fade_status = fade_s;
}

//-------------------------------------
void KTexture::MoveTo(double x, double y)
{
    this->x = x;
    this->y = y;
}
//-------------------------------------
void KTexture::MoveYTo(double y)
{
     this->y = y;
}
//-------------------------------------
void KTexture::SetTx(double v)
{
    this->tx = v;
}

//-------------------------------------
void KTexture::MoveTextureLeft(double step)
{
    this->tx += step;
}
//-------------------------------------
void KTexture::Flash()
{
    fade_mode = FADING_MODES::FADE_IN_OUT_ONCE;
    opacity = 0;
    fade_status = FADING_STATUSES::FADING_IN;
}

//-------------------------------------
void KTexture::Fade()
{
    switch(fade_mode)
    {
        case FADING_MODES::NO_FADING://no fading

        break;

        case FADING_MODES::FADE_IN_OUT_ONCE://fade in then out once
            switch(fade_status)
            {
                case FADING_STATUSES::NOT_FADING://do nothing
                break;

                case FADING_STATUSES::FADING_IN://fade in
                    if(opacity < 1.0)
                        opacity += OPACITY_STEP;
                    else
                        fade_status = FADING_STATUSES::FADING_OUT;
                break;

            case FADING_STATUSES::FADING_OUT: //fade out
                if(opacity > 0)
                    opacity -= OPACITY_STEP;
                else
                    fade_status = FADING_STATUSES::NOT_FADING;
                break;
            }
        break;

        case FADING_MODES::FADE_IN_OUT_LOOP:
            switch(fade_status)
            {
                case 0://fade in
                 if(opacity < 1.0)
                     opacity += OPACITY_STEP;
                 else
                     fade_status = 2;
                break;

                case 1://wait

                break;

                case 2: //fade out
                if(opacity > 0)
                    opacity -= OPACITY_STEP;
                else
                    fade_status = 0;
                break;
            }
        break;
    }
}
//-------------------------------------
void KTexture::Paint()
{
    Fade();

    glBindTexture(GL_TEXTURE_2D, Textures[0]);
    glColor4d(1,1,1,opacity);
    glBegin(GL_QUADS);
        glTexCoord2d(tx,ty);
        glVertex2d(x,y);

        glTexCoord2d(tx + 1,ty);
        glVertex2d(x + width,y);

        glTexCoord2d(tx + 1,ty + 1);
        glVertex2d(x + width,y + height);

        glTexCoord2d(tx,ty + 1);
        glVertex2d(x,y + height);
    glEnd();
}

//------------------------------------------------------
void KTexture::Load(QString name)
{
    QImage* img = new QImage();
    if(img->load(name) != true)
    {
#ifdef QT_DEBUG
        qDebug() << "error: texture not loaded";
#endif
        return;
    }

    width = img->width();
    height = img->height();

    glEnable(GL_TEXTURE_2D);

    glGenTextures(1, &Textures[0]);

    glBindTexture(GL_TEXTURE_2D, Textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, img->bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glDisable(GL_TEXTURE_2D);

    delete(img);

#ifdef QT_DEBUG
    qDebug() << "texture [id="+QString::number(Textures[0])+"] loaded, size: "+QString::number(width)+" x "+QString::number(height);
#endif
}
//------------------------------------------------------
KTexture::~KTexture()
{
    if(glIsTexture(Textures[0]))
        glDeleteTextures(1,Textures);
}
