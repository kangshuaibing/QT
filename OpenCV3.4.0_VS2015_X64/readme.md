## OpenCV3.4.0��vs2015��x64����debug��release�汾

## debugģʽ��QT debug����Ҫconcrt140d.dll��msvcp140d.dll��opencv_world340d.dll��vcruntime140d.dll��������

## QTʹ��ʱ
//.pro
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lopencv_world340
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lopencv_world340d
//.h
#include "opencv2/opencv.hpp"