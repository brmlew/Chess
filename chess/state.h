#ifndef STATE_H
#define STATE_H

// StateType defines the current state of the piece:
// Move: I am a piece that just made a move. I need the board to
//       update to reflect my change in location
// Attack: I am a piece that is attacking another piece. I need 
//         the board to update to reflect my attack and my change
//         in location
// PawnPromotion: I am a PieceType::Pawn that made it to the other end
//                of the board and I need to board to update to reflect
//                my promotion

enum class StateType { Nothing, Move, Attack, PawnPromotion };
enum class Colour { White, Black, NoColour };
enum class PieceType { King, Queen, Rook, Knight, Bishop, Pawn, Empty };

struct Coordinate {
    int row;
    int col;
};

struct State {
    StateType state;
    PieceType type;
    Colour colour;
    Coordinate location;
};

#endif