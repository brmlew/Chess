#include "rook.h"

Rook::Rook(Colour colour, int r, int c, PieceType type) : Piece(colour, r, c, type) {}

bool Rook::legalMove(Coordinate start, Coordinate end) {
    if (start.row == end.row && start.col != end.col) return true;
    if (start.col == end.col && start.row != end.row) return true;
    return false;
}
