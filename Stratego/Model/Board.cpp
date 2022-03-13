#include <Board.hpp>
using namespace std;
Modele::Board::Board(){
    for(unsigned player=1; player<=2; player++){
    initializeArmy(player);
    }
}
Modele::Board::Board(bool a){

}

void Modele::Board::initializeArmy(unsigned player){
    vector<pair<char, int>> listOfPieces={pair('9',1), pair('8',1),pair('7',2),pair('6',3),pair('5',4),
                pair('4',4),pair('3',4),pair('2',5),pair('1',8),
                pair('0',1),pair('D',1),pair('B',6)};

    ifstream fi("player"+std::to_string(player)+".txt");
    if(fi.good()){
        string line;
        unsigned lineNb=0;

        while(getline(fi, line) && lineNb<BOARD_SIZE){
            for(int i=BOARD_SIZE-1; i>=0; i--){
                if(line.size()<2) throw out_of_range("Not enough file input.");
                char selectedSymbol = line.at(0);
                line.erase(0, 2);
                vector<pair<char, int>>::iterator availibilitySymbol = find_if(listOfPieces.begin(), listOfPieces.end(), [selectedSymbol](pair<char, int> currentSymbol){
                    return selectedSymbol == currentSymbol.first;
                });

                if(availibilitySymbol==listOfPieces.end()) throw out_of_range("Piece not found.");
                if(availibilitySymbol->second==0) throw out_of_range("No more piece");
                availibilitySymbol->second--;

                optional<Piece> piece((Piece(selectedSymbol,player)));

                if(player==1){
                board[3-lineNb][i] = piece;
                }else if(player==2){
                    board[BOARD_SIZE+lineNb-4][BOARD_SIZE-i-1] = piece;
                }
            }
            lineNb++;
        }
    }else{
        ofstream fo("player"+std::to_string(player)+".txt");
        srand(time(NULL)+player);

            for(unsigned i=0; i<4; i++){
                        for(unsigned j=0; j<BOARD_SIZE; j++){
                        unsigned randNb = rand()%listOfPieces.size();
                        pair<char, int> & selectedPiece = listOfPieces.at(randNb);
                        fo<<selectedPiece.first<<" ";
                        selectedPiece.second--;
                        if(selectedPiece.second==0){
                            listOfPieces.erase(listOfPieces.begin()+randNb);
                        }
                }
                        if(i<3) fo<<endl;
            }

        fo.close();
        initializeArmy(player);
    }
}

optional<Piece> Modele::Board::at(Position pos) const{
    return board.at(pos.getX()).at(pos.getY());
}
optional<Piece> & Modele::Board::at (Position pos){
    return board.at(pos.getX()).at(pos.getY());
}

bool Modele::Board::isInside(Position pos){
    return 0 <= pos.getX() && 0 <= pos.getY()
            && pos.getX() < (int)BOARD_SIZE && pos.getY() < (int)BOARD_SIZE;
}


inline bool Modele::Board::isPiece(Position pos){
    try {
        this->board.at(pos.getX()).at(pos.getY()).value();
    }  catch (const bad_optional_access &ex) {
        return false;
    }
    return true;
}

optional<Piece> Modele::Board::attack(optional<Piece> &piece, optional<Piece> &piece2){
    if(piece->getPlayer()==piece2->getPlayer())
        throw invalid_argument("Cannot attack own piece! Attacking piece is of player " + std::to_string(piece->getPlayer()) + " while defender's is of " + std::to_string(piece2->getSymbole())  );
    else if(piece2->getSymbole()=='W')
        throw invalid_argument("Cannot attack an obstacle");
    if(piece->getSymbole()=='2' && piece2->getSymbole()=='B')
        return piece;
    else if(piece2->getSymbole()=='B')
        return piece2;
    else if(piece->getSymbole()=='0' && piece2->getSymbole()=='9')
        return piece;
    else if(piece2->getSymbole()=='F')
        return piece;
    else if(piece->getSymbole()>piece2->getSymbole())
        return piece;
    else if(piece->getSymbole()<piece2->getSymbole())
        return piece2;
    else
        return optional<Piece>{};
}
bool Modele::Board::canMoveAt(Position pos, Direction direction, int distance){
    if(!isPiece(pos))
        throw invalid_argument("That's not a piece to move!");
    else if(!isInside(pos)){
        throw invalid_argument("Given position is out of bonds");
    }else if(at(pos).value().getSymbole() == 'B'||
             at(pos)->getSymbole() == 'F' ||
             at(pos)->getSymbole() == 'W')
        throw invalid_argument("Object impossible to move");
    else if(distance<=0)
        throw invalid_argument("Cannot move by 0 cases.");
    else if(distance!=1 && at(pos)->getSymbole()!='0'){
        throw invalid_argument("Only scout can move more than 1 case");
    }
    for(int i =1; i <= distance-1;i++ )
        switch(direction){
            case Direction::BOTTOM:{
                if(!isInside(Position{pos.getX()+i,pos.getY()}))
                    throw invalid_argument("Cannot move there");
                else if(isPiece(Position{pos.getX()+i,pos.getY()}))
                    throw invalid_argument("There's an obstacle in the way");
                break;
            }
            case Direction::TOP:{
                if(!isInside(Position{pos.getX()-i,pos.getY()}))
                    return false;
                else if(isPiece(Position{pos.getX()-i,pos.getY()}))
                    throw invalid_argument("There's an obstacle in the way");
                break;
            }
            case Direction::RIGHT:{
                if(!isInside(Position{pos.getX(),pos.getY()+i}))
                    throw invalid_argument("Cannot move there");
                else if(isPiece(Position{pos.getX(),pos.getY()+i}))
                    throw invalid_argument("There's an obstacle in the way");
                break;
            }
            case Direction::LEFT:{
                if(!isInside(Position{pos.getX(),pos.getY()-i}))
                    throw invalid_argument("Cannot move there");
                else if(isPiece(Position{pos.getX(),pos.getY()-i}))
                    throw invalid_argument("There's an obstacle in the way");
                break;
            }
    }
    return true;
}



void Modele::Board::move(Position pos, Direction direction, int distance){
    if(canMoveAt(pos,direction,distance)){
        switch(direction){
            case Direction::BOTTOM:{
                Position moveAt{pos.getX()+distance,pos.getY()};
                at(moveAt) = attack(at(pos),at(moveAt));
                break;
            }
            case Direction::TOP:{
                Position moveAt{pos.getX()-distance,pos.getY()};
                at(moveAt) = attack(at(pos),at(moveAt));
                break;
            }
            case Direction::LEFT:{
                Position moveAt{pos.getX(),pos.getY()-distance};
                at(moveAt) = attack(at(pos),at(moveAt));
                break;
            }
            case Direction::RIGHT:{
                Position moveAt{pos.getX(),pos.getY()+distance};
                at(moveAt) = attack(at(pos),at(moveAt));
                break;
            }
        }
    at(pos)=optional<Piece>{nullopt};
    }
}
bool Modele::Board::isGameOver(){
    int flags=0;
    bool player1=false;
    bool player2=false;
    for(int i = 0 ; i<(int)BOARD_SIZE;i++){
        for(int j = 0; j <(int)BOARD_SIZE;j++){
            if(isPiece(Position{i,j})
                    && at(Position{i,j})->getSymbole()=='F')
                flags++;
            if(at(Position{i,j})->getSymbole()!='F' && at(Position{i,j})->getSymbole()!='B'){
                if(!player1 && at(Position(i,j))->getPlayer()==1){
                    player1=true;
                }
                else if(!player2 && at(Position(i,j))->getPlayer()==2){
                    player2=true;
                }
            }
        }
    }
    return (flags!=2 || !(player1 && player2));

}
unsigned Modele::Board::getWinner(){

    for(int i = 0 ; i<(int) BOARD_SIZE;i++){
        for(int j = 0; j <(int) BOARD_SIZE;j++){
            if(isPiece(Position{i,j}) && at(Position{i,j})->getSymbole()=='F')
                return at(Position{i,j})->getPlayer();
        }
    }
    return -1;
}

string Modele::Board::to_string(unsigned player){
    string result = "";

    if(player==2){
    for(unsigned i=0; i<board.size(); i++){
        for(unsigned j=0; j<board.size(); j++){
            if(board[i][j].has_value()){
                if(board[i][j]->getPlayer()==player){
            result.push_back(board[i][j]->getSymbole());
                }else{
                    result.append("?");
                }
            result.append(" ");
            }else{
                result.append("  ");
            }
        }
        result.append("\n");
    }
    }else{
        for(int i=board.size()-1; i>=0; i--){
            for(int j=board.size()-1; j>=0; j--){
                if(board[i][j].has_value()){
                    if(board[i][j]->getPlayer()==player){
                result.push_back(board[i][j]->getSymbole());
                    }else{
                        result.append("?");
                    }
                result.append(" ");
                }else{
                    result.append("  ");
                }
            }
            result.append("\n");
        }
    }
    return result;
}
