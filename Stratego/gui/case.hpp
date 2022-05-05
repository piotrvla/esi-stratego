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
class Case : public QWidget , public QGraphicsPolygonItem{
    Q_OBJECT
    Position pos;
    char role;
    int player;
    bool hidden;
public:
    Case(int player, char role, Position pos,bool hidden, QWidget * parent =nullptr);
private:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragEnterEvent(QDragEnterEvent * event);
    void dropEvent(QDropEvent*event);
protected:

signals:
    void sendValue(Position pos);
    void sendDragStatus(bool status);

};
}

#endif // CASE_HPP
