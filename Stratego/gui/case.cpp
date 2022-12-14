#include "case.hpp"
#include <cmath>
#include <iostream>

namespace strategoGui{
Case::Case(int player, char role, Position position,bool hidden,QWidget *parent) : QWidget(parent), pos{position},role{role},player{player},hidden{hidden}{

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
           brush.setColor(Qt::blue);
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
    }else if(role=='W'){
        QBrush brush;
        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);
        painter.drawRect(QRect(0,0,130,72));
    }else{
        QBrush brush;
        brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);
        painter.drawRect(QRect(0,0,130,72));
    }
    if(!hidden && player!=0){
        painter.setPen(Qt::white);
        QFont font;
        font.setPointSize(15);
        painter.setFont(font);
        painter.drawText(QPoint(40,40),QString{role});
    }

    QWidget::setAcceptDrops(true);

}
void Case::mousePressEvent(QMouseEvent *event) {
    event->accept();
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("text");
    drag->setMimeData(mimeData);
    Qt::DropAction dropAction = drag->exec();
}

void Case::dragEnterEvent(QDragEnterEvent * event){
    event->accept();
    emit sendDragStatus(true);
    emit sendValue(pos);
}

void Case::dragLeaveEvent(QDragLeaveEvent *event){

}

void Case::dropEvent(QDropEvent*event){
    event->accept();
    emit sendDragStatus(false);
}

}




