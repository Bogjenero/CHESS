#pragma once
#include <vector>



struct move
{
    int oX, oY, X, Y;
    move() {}
    move(int oldX, int oldY, int newX, int newY);
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
    /*int arr[8][8] = {{7, 6, -1, -1, -1, -1, 0, 1},
                     {8, 6, -1, -1, -1, -1, 0, 2},
                     {9, 6, -1, -1, -1, -1, 0, 3},
                     {11, 6, -1, -1, -1, -1, 0, 5},
                     {10, 6, -1, -1, -1, -1, 0, 4},
                     {9, 6, -1, -1, -1, -1, 0, 3},
                     {8, 6, -1, -1, -1, -1, 0, 2},
                     {7, 6, -1, -1, -1, -1, 0, 1} };*/
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

    const char* notation(int x, int y);
    std::vector<board> history;

    void Pawn(std::vector<move>& moves, int x, int y); // potezi za bijelog pijuna
    void King(std::vector<move>& moves, int x, int y); // potezi za kralja
    void Rook(std::vector<move>& moves, int x, int y); // potezi za topa
    void Queen(std::vector<move>& moves, int x, int y); // potezi za topa
    void Bishop(std::vector<move>& moves, int x, int y); // potezi za topa
    void Knight(std::vector<move>& moves, int x, int y); // potezi za topa
    std::vector<move> getLegalMoves(board b, Figure::Colors color); // dohvaća sve legalne poteze za određenu boju
    bool isKingInCheck(board b, Figure::Colors color); // provjerava je li kralj u šahu
    bool isSquareUnderAttack(int x, int y); // provjerava je li polje pod napadom
    bool isCheckmate(board b, Figure::Colors turn);

public:
    Figure::Colors turn = Figure::white;
    board mBoard;
    bool playMove(move req,int replace[],bool end[]); // izvršava potez
    void nextTurn(); // prebacuje na sljedeći potez
};    
