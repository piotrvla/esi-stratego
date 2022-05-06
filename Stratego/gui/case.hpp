#ifndef CASE_HPP
#define CASE_HPP

#include <QWidget>
#include <QGraphicsPolygonItem>
#include <QPainter>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include "Position.hpp"

namespace strategoGui{
/**
 * @brief The Case class is an ingame case of the board.
 */
class Case : public QWidget , public QGraphicsPolygonItem{
    Q_OBJECT
    Position pos;
    char role;
    int player;
    bool hidden;
public:
    /**
     * @brief Case's constructor.
     * @param player is player's n°.
     * @param role is role of the piece.
     * @param pos position of the piece.
     * @param hidden is it hidden or not.
     * @param parent parent of the piece.
     */
    Case(int player, char role, Position pos,bool hidden, QWidget * parent =nullptr);
private:
    /**
     * @brief paintEvent colors and creates a graphical form of the piece.
     */
    void paintEvent(QPaintEvent *e);

    void mousePressEvent(QMouseEvent *event);

    void dragLeaveEvent(QDragLeaveEvent *event);

    void dragEnterEvent(QDragEnterEvent * event);

    void dropEvent(QDropEvent*event);
protected:

signals:
    /**
     * @brief sendValue sends a signal that contains its position.
     * @param pos position of the case
     */
    void sendValue(Position pos);
    /**
     * @brief sendDragStatus used to inform if the case is currently dragged or not.
     * @param status drag status.
     */
    void sendDragStatus(bool status);

};
}

#endif // CASE_HPP
