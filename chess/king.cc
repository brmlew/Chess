#include "king.h"
#include <cmath>

King::King(Colour colour, int r, int c, PieceType type) : Piece(colour, r, c, type) {
    this->updatePossMoves();
}

bool King::legalMove(Coordinate start, Coordinate end) {
    if (abs(start.row - end.row) <= 1 && abs(start.col - end.row) <= 1 &&
    !(start.row - end.row == 0 && start.col - end.col == 0)) return true;
    return false;
}

void King::updatePossMoves() {
    this->possMoves.empty();
    int row = this->getRow();
    int col = this->getCol();
    Coordinate current = {row, col};
    Coordinate up = {row+1, col};
    Coordinate down = {row-1, col};
    Coordinate left = {row, col-1}; 
    Coordinate right = {row, col+1};
    if (legalMove(current, up)) {
        Move upwards = {current, up};
        possMoves.emplace_back(upwards);
    }
    if (legalMove(current, down)) {
        Move downwards = {current, down};
        possMoves.emplace_back(downwards);
    }
    if (legalMove(current, left)) {
        Move leftwards = {current, up};
        possMoves.emplace_back(leftwards);
    }
    if (legalMove(current, right)) {
        Move rightwards = {current, up};
        possMoves.emplace_back(rightwards);
    }
}

bool King::noMoves() {
    if (this->possMoves.empty()) {
        return true;
    } else {
        return false;
    }
}
