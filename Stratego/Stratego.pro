TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Board.cpp \
        Piece.cpp \
        Position.cpp \
        main.cpp

HEADERS += \
    Board.hpp \
    Direction.hpp \
    Facade.hpp \
    Piece.hpp \
    Position.hpp \
    State.hpp
