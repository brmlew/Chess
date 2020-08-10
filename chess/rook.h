#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
    public:
    Rook(Colour colour, int r, int c, PieceType type);
    bool legalMove(Coordinate start, Coordinate end) override;
};

#endif
