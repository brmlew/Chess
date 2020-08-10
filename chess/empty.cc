#include "empty.h"

Empty::Empty(Colour colour, int r, int c, PieceType type) : Piece(colour, r, c, type) {}

bool Empty::legalMove(Coordinate start, Coordinate end) {
    return false;
}