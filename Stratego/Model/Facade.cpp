#include "Facade.hpp"

Facade::Facade():board{},currentPlayer{},state{State::NOT_STARTED}{


}
void Facade::move(Position pos, Direction direction, int distance){
    board.move(pos,direction,distance);

}
Piece Facade::at(Position pos) const{
    return board.at(pos).value();
}
bool Facade::isGameOver(){
    bool gameOver=board.isGameOver();
    if(gameOver)
        state=State::GAME_OVER;

}
int Facade::getWinner(){
        return board.getWinner();
}

State Facade::getState() const{

    return state;

}
unsigned Facade::getCurrentPlayer() const{
    return currentPlayer;

}
void Facade::nextPlayer(){
    if(state!=State::NEXT_PLAYER)
        currentPlayer = currentPlayer+1 % 2;
}
std::string Facade::to_string(){
    return board.to_string();
}


