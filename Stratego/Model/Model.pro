
CONFIG -= qt

TEMPLATE = lib



include(../config.pri)

SOURCES += \
        Board.cpp \
        Facade.cpp \
        Piece.cpp \
        Position.cpp \


HEADERS += \
    Board.hpp \
    Direction.hpp \
    Facade.hpp \
    Piece.hpp \
    Position.hpp \
    State.hpp \
    observable.h \
    observer.h



