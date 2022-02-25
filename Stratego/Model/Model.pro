CONFIG += c++17 console
CONFIG -= app_bundle

SOURCES += \
        sources/Board.cpp \
        sources/Facade.cpp \
        sources/Piece.cpp \
        sources/Position.cpp

HEADERS += \
    headers/Board.hpp \
    headers/Direction.hpp \
    headers/Facade.hpp \
    headers/Piece.hpp \
    headers/Position.hpp \
    headers/State.hpp
