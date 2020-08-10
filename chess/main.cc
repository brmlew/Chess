#include "board.h"
#include "piece.h"
#include "observer.h"
#include "state.h"
#include "display.h"

Coordinate charToInt(char c, int r) {
    if (c == 'a') {
        Coordinate coor{r, 1};
        return coor;
    }
    else if (c == 'b') {
        Coordinate coor{r, 2};
        return coor;
    }
    else if (c == 'c') {
        Coordinate coor{r, 3};
        return coor;
    }
    else if (c == 'd') {
        Coordinate coor{r, 4};
        return coor;
    }
    else if (c == 'e') {
        Coordinate coor{r, 5};
        return coor;
    }
    else if (c == 'f') {
        Coordinate coor{r, 6};
        return coor;
    }
    else if (c == 'g') {
        Coordinate coor{r, 7};
        return coor;
    }
    else {
        Coordinate coor{r, 8};
        return coor;
    }
}

int main() {
    int whiteScore = 0;
    int blackScore = 0;
    int turn = 0;

    std::string input;
    std::string command;
    char symbol;
    int num;

    // setup board
    Board board;

    // repeat game until CTRL+D
    while(true) {

        std::cin >> command;
        if (command == "setup") {
            board.setup(turn);
            std::cout << board;
        }
        else if (command == "game") {
            //game loop
            board.defaultSetup();
            std::cout << board;
            while(true) {
                if (turn == 0) {
                    std::cout << "White's turn" << std::endl;
                }
                else if (turn == 1) {
                    std::cout << "Black's turn" << std::endl;
                }

                //keyboard input
                if (std::cin.eof()) break;
                std::cin >> command;

                // if "move" check possible moves based off piece type and if legal then move piece
                if (command == "move") {
                    std::cin >> symbol;
                    std::cin >> num;
                    if (symbol != 'a' && symbol != 'b' && symbol != 'c' && symbol != 'd' && symbol != 'd' && 
                    symbol != 'e' && symbol != 'f' && symbol != 'g' && symbol != 'h') continue;
                    if (num < 1 || num > 8) continue;
                    Coordinate start = charToInt(symbol, num);
                    std::cin >> symbol;
                    std::cin >> num;
                    if (symbol != 'a' && symbol != 'b' && symbol != 'c' && symbol != 'd' && symbol != 'd' && 
                    symbol != 'e' && symbol != 'f' && symbol != 'g' && symbol != 'h') continue;
                    if (num < 1 || num > 8) continue;
                    Coordinate end = charToInt(symbol, num);
                    bool legalMove = board.movePiece(start, end, turn);
                    if (!legalMove) continue;
                }
                else if (command == "resign") {
                    if (turn == 1) {
                        blackScore++;
                        std::cout << "Black wins!" << std::endl;
                        break;
                    }
                    whiteScore++;
                    std::cout << "White wins!" << std::endl;
                    break;
                }
                else {
                    continue;
                }
                // if "resign", exit loop

                // display board
                std::cout << board;
                
                // check for checkmate, stalemate
                // if white win, whiteScore++
                // "  black  "   blackScore++

                if (turn == 0) turn++;
                else turn = 0;
            }

        }

        
        // display final score
        if (std::cin.eof()) {
            std::cout << "Final Score:" << std::endl;
            std::cout << "White: " << whiteScore << std::endl;
            std::cout << "Black: " << blackScore << std::endl;
            break;
        }

        //reset game
        board.defaultSetup();
    }
}
