#include "bishop.h"
#include <cmath>

Bishop::Bishop(Colour colour, int r, int c, PieceType type) : Piece(colour, r, c, type) {}

bool Bishop::legalMove(Coordinate start, Coordinate end) {
    if (abs(start.row - end.row) == abs(start.col - end.col) && 
    !(start.row == end.row && start.col == end.col)) return true;
    return false;
}
