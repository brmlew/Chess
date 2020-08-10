#include "display.h"

Display::Display(const int dim): boardSize{dim} {
    
    this->TextDisplay.clear();

    std::vector<char> row1;
    row1.push_back('1');
    row1.push_back(' ');
    row1.push_back('R');
    row1.push_back('N');
    row1.push_back('B');
    row1.push_back('K');
    row1.push_back('Q');
    row1.push_back('B');
    row1.push_back('N');
    row1.push_back('R');
    
    std::vector<char> row2;
    row2.push_back('2');
    row2.push_back(' ');
    for (int i = 0; i < 8; i++) {
        row2.push_back('P');
    }

    std::vector<char> row3;
    row3.push_back('3');
    row3.push_back(' ');
    for (int i = 0; i < 4; i++) {
        row3.push_back('_');
        row3.push_back(' ');
    }
    
    std::vector<char> row4;
    row4.push_back('4');
    row4.push_back(' ');
    for (int i = 0; i < 4; i++) {
        row4.push_back(' ');
        row4.push_back('_');
    } 

    std::vector<char> row5;
    row5.push_back('5');
    row5.push_back(' ');
    for (int i = 0; i < 4; i++) {
        row5.push_back('_');
        row5.push_back(' ');
    }

    std::vector<char> row6;
    row6.push_back('6');
    row6.push_back(' ');
    for (int i = 0; i < 4; i++) {
        row6.push_back(' ');
        row6.push_back('_');
    }

    std::vector<char> row7;
    row7.push_back('7');
    row7.push_back(' ');
    for (int i = 0; i < 8; i++) {
        row7.push_back('p');
    } 

    std::vector<char> row8;
    row8.push_back('8');
    row8.push_back(' ');
    row8.push_back('r');
    row8.push_back('n');
    row8.push_back('b');
    row8.push_back('k');
    row8.push_back('q');
    row8.push_back('b');
    row8.push_back('n');
    row8.push_back('r');

    std::vector<char> rowSpace;
    for (int i = 0; i < 10; i++) {
        rowSpace.push_back(' ');
    }

    std::vector<char> columnLabel;
    columnLabel.push_back(' ');
    columnLabel.push_back(' ');
    columnLabel.push_back('a');
    columnLabel.push_back('b');
    columnLabel.push_back('c');
    columnLabel.push_back('d');
    columnLabel.push_back('e');
    columnLabel.push_back('f');
    columnLabel.push_back('g');
    columnLabel.push_back('h');
    
    this->TextDisplay.push_back(row8);
    this->TextDisplay.push_back(row7);
    this->TextDisplay.push_back(row6);
    this->TextDisplay.push_back(row5);
    this->TextDisplay.push_back(row4);
    this->TextDisplay.push_back(row3);
    this->TextDisplay.push_back(row2);
    this->TextDisplay.push_back(row1);
    this->TextDisplay.push_back(rowSpace);
    this->TextDisplay.push_back(columnLabel);
}

void Display::notify(Subject<Info, State> &whoNotified) {
    if (whoNotified.getState().state == StateType::Move) {
        this->TextDisplay[whoNotified.getInfo().location.row][whoNotified.getInfo().location.col] = 'C';
        std::cout << "notified" << std::endl;
    } else if (whoNotified.getState().state == StateType::Attack) {
        this->TextDisplay[whoNotified.getInfo().location.row]
        [whoNotified.getInfo().location.col] = 'C';
    } else {
        // pawn promo
    }
}

std::ostream &operator<<(std::ostream &out, const Display &td) {
    int dimension = td.boardSize;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            out << td.TextDisplay[i][j];
        }
        out << std::endl;
    }
    return out;
}

