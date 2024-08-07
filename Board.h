#pragma once
#include <vector>


struct move
{
    int oX, oY, X, Y;
    move() {}
    move(int oldX, int oldY, int newX, int newY);
};

struct board
{
    int arr[8][8] = { {7, 6, -1, -1, -1, -1, 0, 1},
                     {8, 6, -1, -1, -1, -1, 0, 2},
                     {9, 6, -1, -1, -1, -1, 0, 3},
                     {11, 6, -1, -1, -1, -1, 0, 5},
                     {10, 6, -1, -1, -1, -1, 0, 4},
                     {9, 6, -1, -1, -1, -1, 0, 3},
                     {8, 6, -1, -1, -1, -1, 0, 2},
                     {7, 6, -1, -1, -1, -1, 0, 1} };
};

class chessBoard {
private: 
    bool turn = 1;
    const char* notation(int x, int y);
    std::vector<board> history;

    void wPawn(std::vector<move>& moves, int x, int y); // potezi za bijelog pijuna
    void bPawn(std::vector<move>& moves, int x, int y); // potezi za crnog pijuna
    void King(std::vector<move>& moves, int x, int y); // potezi za kralja
    std::vector<move> getLegalMoves(board b, bool color); // dohvaća sve legalne poteze za određenu boju


public:
    board mBoard;
    bool playMove(move req); // izvršava potez
    void nextTurn(); // prebacuje na sljedeći potez
};