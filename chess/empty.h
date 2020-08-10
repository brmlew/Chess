#ifndef EMPTY_H
#define EMPTY_H

#include "piece.h"

class Empty : public Piece {
    public:
    Empty(Colour colour, int r, int c, PieceType type);
    bool legalMove(Coordinate start, Coordinate end) override;
};

#endif
