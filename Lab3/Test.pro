QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    convinfo.cpp \
    deletedialog.cpp \
    list.cpp \
    main.cpp \
    mainwindow.cpp \
    outputcityinfodialog.cpp \
    outputnumberdialog.cpp

HEADERS += \
    convinfo.h \
    deletedialog.h \
    list.h \
    mainwindow.h \
    outputcityinfodialog.h \
    outputnumberdialog.h

FORMS += \
    deletedialog.ui \
    mainwindow.ui \
    outputcityinfodialog.ui \
    outputnumberdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
