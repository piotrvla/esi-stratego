#ifndef BOARDGUI_H
#define BOARDGUI_H

#include "Position.hpp"
#include "ui_stratego.h"
#include <QObject>

class Facade;

namespace strategoGui{
class View;
class Controller;
/**
 * @brief The Board class contains cases of the game.
 */
class Board : public QObject
{
Q_OBJECT
private slots:
    /**
     * @brief positionHandler used to manage swapping and moving pieces.
     * @param pos position to move from or to move to.
     */
    void positionHandler(Position pos);
    /**
     * @brief dragStatusHandler modifies the drag status and also movPosEnd.
     * @param status is the new status.
     */
    void dragStatusHandler(bool status);
private:
    Position movPosInit;
    Position movPosEnd;
    Ui::View * ui;
    Facade & facade;
    View * view;
    QWidget * parent;
    bool dragStatus;
    /**
     * @brief move used to move a case from position x to position y.
     * @param pos1 position x to move from.
     * @param pos2 position y to move to.
     */
    void move(Position pos1, Position pos2);
public:
    /**
     * @brief Board's constructor.
     * @param ui, ui design.
     * @param view is current view instance.
     * @param facade is current facade instance.
     * @param parent parent of the instance.
     */
    Board(Ui::View * ui, strategoGui::View * view, Facade & facade, QWidget * parent=nullptr);
    /**
     * @brief updateBoard updates the board by recreating the pieces at their current positions.
     */
    void updateBoard();
};
}

#endif // BOARDGUI_H
