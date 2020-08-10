#include "pawn.h"

Pawn::Pawn(Colour colour, int r, int c, PieceType type) : Piece(colour, r, c, type) {}

bool Pawn::legalMove(Coordinate start, Coordinate end) {
    if (this->getColour() == Colour::White) {
        if (end.row - start.row == 1 && start.col == end.col) return true;
        else if (start.row == 2 && end.row - start.row == 2 &&
        start.col == end.col) return true;
        return false;
    }
    else if (this->getColour() == Colour::Black) {
        if (start.row - end.row == 1 && start.col == end.col) return true;
        else if (start.row == 7 && start.row - end.row == 2 &&
        start.col == end.col) return true;
    }
    return false;
}
