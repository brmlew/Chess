#include "piece.h"

Piece::Piece(Colour colour, int r, int c, PieceType type):
colour{colour}, r{r}, c{c}, piecetype{type} {
    Coordinate location {r, c};
    State signal {StateType::Move, type, colour, location};
    this->setState(signal);
}

int Piece::getRow(){
    return this->r;
}

int Piece::getCol(){
    return this->c;
}

void Piece::setRow(int r){
    this->r = r;
}

void Piece::setCol(int c) {
    this->c = c;
}

void Piece::setType(PieceType type) {
    this->piecetype = type;
}

Colour Piece::getColour() {
    return this->colour;
}

PieceType Piece::getType() {
    return this->piecetype;
}

void Piece::notify(Subject<Info, State> &whoFrom) {
    if (whoFrom.getState().state == StateType::Nothing) {
        return;
    }
    else if (whoFrom.getState().state == StateType::Move) {
        this->notifyObservers();
        std::cout << "moving notification" << std::endl;
    }
    else if (whoFrom.getState().state == StateType::Attack) {
        this->notifyObservers();
    }
    else {
        this->notifyObservers();
    }
}

Info Piece::getInfo() const {
    Coordinate location {this->r, this->c};
    Info pieceInfo {this->colour, this->piecetype, location};
    return pieceInfo;
}

