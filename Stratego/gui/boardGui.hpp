#ifndef BOARDGUI_H
#define BOARDGUI_H

#include "Position.hpp"
#include "ui_stratego.h"
#include <QObject>

class Facade;

namespace strategoGui{
class View;
class Controller;

class Board : public QObject
{
Q_OBJECT
private slots:
    void positionHandler(Position pos);
    void dragStatusHandler(bool status);
private:
    Position movPosInit;
    Position movPosEnd;
    Ui::View * ui;
    Facade & facade;
    View * view;
    void move(Position pos1, Position pos2);
    QWidget * parent;
    bool dragStatus;
public:
    Board(Ui::View * ui, strategoGui::View * view, Facade & facade, QWidget * parent=nullptr);
    void updateBoard();
};
}

#endif // BOARDGUI_H
