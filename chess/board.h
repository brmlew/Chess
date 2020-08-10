#ifndef BOARD_H
#define BOARD_H

#include <string>

#include "piece.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"
#include "display.h"
#include "info.h"
#include "subject.h"
#include "empty.h"

class Display;
template <typename InfoType, typename StateType> class Observer;

class Board {
    Piece * pieces[8][8];
    Display * theDisplay = nullptr;
    Observer<Info, State> *ob = nullptr;
    
    public:
    ~Board();
    bool castle(Coordinate start, Coordinate end);
    bool pawnAttack(Coordinate start, Coordinate end);
    bool checkPiece(Colour colour, Coordinate end);
    bool checkPath(PieceType type, Coordinate start, Coordinate end);
    void pawnPromo(Piece & piece);
    void setObserver(Observer<Info, State> *ob);
    void setup(int &turn);
    void defaultSetup();
    void placePiece(Piece & piece, Coordinate cell);
    void deletePiece(Coordinate cell);
    bool movePiece(Coordinate start, Coordinate end, int turn);
    void moveCompPiece();
    bool check(const Colour colour, King & enemyKing);
    bool checkmate(const Colour colour, King & enemyKing);
    bool stalemate(const Colour colour, King & enemyKing);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
