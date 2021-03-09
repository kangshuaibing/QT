#include "colorwindow.h"
#include "paint.h"
#include "button.h"
#include "colorbar.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSignalMapper>
#include <QColorDialog>


ColorWindow::ColorWindow(QWidget *parent) : QWidget(parent)
{
    colorbar1 = new ColorBarLight;
    colorbar2 = new ColorBarAlpha;
    QVBoxLayout* vlayout = new QVBoxLayout();
    QGridLayout* glayout = new QGridLayout();
    QGridLayout* glayout1 = new QGridLayout();
    QSignalMapper* signalMapper[10];
    QString str0 = ":/images/choose.png";
    Button* chooseNewColorBtn = new Button(str0,str0,str0);
    chooseNewColorBtn->setStyleSheet("border:1px solid #d1d1d1;");
    currentColorBtn = new QToolButton();
    btnGroup = new QGroupBox;
    chosenColorGroup = new QGroupBox;

    connect(chooseNewColorBtn,SIGNAL(clicked(bool)),this,SLOT(colorDialog()));
    QString str[] ={"border:1px solid #d1d1d1;background-color:rgb(255,50,50);",
                    "border:1px solid #d1d1d1;background-color:rgb(255,125,50);",
                    "border:1px solid #d1d1d1;background-color:rgb(255,50,255);",
                    "border:1px solid #d1d1d1;background-color:rgb(255,255,50);",
                    "border:1px solid #d1d1d1;background-color:rgb(50,255,50);",
                    "border:1px solid #d1d1d1;background-color:rgb(50,50,255);",
                    "border:1px solid #d1d1d1;background-color:rgb(50,255,255);",
                    "border:1px solid #d1d1d1;background-color:rgb(255,255,255);",
                    "border:1px solid #d1d1d1;background-color:rgb(50,50,50);",
                    "border:1px solid #d1d1d1;background-color:rgb(156,156,156);"};

    for(int i=0;i<10;i++)
    {
        style[i] = str[i];

        signalMapper[i] = new QSignalMapper();

        colorBtn[i] = new QToolButton();
        colorBtn[i]->setStyleSheet(style[i]);
        connect(colorBtn[i],SIGNAL(clicked()),signalMapper[i],SLOT(map()));

        signalMapper[i]->setMapping(colorBtn[i],i);

        connect(signalMapper[i],SIGNAL(mapped(int)),this,SLOT(changeColor(int)));

        glayout->addWidget(colorBtn[i],i/2,i%2);
    }

    currentColorBtn->setStyleSheet(style[0]);
    glayout1->addWidget(currentColorBtn,0,0,1,1);
    glayout1->addWidget(chooseNewColorBtn,0,1,1,1);
    chosenColorGroup->setLayout(glayout1);

    btnGroup->setLayout(glayout);

    vlayout->addWidget(chosenColorGroup);
    vlayout->addWidget(btnGroup);
    vlayout->addWidget(colorbar1);
    vlayout->addWidget(colorbar2);
    vlayout->addStretch();

    setLayout(vlayout);
    setMaximumWidth(100);

    connect(colorbar1,SIGNAL(selectColor(QColor)),this,SLOT(changeColorLight(QColor)));
    connect(colorbar2,SIGNAL(selectColor(QColor)),this,SLOT(changeColorAlpha(QColor)));
}
void ColorWindow::changeColor(int id)
{
    int num[10][3] = {
        255,50,50,255,125,50,255,50,255,255,255,50,50,255,50,50,50,255,50,255,255,
        255,255,255,50,50,50,156,156,156
    };
    currentColorBtn->setStyleSheet(style[id]);
    paintWindow::color = QColor(num[id][0],num[id][1],num[id][2]);
    ColorBarLight::color = QColor(num[id][0],num[id][1],num[id][2]);
    ColorBarAlpha::color = QColor(num[id][0],num[id][1],num[id][2]);
    colorbar1->update();
    colorbar2->update();
}

QString ColorWindow::getStyleSheetAlpha(const QColor& color)
{
    QString str = "border:1px solid #d1d1d1;background-color:rgba(";

    str = str + QString::number(color.red()) + "," + QString::number(color.green()) + ","
            + QString::number(color.blue()) + "," + QString::number(1.0*color.alpha()/255*100) + "%);";
    return str;
}

QString ColorWindow::getStyleSheet(const QColor& color)
{
    QString str = "border:1px solid #d1d1d1;background-color:rgb(";

    str = str + QString::number(color.red()) + "," + QString::number(color.green()) + ","
            + QString::number(color.blue()) + ");";
    return str;
}

void ColorWindow::changeColorLight(QColor color)
{
    currentColorBtn->setStyleSheet(getStyleSheet(color));
    paintWindow::color = color;
    ColorBarAlpha::color = color;
    colorbar2->update();
}

void ColorWindow::changeColorAlpha(QColor color)
{
    currentColorBtn->setStyleSheet(getStyleSheetAlpha(color));
    paintWindow::color = color;
    ColorBarAlpha::color = color;
    colorbar1->update();
}

void ColorWindow::changeColor(QColor color)
{
    currentColorBtn->setStyleSheet(getStyleSheetAlpha(color));
    paintWindow::color = color;
    ColorBarLight::color = color;
    ColorBarAlpha::color = color;
    colorbar1->update();
    colorbar2->update();
}

void ColorWindow::colorDialog()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    if(color==QColor::Invalid){
        color = paintWindow::color;
    }
    QString str = getStyleSheet(color);
    currentColorBtn->setStyleSheet(str);
    paintWindow::color = color;
    ColorBarLight::color = color;
    ColorBarAlpha::color = color;
    colorbar1->update();
    colorbar2->update();
}
