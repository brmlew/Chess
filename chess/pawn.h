#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
    public:
    Pawn(Colour colour, int r, int c, PieceType type);
    bool legalMove(Coordinate start, Coordinate end) override;
};

#endif
