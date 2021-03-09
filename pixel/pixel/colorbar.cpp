#include "colorbar.h"

#include<QPainter>
#include<QMouseEvent>

QColor ColorBarLight::color(255,50,50,255);
QColor ColorBarAlpha::color(255,50,50,255);
ColorBarLight::ColorBarLight(QWidget* parent)
    :QWidget(parent) {
    setFixedHeight(30);
}

void ColorBarLight::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    int h,s,l;
    color.getHsl(&h,&s,&l);
    paint.setPen(Qt::NoPen);
    for(int i=0;i<width();i++){
        color.setHsl(h,s,(int)(1.0*i/width()*255));
        paint.setBrush(color);
        paint.drawRect(i,0,1,height());
    }

}

void ColorBarLight::mousePressEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int h,s,l;
    color.getHsl(&h,&s,&l);
    QColor newColor;
    newColor.setHsl(h,s,(int)(1.0*x/width()*255));
    emit(selectColor(newColor));
}

ColorBarAlpha::ColorBarAlpha(QWidget* parent)
    :QWidget(parent) {
    setFixedHeight(30);
}

void ColorBarAlpha::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.setPen(Qt::NoPen);
    int size = 8;
    for(int i=0;i<=width()/size;i++){
        for(int j=0;j<=height()/size;j++){
            paint.setBrush(QColor(222,222,222));
            paint.drawRect(size*i, size*j, size/2, size/2);
            paint.drawRect(size*i + size/2, size*j+size/2, size/2, size/2);
            paint.setBrush(QColor(255,255,255));
            paint.drawRect(size*i+size/2, size*j, size/2, size/2);
            paint.drawRect(size*i, size*j+size/2, size/2, size/2);
        }
    }
    for(int i=0;i<width();i++){
        color.setAlpha((int)((1.0*i/width())*255));
        paint.setBrush(color);
        paint.drawRect(i,0,1,height());
    }
}

void ColorBarAlpha::mousePressEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int alpha = (int)(1.0*x/width()*255);
    QColor newColor(color.red(),color.green(),color.blue(),alpha);
    emit(selectColor(newColor));

}
