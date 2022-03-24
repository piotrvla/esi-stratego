#include "Facade.hpp"

Facade::Facade():board{Modele::Board()},currentPlayer{1},state{State::NOT_STARTED}{

}
void Facade::move(Position pos, Direction direction, int distance){
    if(state!=State::MOVING)
        throw std::invalid_argument("Cannot move right now");
    if(board.at(pos)->getPlayer()!=currentPlayer)
        throw std::invalid_argument("That's not your piece");
    try {
        board.move(pos,direction,distance);
        state=State::NEXT_PLAYER;
    } catch (std::exception &ex) {
        throw std::invalid_argument("Invalid move");
    }
}
Piece Facade::at(Position pos) const{
    return board.at(pos).value();
}
bool Facade::isGameOver(){
    if(board.isGameOver()){
        state=State::GAME_OVER;
        return true;
    }
    return false;
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
        currentPlayer = currentPlayer==1 ? 2 : 1;
    state=State::MOVING;
}
std::string Facade::to_string(){
    return board.to_string(currentPlayer);
}

void Facade::start(){
    if(state!=State::NOT_STARTED)
        throw std::invalid_argument("Game is already started");
    state=State::MOVING;
}

int Facade::getBoardSize() const{
    return board.getBoardSize();
}


