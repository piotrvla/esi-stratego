#ifndef PIECE_H
#define PIECE_H
/**
 * @brief The Piece class represents a piece in the board, identified by it's symbol and player id.
 */
class Piece{
private:
    char symbole;
    unsigned player;
    bool cheated;

public:
    /**
     * @brief Piece is a constructor of the piece.
     * @param symbole symbol of the piece
     * @param player id of the player
     */
    Piece (char symbole,unsigned player=0);
    /**
     * @brief getSymbole getter of the symbol.
     * @return symbol of the piece.
     */
    char getSymbole() const;
    /**
     * @brief getPlayer getter of player's id.
     * @return player's id.
    */
    unsigned getPlayer() const;

    unsigned getCheated() const;

    void setCheated(bool cheated);
};
#endif // PIECE_H
