## OpenCV3.4.0、vs2015、x64包括debug和release版本

## debug模式（QT debug）需要concrt140d.dll、msvcp140d.dll、opencv_world340d.dll、vcruntime140d.dll才能运行

## QT使用时
//.pro
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lopencv_world340
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lopencv_world340d
//.h
#include "opencv2/opencv.hpp"