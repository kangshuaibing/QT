﻿#ifndef PAINT_H
#define PAINT_H
#include<QWidget>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QColor>
#include<set>
class QLabel;
class point{
public:
    int x;
    int y;
    QColor c;
    point();
    point(QColor color,int i = -1,int j = -1);
    friend bool operator <(const point& x,const point& y);
    friend bool operator ==(const point& x,const point& y);
};

class paintWindow:public QWidget
{
    Q_OBJECT
private:
    int XMAX;
    int YMAX;
    int size;

    enum{DRAWPIXEL,DRAWRECT,FILLCOLOR,DRAWFULLRECT,DRAWLINE,
        DRAWCIRCLE,DRAWFULLCIRCLE,ERASE,GETCOLOR};
    enum{TIMES=30};
    QImage *img;
    QLabel *picture;
    int state;
    QColor*** map;
    int layer;
    int front;
    int rear;
    int margin;
    std::set<point>currentPoint;

    bool isRelease;
    void updateMap();
    void bresenhamLine(int,int,int,int);
    void bresenhamLine(int,int,int,int,bool);
    void bresenhamCircle(int xc,int yc,int r);
    void bresenhamCircle(int xc,int yc,int x,int y);
    void bresenhamFullCircle(int xc,int yc,int r);
    void seedFilling(int i,int j);
    void updateImage();
    void drawTmpPixel();
    void drawOnScreenPixel();
    void setLayout(int,int);
    bool isShowGrid;
    inline int min(int x,int y){return x<y?x:y;}
    inline int max(int x,int y){return x>y?x:y;}
    QColor mixColor(const QColor& x,const QColor& y);

public:
    static QColor color;
    void saveImage(const QString &fileName,int s);
    void undo();
    void redo();
    void drawRect();
    void drawPixel();
    void fillColor();
    void drawFullRect();
    void drawLine();
    void drawCircle();
    void drawFullCircle();
    void erase();
    void showGrid();
    void getColor();
    QLabel* getImage();
    void newImage(QImage* image);
    paintWindow(QWidget *parent = 0);
    ~paintWindow();

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

public slots:
    void changeSize(int,int);
signals:
    void changeColor(QColor);
    void changeImg();
};

#endif // PAINT_H
