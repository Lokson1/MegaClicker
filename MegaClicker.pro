QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += headers/

SOURCES += \
    src/settings.cpp \
    src/main.cpp \
	src/gamepoints.cpp \
	src/clicker.cpp \
	src/gamebutton.cpp \
	src/mainwindow.cpp \
	src/menu.cpp

HEADERS += \
    headers/gamepoints.h \
	headers/clicker.h \
	headers/gamebutton.h \
	headers/mainwindow.h \
	headers/menu.h \
    headers/settings.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md \
    score
