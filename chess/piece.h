#ifndef PIECE_H
#define PIECE_H

#include <cmath>

#include "subject.h"
#include "state.h"
#include "move.h"
#include "observer.h"
#include "info.h"

class Piece: public Subject<Info, State>, public Observer<Info, State> {
    protected:
    Colour colour =  Colour::NoColour;
    int r, c;
    PieceType piecetype;
    public:
    Piece(Colour colour, int r, int c, PieceType type);
    virtual bool legalMove(Coordinate start, Coordinate end) = 0;
    Colour getColour();
    PieceType getType();
    int getRow();
    int getCol();
    void setRow(int r);
    void setCol(int c);
    void setType(PieceType type);
    void notify(Subject<Info, State> &whoFrom) override;
    Info getInfo() const override;
};

#endif
