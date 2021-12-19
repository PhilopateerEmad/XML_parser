QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    compressionCoding.cpp \
    compressionDecoding.cpp \
    consistency.cpp \
    formatting_minifying.cpp \
    general_functions.cpp \
    huffNode.cpp \
    huffTree.cpp \
    json.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    C:/Users/koko/Desktop/pro/pro/compressionCoding.h \
    C:/Users/koko/Desktop/pro/pro/compressionDecoding.h \
    C:/Users/koko/Desktop/pro/pro/huffNode.h \
    C:/Users/koko/Desktop/pro/pro/huffTree.h \
    compressionCoding.h \
    compressionDecoding.h \
    consistency.h \
    formatting_minifying.h \
    general_functions.h \
    huffNode.h \
    huffTree.h \
    json.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc \
    Resources.qrc
