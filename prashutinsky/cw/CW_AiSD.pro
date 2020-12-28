QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    finish_the_task.cpp \
    graphics_view_zoom.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    finish_the_task.h \
    graphics_view_zoom.h \
    mainwindow.h \
    treap.h

FORMS += \
    finish_the_task.ui \
    mainwindow.ui

TRANSLATIONS += \
    CW_AiSD_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
