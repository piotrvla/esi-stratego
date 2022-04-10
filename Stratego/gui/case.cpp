#include "case.hpp"
#include <cmath>
#include <iostream>

Case::Case(int player, char role, Position position,QWidget *parent) : QWidget(parent), pos{position},role{role},player{player}{
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#pragma GCC diagnostic pop
void Case::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    if(player !=0){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
       if(player==1){
           QBrush brush;
           brush.setColor(Qt::green);
           brush.setStyle(Qt::SolidPattern);
           painter.setBrush(brush);
           painter.drawRect(QRect(0,0,130,72));
       }else{
           QBrush brush;
           brush.setColor(Qt::red);
           brush.setStyle(Qt::SolidPattern);
           painter.setBrush(brush);
           painter.drawRect(QRect(0,0,130,72));
       }

       painter.setBrush(brush);
       QString a;
       a+= role;
    }else{
        QBrush brush;
        brush.setColor(Qt::blue);
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);
        painter.drawRect(QRect(0,0,130,72));

    }


}



