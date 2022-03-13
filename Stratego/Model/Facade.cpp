#include "Facade.hpp"

Facade::Facade():board{},currentPlayer{},state{State::NOT_STARTED}{


}
void Facade::move(Position pos, Direction direction, int distance){
    if(state!=State::MOVING)
        //exception dans la façade?
    if(board.at(pos)->getPlayer()!=currentPlayer)
        //exception?
    board.move(pos,direction,distance);
    state=State::NEXT_PLAYER;
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
        currentPlayer = currentPlayer+1 % 2;
    state=State::MOVING;
}
std::string Facade::to_string(){
    return board.to_string(currentPlayer);
}


