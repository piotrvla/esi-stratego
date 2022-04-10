QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


include(../config.pri)


SOURCES += \
    case.cpp \
    controller.cpp \
    main.cpp \
    view.cpp

HEADERS += \
    case.hpp \
    controller.hpp \
    view.hpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Model/release/ -lModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Model/debug/ -lModel
else:unix: LIBS += -L$$OUT_PWD/../Model/ -lModel

INCLUDEPATH += $$PWD/../Model
DEPENDPATH += $$PWD/../Model

FORMS += \
    resources/stratego.ui
OTHER_FILES += \
    resources/background_picture
