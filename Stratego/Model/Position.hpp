#ifndef POSITION_H
#define POSITION_H
/**
 * @brief The Position class is a position in the board.
 */
class Position{
private:
    int x,y;

public:
    /**
     * @brief Position is a constructor of a single position.
     * @param x is row in the board.
     * @param y is the col in the board.
     */
    Position(int x, int y );
    /**
     * @brief getX returns the row position.
     * @return row position.
     */
    int getX() const ;
    /**
     * @brief getY returns the col position.
     * @return col position.
     */
    int getY() const ;
};
#endif // POSITION_H
