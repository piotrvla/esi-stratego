#ifndef POSITION_H
#define POSITION_H

class Position{
private:
    int x,y;

public:
    Position(int x, int y );
    inline int getX(){
        return this->x;
    }
    inline int getY(){
        return this->y;
    }
};
#endif // POSITION_H
