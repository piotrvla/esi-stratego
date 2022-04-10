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
protected:

signals:
    void sendValue(Position pos);
};

#endif // CASE_HPP
