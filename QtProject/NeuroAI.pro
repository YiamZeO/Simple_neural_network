QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NeuroNetwork.cpp \
    aboutclass.cpp \
    gamesett.cpp \
    main.cpp \
    networkplaying.cpp \
    networktraining.cpp \
    playingclass.cpp \
    trainclass.cpp \
    widget.cpp

HEADERS += \
    NeuroNetwork.h \
    aboutclass.h \
    gamesett.h \
    networkplaying.h \
    networktraining.h \
    playingclass.h \
    trainclass.h \
    widget.h

FORMS += \
    aboutclass.ui \
    gamesett.ui \
    playingclass.ui \
    trainclass.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
