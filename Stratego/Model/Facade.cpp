 #include "Facade.hpp"

using namespace Modele;

Facade::Facade():board{Board()},currentPlayer{1},state{State::NOT_STARTED}{

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
        state=State::MOVING;
    }
}
Piece Facade::at(Position pos) const{
    return board.at(pos).value();
}
bool Facade::isGameOver(){
    if(board.isGameOver()){
        state=State::GAME_OVER;
        notify("game over");
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
    if((state==State::NEXT_PLAYER | state==State::SWAPING))
        currentPlayer = currentPlayer==1 ? 2 : 1;
    if(state==State::SWAPING && currentPlayer==2){
        state=State::SWAPING;
        notify("swap");
    }else{
        state=State::MOVING;
        notify("move");
    }
}
std::string Facade::to_string(){
    if(cheatMode)
        return board.to_string(0);
    else
        return board.to_string(currentPlayer);
}

void Facade::start(){
    if(state!=State::NOT_STARTED)
        throw std::invalid_argument("Game is already started");
    state=State::SWAPING;
}

int Facade::getBoardSize() const{
    return board.getBoardSize();
}

void Facade::swap(Position p1, Position p2){
    if(state!=State::SWAPING) throw std::invalid_argument("Not in SWAPING.");
    if(at(p1).getPlayer()!=currentPlayer || at(p2).getPlayer()!=currentPlayer)
        throw std::invalid_argument("That's not your piece");
    board.swap(p1, p2);
    notify("swap");
}
void Facade::setCheatMode(char chMode){
    if(chMode=='y')
        cheatMode=true;
}
bool Facade::isPiece(Position pos){
    return board.isPiece(pos);
}


