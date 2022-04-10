#ifndef CASE_HPP
#define CASE_HPP

#include <Position.hpp>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPolygonItem>


class Case : public QWidget , public QGraphicsPolygonItem{

    Position pos;
    char role;
    int player;
public:
    Case(int player, char role, Position pos, QWidget * parent =nullptr);
private:
    void paintEvent(QPaintEvent *e);
};

#endif // CASE_HPP
