#include <vector>
#include "Board.h"

move::move(int oldX, int oldY, int newX, int newY)
{
    oX = oldX;
    oY = oldY;
    X = newX;
    Y = newY;
}

void chessBoard::wPawn(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y] == 0)
    {
        if (y > 0)
        {
            if (mBoard.arr[x][y - 1] == -1)
            {
                moves.push_back(move(x, y, x, y - 1));
                if (mBoard.arr[x][y - 2] == -1 && y == 6)
                {
                    moves.push_back(move(x, y, x, y - 2));
                }
            }
            if (x > 0)
            {
                if (mBoard.arr[x - 1][y - 1] >= 6)
                {
                    moves.push_back(move(x, y, x - 1, y - 1));
                }
            }
            if (x < 7)
            {
                if (mBoard.arr[x + 1][y - 1] >= 6)
                {
                    moves.push_back(move(x, y, x + 1, y - 1));
                }
            }
        }
    }
}

void chessBoard::bPawn(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y] == 6)
    {
        if (y < 7)
        {
            if (mBoard.arr[x][y + 1] == -1)
            {
                moves.push_back(move(x, y, x, y + 1));
                if (mBoard.arr[x][y + 2] == -1 && y == 1)
                {
                    moves.push_back(move(x, y, x, y + 2));
                }
            }
            if (x > 0)
            {
                if (mBoard.arr[x - 1][y + 1] < 6 && mBoard.arr[x - 1][y + 1] != -1)
                {
                    moves.push_back(move(x, y, x - 1, y + 1));
                }
            }
            if (x < 7)
            {
                if (mBoard.arr[x + 1][y + 1] < 6 && mBoard.arr[x + 1][y + 1] != -1)
                {
                    moves.push_back(move(x, y, x + 1, y + 1));
                }
            }
        }
    }
}
void chessBoard::King(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y] == 4 || mBoard.arr[x][y] == 10)
    {
        bool pThreshold = mBoard.arr[x][y] < 6;
        if (x > 0)
        {
            if ((pThreshold && (mBoard.arr[x - 1][y] > 5 || mBoard.arr[x - 1][y] == -1)) || (!pThreshold && (mBoard.arr[x - 1][y] < 6 || mBoard.arr[x - 1][y] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y));
            }
        }
        if (x > 0 && y > 0)
        {
            if ((pThreshold && (mBoard.arr[x - 1][y - 1] > 5 || mBoard.arr[x - 1][y - 1] == -1)) || (!pThreshold && (mBoard.arr[x - 1][y - 1] < 6 || mBoard.arr[x - 1][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y - 1));
            }
        }
        if (x > 0 && y < 7)
        {
            if ((pThreshold && (mBoard.arr[x - 1][y + 1] > 5 || mBoard.arr[x - 1][y + 1] == -1)) || (!pThreshold && (mBoard.arr[x - 1][y + 1] < 6 || mBoard.arr[x - 1][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y + 1));
            }
        }
        if (y > 0)
        {
            if ((pThreshold && (mBoard.arr[x][y - 1] > 5 || mBoard.arr[x][y - 1] == -1)) || (!pThreshold && (mBoard.arr[x][y - 1] < 6 || mBoard.arr[x][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x, y - 1));
            }
        }
        if (y < 7)
        {
            if ((pThreshold && (mBoard.arr[x][y + 1] > 5 || mBoard.arr[x][y + 1] == -1)) || (!pThreshold && (mBoard.arr[x][y + 1] < 6 || mBoard.arr[x][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x, y + 1));
            }
        }
        if (x < 7)
        {

            if ((pThreshold && (mBoard.arr[x + 1][y] > 5 || mBoard.arr[x + 1][y] == -1)) || (!pThreshold && (mBoard.arr[x + 1][y] < 6 || mBoard.arr[x + 1][y] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y));
            }
        }
        if (x < 7 && y < 7)
        {

            if ((pThreshold && (mBoard.arr[x + 1][y + 1] > 5 || mBoard.arr[x + 1][y + 1] == -1)) || (!pThreshold && (mBoard.arr[x + 1][y + 1] < 6 || mBoard.arr[x + 1][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y + 1));
            }
        }
        if (x < 7 && y > 0)
        {

            if ((pThreshold && (mBoard.arr[x + 1][y - 1] > 5 || mBoard.arr[x + 1][y - 1] == -1)) || (!pThreshold && (mBoard.arr[x + 1][y - 1] < 6 || mBoard.arr[x + 1][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y - 1));
            }
        }
    }
}

std::vector<move> chessBoard::getLegalMoves(board b, bool color)
{
    std::vector<move> moves;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (color == 1)
            {
                if (b.arr[i][j] == 0)
                {
                    wPawn(moves, i, j);
                }
                if (b.arr[i][j] == 4)
                {
                    King(moves, i, j);
                }
            }
            else
            {
                if (b.arr[i][j] == 6)
                {
                    bPawn(moves, i, j);
                }
                else if (b.arr[i][j] == 10)
                {
                    King(moves, i, j);
                }
            }
        }
    }
    return moves;
}

bool chessBoard::playMove(move req)
{
    std::vector<move> moves = getLegalMoves(mBoard, turn);
    move temp;
    for (int i = 0; i < moves.size(); ++i)
    {
        temp = moves[i];
        if (temp.oX == req.oX && temp.oY == req.oY && temp.X == req.X && temp.Y == req.Y)
        {
            mBoard.arr[req.X][req.Y] = mBoard.arr[req.oX][req.oY];
            mBoard.arr[req.oX][req.oY] = -1;
            std::vector<move> tempMoves = getLegalMoves(mBoard, !turn);
            bool check = false;
            for (int j = 0; j < tempMoves.size(); ++j)
            {
                if (mBoard.arr[tempMoves[j].X][tempMoves[j].Y] == 4 || mBoard.arr[tempMoves[j].X][tempMoves[j].Y] == 10)
                {
                    mBoard = history[history.size() - 1];
                    check = true;
                    break;
                }
            }
            if (!check)
            {
                history.push_back(mBoard);
                return true;
            }
        }
    }
    return false;
}
void chessBoard::nextTurn()
{
    turn = !turn;

}