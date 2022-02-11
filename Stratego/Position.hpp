#ifndef POSITION_H
#define POSITION_H
class Position{
    Position(int x, int y );
    int x,y;
public:
    inline int getX(){
        return this->x;
    }
    inline int getY(){
        return this->y;
    }
};
#endif // POSITION_H
