#include <Board.hpp>
#include <Piece.hpp>
#include <fstream>
#include <optional>
#include <iostream>

using namespace std;
void Modele::Board::initializeArmy(){
    //A FAIRE POUR QUE CA MARCHE !!!!
    listOfPieces={pair<char, int>()};
    ifstream fi("player.txt");

    if(fi.good()){
        //AJOUTER VERIFICATION listOfPiece
        string line;
        unsigned lineNb=0;
        while(getline(fi, line)){
            for(unsigned i=0; i<BOARD_SIZE; i++){
                char symbol = line.erase(line.find(" "), line.find(" ")).at(0);
                optional<Piece> piece((Piece(symbol)));
                board[lineNb][i] = piece;
            }
            lineNb++;
        }
    }else{
        ofstream fo("player.txt");

        for(unsigned i=0; i<4; i++){
            for(unsigned j=0; j<BOARD_SIZE; j++){
                    unsigned randNb = rand()%listOfPieces.size();
                    pair<char, int> selectedPiece(listOfPieces.at(randNb));
                    cout<<selectedPiece.first<<endl;
                    fo<<selectedPiece.first<<" ";
                    selectedPiece.second--;
                    if(selectedPiece.second==0){
                        listOfPieces.erase(listOfPieces.cbegin()+randNb);
                    }
            }
            fo<<endl;
        }

        fo.close();
        initializeArmy();
    }
}

Modele::Board::Board(){
    initializeArmy();
}


