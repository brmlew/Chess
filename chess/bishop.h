#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
    public:
    Bishop(Colour colour, int r, int c, PieceType type);
    bool legalMove(Coordinate start, Coordinate end) override;
};

#endif
