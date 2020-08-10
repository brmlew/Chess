#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
    std::vector<Move> possMoves; 
    public:
    King(Colour colour, int r, int c, PieceType type);
    bool legalMove(Coordinate start, Coordinate end) override;
    void updatePossMoves();
    bool noMoves();
};

#endif
