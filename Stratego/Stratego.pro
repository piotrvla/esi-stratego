TEMPLATE = subdirs

SUBDIRS += \
    Model \
    tests

tests.depends = Model

OTHER_FILES += config.pri

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Model/release/ -lmodel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Model/debug/ -lmodel
else:unix: LIBS += -L$$OUT_PWD/Model/ -lmodel

INCLUDEPATH += $$PWD/Model
DEPENDPATH += $$PWD/Model

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/Model/release/libmodel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/Model/debug/libmodel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/Model/release/model.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/Model/debug/model.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/Model/libmodel.a
