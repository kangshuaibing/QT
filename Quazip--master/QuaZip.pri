QUAZIP_INCLUDE_PATH= .

INCLUDEPATH+= $$QUAZIP_INCLUDE_PATH/quazip
DEFINES+= QUAZIP_BUILD
#LIBS+= -lz

HEADERS+= \
        $$QUAZIP_INCLUDE_PATH/quazip/crypt.h \
        $$QUAZIP_INCLUDE_PATH/quazip/ioapi.h \
       $$QUAZIP_INCLUDE_PATH/quazip/JlCompress.h \
       $$QUAZIP_INCLUDE_PATH/quazip/quaadler32.h \
       $$QUAZIP_INCLUDE_PATH/quazip/quachecksum32.h \
        $$QUAZIP_INCLUDE_PATH/quazip/quacrc32.h\
       $$QUAZIP_INCLUDE_PATH/quazip/quagzipfile.h \
       $$QUAZIP_INCLUDE_PATH/quazip/quaziodevice.h \
       $$QUAZIP_INCLUDE_PATH/quazip/quazipdir.h \
       $$QUAZIP_INCLUDE_PATH/quazip/quazipfile.h \
        $$QUAZIP_INCLUDE_PATH/quazip/quazipfileinfo.h\
       $$QUAZIP_INCLUDE_PATH/quazip/quazip_global.h \
        $$QUAZIP_INCLUDE_PATH/quazip/quazip.h \
       $$QUAZIP_INCLUDE_PATH/quazip/quazipnewinfo.h \
        $$QUAZIP_INCLUDE_PATH/quazip/unzip.h \
        $$QUAZIP_INCLUDE_PATH/quazip/zip.h

SOURCES+= $$QUAZIP_INCLUDE_PATH/quazip/qioapi.cpp \
          $$QUAZIP_INCLUDE_PATH/quazip/JlCompress.cpp \
          $$QUAZIP_INCLUDE_PATH/quazip/quaadler32.cpp \
          $$QUAZIP_INCLUDE_PATH/quazip/quacrc32.cpp \
          $$QUAZIP_INCLUDE_PATH/quazip/quagzipfile.cpp \
          $$QUAZIP_INCLUDE_PATH/quazip/quaziodevice.cpp \
          $$QUAZIP_INCLUDE_PATH/quazip/quazip.cpp \
          $$QUAZIP_INCLUDE_PATH/quazip/quazipdir.cpp \
           $$QUAZIP_INCLUDE_PATH/quazip/quazipfile.cpp\
          $$QUAZIP_INCLUDE_PATH/quazip/quazipfileinfo.cpp \
          $$QUAZIP_INCLUDE_PATH/quazip/quazipnewinfo.cpp \
           $$QUAZIP_INCLUDE_PATH/quazip/unzip.c\
           $$QUAZIP_INCLUDE_PATH/quazip/zip.c
