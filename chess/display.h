#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

#include "observer.h"
#include "subject.h"
#include "info.h"

class Piece;

class Display: public Observer<Info, State> {
    std::vector<std::vector<char>> TextDisplay;
    const int boardSize = 10;
    public:
    Display(const int dim);
    void notify(Subject<Info, State> &whoNotified) override;
    friend std::ostream &operator<<(std::ostream &out, const Display &td);
};

#endif
