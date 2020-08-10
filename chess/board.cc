#include "board.h"

// board dtor
Board::~Board() {
    delete [] this->pieces;
    delete this->theDisplay;
}

bool Board::castle(Coordinate start, Coordinate end) {
    
    if (pieces[start.row-1][start.col-1]->getColour() == Colour::White) {
        Coordinate pos1{1,1};
        Coordinate pos2{1,4};
        Coordinate pos3{1,8};
        Coordinate pos4{1,6};
        if (start.row == 1 && start.col == 5 && end.row == 1 && end.col == 3 &&
        pieces[0][0]->getType() == PieceType::Rook && pieces[0][0]->getColour() == Colour::White &&
        checkPath(PieceType::Rook, pos1, pos2)) {
            
            pieces[start.row-1][start.col-1]->setRow(end.row);
            pieces[start.row-1][start.col-1]->setCol(end.col);
            pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];

            Empty *emptyCell1 = new Empty(Colour::NoColour, start.row, start.col, PieceType::Empty);
            pieces[start.row-1][start.col-1] = emptyCell1;

            pieces[0][0]->setCol(4);
            pieces[0][3] = pieces[0][0];

            Empty *emptyCell2 = new Empty(Colour::NoColour, 1, 1, PieceType::Empty);
            pieces[1][1] = emptyCell2;
            return true;
        }
        else if (start.row == 1 && start.col == 5 && end.row == 1 && end.col == 7 &&
        pieces[0][7]->getType() == PieceType::Rook && pieces[0][7]->getColour() == Colour::White &&
        checkPath(PieceType::Rook, pos3, pos4)) {
            pieces[start.row-1][start.col-1]->setRow(end.row);
            pieces[start.row-1][start.col-1]->setCol(end.col);
            pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];

            Empty *emptyCell1 = new Empty(Colour::NoColour, start.row, start.col, PieceType::Empty);
            pieces[start.row-1][start.col-1] = emptyCell1;

            pieces[0][7]->setCol(6);
            pieces[0][5] = pieces[0][7];

            Empty *emptyCell2 = new Empty(Colour::NoColour, 1, 8, PieceType::Empty);
            pieces[0][7] = emptyCell2;
            return true;
        }
    }
    else if (pieces[start.row-1][start.col-1]->getColour() == Colour::Black) {
        Coordinate pos1{8,1};
        Coordinate pos2{8,4};
        Coordinate pos3{8,8};
        Coordinate pos4{8,6};
        if (start.row == 8 && start.col == 5 && end.row == 8 && end.col == 3 &&
        pieces[7][0]->getType() == PieceType::Rook && pieces[7][0]->getColour() == Colour::Black &&
        checkPath(PieceType::Rook, pos1, pos2)) {
            pieces[start.row-1][start.col-1]->setRow(end.row);
            pieces[start.row-1][start.col-1]->setCol(end.col);
            pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];

            Empty *emptyCell1 = new Empty(Colour::NoColour, start.row, start.col, PieceType::Empty);
            pieces[start.row-1][start.col-1] = emptyCell1;

            pieces[7][0]->setCol(4);
            pieces[7][3] = pieces[7][0];

            Empty *emptyCell2 = new Empty(Colour::NoColour, 8, 1, PieceType::Empty);
            pieces[8][1] = emptyCell2;
            return true;
        }
        else if (start.row == 8 && start.col == 5 && end.row == 8 && end.col == 7 &&
        pieces[7][7]->getType() == PieceType::Rook && pieces[7][7]->getColour() == Colour::Black &&
        checkPath(PieceType::Rook, pos3, pos4)) {
            pieces[start.row-1][start.col-1]->setRow(end.row);
            pieces[start.row-1][start.col-1]->setCol(end.col);
            pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];

            Empty *emptyCell1 = new Empty(Colour::NoColour, start.row, start.col, PieceType::Empty);
            pieces[start.row-1][start.col-1] = emptyCell1;

            pieces[7][7]->setCol(6);
            pieces[7][5] = pieces[7][7];

            Empty *emptyCell2 = new Empty(Colour::NoColour, 8, 8, PieceType::Empty);
            pieces[7][7] = emptyCell2;
            return true;
        }
    }
    return false;
}

bool Board::pawnAttack(Coordinate start, Coordinate end) {
    if (pieces[start.row-1][start.col-1]->getColour() == Colour::White) {
        // regular attacking
        if (end.row - start.row == 1 && abs(end.col - start.col) == 1 &&
        pieces[end.row-1][end.col-1]->getType() != PieceType::Empty &&
        pieces[end.row-1][end.col-1]->getColour() != pieces[start.row-1][start.col-1]->getColour()) {

            deletePiece(end);
            pieces[start.row-1][start.col-1]->setRow(end.row);
            pieces[start.row-1][start.col-1]->setCol(end.col);
            pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];

            Empty *emptyCell = new Empty(Colour::NoColour, start.row, start.col, PieceType::Empty);
            this->pieces[start.row-1][start.col-1] = emptyCell;
            return true;
        }
        // en passant
        else if (start.row == 4 && pieces[4][start.col-1]->getType() == PieceType::Pawn &&
        pieces[4][start.col-1]->getColour() == Colour::Black &&
        end.row - start.row == 1 && abs(end.col - start.col) == 1) {
            Coordinate take{5, start.col};
            deletePiece(take);
            pieces[start.row-1][start.col-1]->setRow(end.row);
            pieces[start.row-1][start.col-1]->setCol(end.col);
            pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];
            deletePiece(start);
            return true;
        }
        return false;
    }
    else if (pieces[start.row-1][start.col-1]->getColour() == Colour::Black) {
        // regular attacking
        if (start.row - end.row == 1 && abs(end.col - start.col) == 1 &&
        pieces[end.row-1][end.col-1]->getType() != PieceType::Empty &&
        pieces[end.row-1][end.col-1]->getColour() != pieces[start.row-1][start.col-1]->getColour()) {

            deletePiece(end);
            pieces[start.row-1][start.col-1]->setRow(end.row);
            pieces[start.row-1][start.col-1]->setCol(end.col);
            pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];

            Empty *emptyCell = new Empty(Colour::NoColour, start.row, start.col, PieceType::Empty);
            this->pieces[start.row-1][start.col-1] = emptyCell;
            return true;
        }
        // en passant
        else if (start.row == 5 && pieces[3][start.col-1]->getType() == PieceType::Pawn &&
        pieces[3][start.col-1]->getColour() == Colour::Black &&
        start.row - end.row == 1 && abs(end.col - start.col) == 1) {
            Coordinate take{4, start.col};
            deletePiece(take);
            pieces[start.row-1][start.col-1]->setRow(end.row);
            pieces[start.row-1][start.col-1]->setCol(end.col);
            pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];
            deletePiece(start);
            return true;
        }
        return false;
    }
    return false;
}

bool Board::checkPiece(Colour colour, Coordinate end) {
    if (pieces[end.row-1][end.col-1]->getType() == PieceType::Empty) return true;
    if (pieces[end.row-1][end.col-1]->getColour() == colour) return false;
    return true;
}

// function checks along the straight line path between the starting and
// ending coordinate
// requires that the start and end coordinates are valid moves
// returns true if the path is clear (no pieces inbetween)
bool Board::checkPath(PieceType type, Coordinate start, Coordinate end) {
    if (type == PieceType::King || type == PieceType::Knight) {
        return true;
    }
    int xDiff = start.col - end.col;
    int yDiff = start.row - end.row;
    std::cout << "x:" << xDiff << " y:" << yDiff << std::endl;
    if (xDiff == 0 && yDiff == 0) {
        return true;
    }
    // if the path is a straight horizontal line
    if (yDiff == 0) {
        if (xDiff < 0) {
            for (int i = start.col + 1; i <= end.col; i++) {
                if (pieces[start.row-1][i-1]->getType() != PieceType::Empty) {
                    return false;
                }
            }
        } else {
            for (int i = start.col - 1; i >= end.col; i--) {
                if (pieces[start.row-1][i-1]->getType() != PieceType::Empty) {
                    return false;
                }
            }
        }
    } 
    // if the path is a straight vertical line
    else if (xDiff == 0) {
        if (yDiff < 0) {
            for (int i = start.row + 1; i <= end.row; i++) {
                if (pieces[i-1][start.col-1]->getType() != PieceType::Empty) {
                    return false;
                }
            }
        } else {
            for (int i = start.row - 1; i >= end.row; i--) {
                if (pieces[i-1][start.col-1]->getType() != PieceType::Empty) {
                    return false;
                }
            }
        }
    }
    // if the path is a NE diagonal line
    else if (xDiff < 0 && yDiff < 0) {
        int sRow = start.row + 1;
        int sCol = start.col + 1;
        while (sRow != end.row && sCol != end.col) {
            if (pieces[sRow-1][sCol-1]->getType() != PieceType::Empty) {
                return false;
            }
            sRow++;
            sCol++;
        }
    }
    // if the path is a NW diagonal line
    else if (yDiff < 0 && xDiff > 0) {
        int sRow = start.row + 1;
        int sCol = start.col - 1;
        std::cout << "r:" << sRow << " c:" << sCol;
        std::cout << " er:" << end.row << " ec:" << end.col;

        while (sRow != end.row - 1 && sCol != end.col + 1) {
            if (pieces[sRow-1][sCol-1]->getType() != PieceType::Empty) {
                return false;
            }
            sRow++;
            sCol--;
        }
    }
    // if the path is a SE diagonal line
    else if (yDiff > 0 && xDiff < 0) {
        int sRow = start.row - 1;
        int sCol = start.col + 1;
        while (sRow != end.row + 1 && sCol != end.col - 1) {
            if (pieces[sRow-1][sCol-1]->getType() != PieceType::Empty) {
                return false;
            }
            sRow--;
            sCol++;
        }
    }
    // if the path is a SW diagonal line
    else if (yDiff > 0 && xDiff > 0) {
        int sRow = start.row - 1;
        int sCol = start.col - 1;
        while (sRow != end.row + 1 && start.col != end.col + 1) {
            if (pieces[sRow-1][sCol-1]->getType() != PieceType::Empty) {
                return false;
            }
            sRow--;
            sCol--;
        }
    }
    return true;
}

void Board::pawnPromo(Piece & piece) {
    char input;
    std::cin >> input;
    if (input == 'Q') {
        Queen *newPiece = new Queen(piece.getColour(), piece.getRow(), piece.getCol(), PieceType::Queen);
        piece = *newPiece;
    }
    else if (input == 'R') {
        Rook *newPiece = new Rook(piece.getColour(), piece.getRow(), piece.getCol(), PieceType::Rook);
        piece = *newPiece;
    }
    else if (input == 'B') {
        Bishop *newPiece = new Bishop(piece.getColour(), piece.getRow(), piece.getCol(), PieceType::Bishop);
        piece = *newPiece;
    }
    else if (input == 'N') {
        Knight *newPiece = new Knight(piece.getColour(), piece.getRow(), piece.getCol(), PieceType::Knight);
        piece = *newPiece;
    }
}

// attaching the observer
void Board::setObserver(Observer<Info, State> *ob) {
    this->ob = ob;
}

void Board::setup(int &turn) {
    std::string input;
    char symbol;
    char piece;
    int row;
    int col;
    std::cin >> input;
    if (input == "done") return;
    
    // adding a piece
    if (input == "+") {
        std::cin >> piece;
        std::cin >> symbol;
        std::cin >> row;

        if (symbol == 'a') col = 1;
        else if (symbol == 'b') col = 2;
        else if (symbol == 'c') col = 3;
        else if (symbol == 'd') col = 4;
        else if (symbol == 'e') col = 5;
        else if (symbol == 'f') col = 6;
        else if (symbol == 'g') col = 7;
        else if (symbol == 'h') col = 8;

        if (piece == 'K') {
            King *newKing = new King(Colour::White, row, col, PieceType::King);
            Coordinate cell{row, col};
            placePiece(*newKing, cell);
        }
        else if (piece == 'Q') {
            Queen *newQueen = new Queen(Colour::White, row, col, PieceType::Queen);
            Coordinate cell{row, col};
            placePiece(*newQueen, cell);
        }
        else if (piece == 'R') {
            Rook *newRook = new Rook(Colour::White, row, col, PieceType::Rook);
            Coordinate cell{row, col};
            placePiece(*newRook, cell);
        }
        else if (piece == 'N') {
            Knight *newKnight = new Knight(Colour::White, row, col, PieceType::Knight);
            Coordinate cell{row, col};
            placePiece(*newKnight, cell);
        }
        else if (piece == 'B') {
            Bishop *newBishop = new Bishop(Colour::White, row, col, PieceType::Bishop);
            Coordinate cell{row, col};
            placePiece(*newBishop, cell);
        }
        else if (piece == 'P') {
            Pawn *newPawn = new Pawn(Colour::White, row, col, PieceType::Pawn);
            Coordinate cell{row, col};
            placePiece(*newPawn, cell);
        }
        else if (piece == 'k') {
            King *newKing = new King(Colour::Black, row, col, PieceType::King);
            Coordinate cell{row, col};
            placePiece(*newKing, cell);
        }
        else if (piece == 'q') {
            Queen *newQueen = new Queen(Colour::Black, row, col, PieceType::Queen);
            Coordinate cell{row, col};
            placePiece(*newQueen, cell);
        }
        else if (piece == 'r') {
            Rook *newRook = new Rook(Colour::Black, row, col, PieceType::Rook);
            Coordinate cell{row, col};
            placePiece(*newRook, cell);
        }
        else if (piece == 'n') {
            Knight *newKnight = new Knight(Colour::Black, row, col, PieceType::Knight);
            Coordinate cell{row, col};
            placePiece(*newKnight, cell);
        }
        else if (piece == 'b') {
            Bishop *newBishop = new Bishop(Colour::Black, row, col, PieceType::Bishop);
            Coordinate cell{row, col};
            placePiece(*newBishop, cell);
        }
        else if (piece == 'p') {
            Pawn *newPawn = new Pawn(Colour::Black, row, col, PieceType::Pawn);
            Coordinate cell{row, col};
            placePiece(*newPawn, cell);
        }
        std::cout << this;
    }
    // removing a piece
    else if (symbol == '-') {
        std::cin >> symbol;
        std::cin >> row;

        if (symbol == 'a') col = 1;
        else if (symbol == 'b') col = 2;
        else if (symbol == 'c') col = 3;
        else if (symbol == 'd') col = 4;
        else if (symbol == 'e') col = 5;
        else if (symbol == 'f') col = 6;
        else if (symbol == 'g') col = 7;
        else if (symbol == 'h') col = 8;

        Coordinate cell{row, col};
        deletePiece(cell);
    }
    // changing the turn
    else if (symbol == '=') {
        std::string colour;
        std::cin >> colour;
        if (colour == "White") {
            turn = 0;
        }
        else if (colour == "Black") {
            turn = 1;
        }
    }
}

// reset board back to original state
void Board::defaultSetup() {
    if (theDisplay) delete this->theDisplay;
    theDisplay = new Display(10);

    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Empty *emptyCell = new Empty(Colour:: NoColour, i, j, PieceType::Empty);
            this->pieces[i][j] = emptyCell;
            //this->pieces[i][j]->attach(theDisplay);
        }
    }
    
    Rook *newRookB1 = new Rook(Colour::Black, 8, 1, PieceType::Rook);
    this->pieces[7][0] = newRookB1;

    Knight *newKnightB1 = new Knight(Colour::Black, 8, 2, PieceType::Knight);
    this->pieces[7][1] = newKnightB1;

    Bishop *newBishopB1 = new Bishop(Colour::Black, 8, 3, PieceType::Bishop);
    this->pieces[7][2] = newBishopB1;

    Queen *newQueenB = new Queen(Colour::Black, 8, 4, PieceType::Queen);
    this->pieces[7][3] = newQueenB;

    King *newKingB = new King(Colour::Black, 8, 5, PieceType::King);
    this->pieces[7][4] = newKingB;

    Bishop *newBishopB2 = new Bishop(Colour::Black, 8, 6, PieceType::Bishop);
    this->pieces[7][5] = newBishopB2;

    Knight *newKnightB2 = new Knight(Colour::Black, 8, 7, PieceType::Knight);
    this->pieces[7][6] = newKnightB2;

    Rook *newRookB2 = new Rook(Colour::Black, 8, 8, PieceType::Rook);
    this->pieces[7][7] = newRookB2;

    for (int i = 0; i < 8; i++) {
        Pawn *newPawn = new Pawn(Colour::Black, 7, i+1, PieceType::Pawn);
        this->pieces[6][i] = newPawn;
    }

    for (int i = 0; i < 8; i++) {
        Pawn *newPawn = new Pawn(Colour::White, 2, i+1, PieceType::Pawn);
        this->pieces[1][i] = newPawn;
    }

    Rook *newRookW1 = new Rook(Colour::White, 1, 1, PieceType::Rook);
    this->pieces[0][0] = newRookW1;

    Knight *newKnightW1 = new Knight(Colour::White, 1, 2, PieceType::Knight);
    this->pieces[0][1] = newKnightW1;

    Bishop *newBishopW1 = new Bishop(Colour::White, 1, 3, PieceType::Bishop);
    this->pieces[0][2] = newBishopW1;

    Queen *newQueenW = new Queen(Colour::White, 1, 4, PieceType::Queen);
    this->pieces[0][3] = newQueenW;

    King *newKingW = new King(Colour::White, 1, 5, PieceType::King);
    this->pieces[0][4] = newKingW;

    Bishop *newBishopW2 = new Bishop(Colour::White, 1, 6, PieceType::Bishop);
    this->pieces[0][5] = newBishopW2;

    Knight *newKnightW2 = new Knight(Colour::White, 1, 7, PieceType::Knight);
    this->pieces[0][6] = newKnightW2;

    Rook *newRookW2 = new Rook(Colour::White, 1, 8, PieceType::Rook);
    this->pieces[0][7] = newRookW2;
}

void Board::placePiece(Piece & piece, Coordinate cell) {
    if (pieces[cell.row-1][cell.col-1]->getType() != PieceType::Empty) {
        deletePiece(cell);
        piece.setRow(cell.row);
        piece.setCol(cell.col);
        *pieces[cell.row-1][cell.col-1] = piece;
        return;
    }
    piece.setRow(cell.row);
    piece.setCol(cell.col);
    *pieces[cell.row-1][cell.col-1] = piece;
}

void Board::deletePiece(Coordinate cell) {
    Empty *emptyCell = new Empty(Colour::NoColour, cell.row, cell.col, PieceType::Empty);
    pieces[cell.row-1][cell.col-1] = emptyCell;
}

bool Board::movePiece(Coordinate start, Coordinate end, int turn) {
    //std::cout << "legal: " << pieces[start.row-1][start.col-1]->legalMove(start, end) << std::endl;
    //std::cout << "piece: " << checkPiece(pieces[start.row-1][start.col-1]->getColour(), end) << std::endl;
    //std::cout << "path: " << checkPath(pieces[start.row-1][start.col-1]->getType(), start, end) << std::endl;
    //std::cout << "turn: " << (turn == 0 && pieces[start.row-1][start.col-1]->getColour() == Colour::Black) << std::endl;
    if (pieces[start.row-1][start.col-1]->legalMove(start, end) &&
    checkPiece(pieces[start.row-1][start.col-1]->getColour(), end) &&
    checkPath(pieces[start.row-1][start.col-1]->getType(), start, end) &&
    !(turn == 0 && pieces[start.row-1][start.col-1]->getColour() == Colour::Black) &&
    !(turn == 1 && pieces[start.row-1][start.col-1]->getColour() == Colour::White)) {

        deletePiece(end);
        pieces[start.row-1][start.col-1]->setRow(end.row);
        pieces[start.row-1][start.col-1]->setCol(end.col);
        pieces[end.row-1][end.col-1] = pieces[start.row-1][start.col-1];

        Empty *emptyCell = new Empty(Colour::NoColour, start.row, start.col, PieceType::Empty);
        this->pieces[start.row-1][start.col-1] = emptyCell;

        if (pieces[end.row-1][end.col-1]->getType() == PieceType::Pawn) {
            if (pieces[end.row-1][end.col-1]->getColour() == Colour::White &&
            end.row == 8) {
                pawnPromo(*pieces[end.row-1][end.col-1]);
            }
            else if (pieces[end.row-1][end.col-1]->getColour() == Colour::Black && 
            end.row == 1) {
                pawnPromo(*pieces[end.row-1][end.col-1]);
            }
        }

        return true;
    }
    else if (pieces[start.row-1][start.col-1]->getType() == PieceType::King) {
        return castle(start, end);
    }
    else if (pieces[start.row-1][start.col-1]->getType() == PieceType::Pawn) {
        if (pawnAttack(start, end)) {
            if (pieces[end.row-1][end.col-1]->getType() == PieceType::Pawn) {
                if (pieces[end.row-1][end.col-1]->getColour() == Colour::White &&
                end.row == 8) {
                    pawnPromo(*pieces[end.row-1][end.col-1]);
                }
                else if (pieces[end.row-1][end.col-1]->getColour() == Colour::Black && 
                end.row == 1) {
                    pawnPromo(*pieces[end.row-1][end.col-1]);
                }
            }
        }
        return true;

    }
    return false;
}

void Board::moveCompPiece() {

}

// returns true if the current colour has checked the enemyKing
bool Board::check(const Colour colour, King & enemyKing) {
    int enemyRow = enemyKing.getRow();
    int enemyCol = enemyKing.getCol();
    Coordinate enemy = {enemyRow, enemyCol};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Coordinate current = {i, j};
            if (pieces[i][j]->getColour() == colour) {
                if (pieces[i][j]->legalMove(current, enemy)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// returns true if the enemy king is in checkmate
// essentially if it is checked and has no legal moves
bool Board::checkmate(const Colour colour, King & enemyKing) {
    if (check(colour, enemyKing) && enemyKing.noMoves()) {
        return true;
    } else {
        return false;
    }
}

// return true if the enemy king is in staleate
// essentially if it is not checked but has no legal moves
bool Board::stalemate(const Colour colour, King & enemyKing) {
    if (!check(colour, enemyKing) && enemyKing.noMoves()) {
        return true;
    } else {
        return false;
    }
}

// output operator that calls the output operator for textdisplay
std::ostream &operator<<(std::ostream &out, const Board &b) {
    for (int i = 7; i >= 0; i--) {
        out << i+1 << " ";
        for (int j = 0; j < 8; j++) {
            if (b.pieces[i][j]->getType() == PieceType::Empty) {
                if (j%2 == 0 && i%2 == 0) out << "_";
                else if (j%2 == 0 && i%2 == 1) out << " ";
                else if (j%2 == 1 && i%2 == 0) out << " ";
                else if (j%2 == 1 && i%2 == 1) out << "_";
            }
            else if (b.pieces[i][j]->getColour() == Colour::Black) {
                if (b.pieces[i][j]->getType() == PieceType::King) {
                    out << "k";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Queen) {
                    out << "q";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Rook) {
                    out << "r";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Bishop) {
                    out << "b";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Knight) {
                    out << "n";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Pawn) {
                    out << "p";
                }
            }
            else if (b.pieces[i][j]->getColour() == Colour::White) {
                if (b.pieces[i][j]->getType() == PieceType::King) {
                    out << "K";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Queen) {
                    out << "Q";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Rook) {
                    out << "R";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Knight) {
                    out << "N";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Bishop) {
                    out << "B";
                }
                else if (b.pieces[i][j]->getType() == PieceType::Pawn) {
                    out << "P";
                }
            }
        }
        out << std::endl;
    }
    out << std::endl;
    out << "  abcdefgh" << std::endl;
    return out;
}
