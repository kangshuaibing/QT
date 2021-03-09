#include "pixel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pixel w;
    a.setWindowIcon(QIcon(":/images/box.icon"));

    return a.exec();
}
