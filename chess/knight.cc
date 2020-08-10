#include "knight.h"

Knight::Knight(Colour colour, int r, int c, PieceType type) : Piece(colour, r, c, type) {}

bool Knight::legalMove(Coordinate start, Coordinate end) {
    if (std::abs(end.row - start.row) == 2 && std::abs(end.col - start.col) == 1) return true;
    else if (std::abs(end.row - start.row) == 1 && std::abs(end.col - start.col) == 2) return true;
    return false;
}
