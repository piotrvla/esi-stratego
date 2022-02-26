TEMPLATE = app
CONFIG -= qt
CONFIG -= app_bundle
CONFIG += console



include(../config.pri)

SOURCES += \
    main.cpp \
    test_models.cpp

HEADERS += \
    catch.hpp

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
