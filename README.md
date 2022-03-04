# Stratego
## Start :
1. Run ```make``` in the project directory.
## Technical informations :
The project respects the MVP architecture structure.
### View part :
The project have got two views and controlers : one for graphical interface and an other one for console interface.
(coming soon)
### Facade part :
The Facade manage the players turns, the states and interactions between GUI/CLI Views and Board model.
### Model part :
#### Board :
##### Board structure :
The board manage a 2D std::array of std::optional Pieces (```std::array<std::array<std::optional<Piece>>>```). With this structure, we can easy-way detect if a board case is empty or not and access to a case without loop.
##### Forbidden locations :
To manage forbidden cases (e.g. : water cases), we will just put a Piece with 'W' symbol.
##### Movables/unmovables pieces :
To know if a piece is movable, we just have to check if piece symbol is an alphabetic or numeric char(alphabetics are unmovables and numerics movables).
##### Moves :
Each turn, a player chooses a piece and a direction. If the piece can move more than one case (scout), the player add a move distance.
##### Enemy detection :
After player chooses a move, the program will check (case by case if the move distance is bigger than 1) if a ennemy is on a case (by calling x and y element in board array), no more move is allowed for this turn and the program check wich piece(s) have to leave the board.
##### Game over :
Game is over when the flag piece is catch.



