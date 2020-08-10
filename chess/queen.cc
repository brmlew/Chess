#include "queen.h"
#include <cmath>

Queen::Queen(Colour colour, int r, int c, PieceType type) : 
    Piece{colour, r, c, type} {
    Coordinate location {r,c};
    this->setState({StateType::Move, PieceType::Queen, colour, location});
}

bool Queen::legalMove(Coordinate start, Coordinate end) {
    if (start.col == end.col && start.row != end.row) return true;
    else if (start.row == end.row && start.col != end.col) return true;
    else if (abs(end.row - start.row) == abs(end.col - start.col)) return true;
    return false;
}
