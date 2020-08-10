#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
    public:
    Queen(Colour colour, int r, int c, PieceType type);
    bool legalMove(Coordinate start, Coordinate end) override;
};

#endif
