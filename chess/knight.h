#ifndef KNIGHT_H
#define KNIGHT_H

#include <cmath>

#include "piece.h"

class Knight : public Piece {
    public:
    Knight(Colour colour, int r, int c, PieceType type);
    bool legalMove(Coordinate start, Coordinate end) override;
};

#endif
