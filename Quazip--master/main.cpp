#include "mainwindow.h"
#include "quazip/JlCompress.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString UnpackSourcePath;
    QString UnpackDirPath;
    UnpackSourcePath = "D:/WorkSpace/QTproject/test_ZX/test_filepath/V1.0.0.2.zip";
    UnpackDirPath    = "D:/WorkSpace/QTproject/test_ZX/test_filepath";
    JlCompress::extractDir(UnpackSourcePath, UnpackDirPath);

    QString PackFilePath;
    QString PackSourcePath;

    PackFilePath      = "D:/WorkSpace/QTproject/test_ZX/test_filepath/bin2.zip";
    PackSourcePath    = "D:/WorkSpace/QTproject/test_ZX/test_filepath/bin2";
    JlCompress::compressDir(PackFilePath, PackSourcePath, true);
    return a.exec();
}

