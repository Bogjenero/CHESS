#pragma once
#include <vector>



struct move
{
    int oX, oY, X, Y;
    move() {}
    move(int oldX, int oldY, int newX, int newY);
    bool operator==(const move& other) const {
        return (X == other.X) && (Y == other.Y) && (oX==other.oX) == (oY==other.oY);
    }
};

struct Figure {
    enum Figures {
        Empty ,Pawn, Rook, Knight, Bishop, King, Queen
    };
    enum Colors {
        none = -1,white, black
    };
    Figures figure;
    Colors color;
    bool hasMoved = false;
   
};

struct board
{

        Figure arr[8][8] = {
            {{Figure::Rook, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Rook, Figure::white}},
            {{Figure::Knight, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Knight, Figure::white}},
            {{Figure::Bishop, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Bishop, Figure::white}},
            {{Figure::Queen, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Queen, Figure::white}},
            {{Figure::King, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::King, Figure::white}},
            {{Figure::Bishop, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Bishop, Figure::white}},
            {{Figure::Knight, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Knight, Figure::white}},
            {{Figure::Rook, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Rook, Figure::white}}
        };        
        Figure start[8][8] = {
            {{Figure::Rook, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Rook, Figure::white}},
            {{Figure::Knight, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Knight, Figure::white}},
            {{Figure::Bishop, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Bishop, Figure::white}},
            {{Figure::Queen, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Queen, Figure::white}},
            {{Figure::King, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::King, Figure::white}},
            {{Figure::Bishop, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Bishop, Figure::white}},
            {{Figure::Knight, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Knight, Figure::white}},
            {{Figure::Rook, Figure::black}, {Figure::Pawn, Figure::black}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Empty, Figure::none}, {Figure::Pawn, Figure::white}, {Figure::Rook, Figure::white}}
        };
};

class chessBoard {
private: 

   
    std::vector<board> history;

    void Pawn(board Board, std::vector<move>& moves, int x, int y); // potezi za bijelog pijuna
    void King(board Board, std::vector<move>& moves, int x, int y); // potezi za kralja
    void Rook(board Board, std::vector<move>& moves, int x, int y); // potezi za topa
    void Queen(board Board, std::vector<move>& moves, int x, int y); // potezi za topa
    void Bishop(board Board, std::vector<move>& moves, int x, int y); // potezi za topa
    void Knight(board Board, std::vector<move>& moves, int x, int y); // potezi za topa
    std::vector<move> getLegalMoves(board b, Figure::Colors color); // dohvaća sve legalne poteze za određenu boju
    bool isKingInCheck(board b, Figure::Colors color); // provjerava je li kralj u šahu
    bool isSquareUnderAttack(int x, int y); // provjerava je li polje pod napadom
    bool isCheckmate(board b, Figure::Colors turn);
    bool wKing_moved, bKing_moved, wRook1_moved, wRook2_moved, bRook1_moved, bRook2_moved = false;
public:
    Figure::Colors turn = Figure::white;
    board chessBoard;
    bool playMove(move req,int replace[],bool& end,bool& rotation); // izvršava potez
    void nextTurn(); // prebacuje na sljedeći potez
};    
