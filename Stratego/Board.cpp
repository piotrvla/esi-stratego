#include <Board.hpp>
#include <Piece.hpp>
#include <fstream>
#include <optional>
#include <algorithm>
#include <stdexcept>
#include <time.h>

using namespace std;
void Modele::Board::initializeArmy(){
    listOfPieces={pair('9',1), pair('8',1),pair('7',2),pair('6',3),pair('5',4),
                pair('4',4),pair('3',4),pair('2',5),pair('1',8),
                pair('0',1),pair('D',1),pair('B',6)};

    ifstream fi("player.txt");

    if(fi.good()){
        string line;
        unsigned lineNb=0;
        while(getline(fi, line)){
            for(unsigned i=0; i<BOARD_SIZE; i++){
                if(line.size()<2) throw out_of_range("Not enough file input.");
                char selectedSymbol = line.at(0);
                line.erase(0, 2);
                vector<pair<char, int>>::iterator availibilitySymbol = find_if(listOfPieces.begin(), listOfPieces.end(), [selectedSymbol](pair<char, int> currentSymbol){
                    return selectedSymbol == currentSymbol.first;
                });

                if(availibilitySymbol==listOfPieces.end()) throw out_of_range("Piece not found.");
                if(availibilitySymbol->second==0) throw out_of_range("No more piece");
                availibilitySymbol->second--;

                optional<Piece> piece((Piece(selectedSymbol)));
                board[lineNb][i] = piece;
            }
            lineNb++;
        }
    }else{
        ofstream fo("player.txt");
        srand(time(NULL));

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
        initializeArmy();
    }
}

Modele::Board::Board(){
    initializeArmy();
}


