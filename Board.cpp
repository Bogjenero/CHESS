
#include <vector>
#include "Board.h"
#include <iostream>


move::move(int oldX, int oldY, int newX, int newY)
{
    oX = oldX;
    oY = oldY;
    X = newX;
    Y = newY;
}

void chessBoard::wPawn(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Pawn && mBoard.arr[x][y].color == Figure::white)
    {
        if (y > 0)
        {
            if (mBoard.arr[x][y - 1].figure == Figure::Empty)
            {
                moves.push_back(move(x, y, x, y - 1));
                if (mBoard.arr[x][y - 2].figure == Figure::Empty && y == 6)
                {
                    moves.push_back(move(x, y, x, y - 2));
                }
            }
            if (x > 0)
            {
                if (mBoard.arr[x - 1][y - 1].figure >= Figure::Pawn && mBoard.arr[x - 1][y - 1].figure <= Figure::Queen && mBoard.arr[x - 1][y - 1].color >= Figure::black)
                {
                    moves.push_back(move(x, y, x - 1, y - 1));
                }
            }
            if (x < 7)
            {
                if (mBoard.arr[x - 1][y - 1].figure >= Figure::Pawn  && mBoard.arr[x - 1][y - 1].figure <= Figure::Queen && mBoard.arr[x - 1][y - 1].color == Figure::black )
                {
                    moves.push_back(move(x, y, x + 1, y - 1));
                }
            }
        }
    }
}

void chessBoard::bPawn(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Pawn && mBoard.arr[x][y].color == Figure::black)
    {
        if (y < 7)
        {
            if (mBoard.arr[x][y + 1].figure == Figure::Empty)
            {
                moves.push_back(move(x, y, x, y + 1));
                if (mBoard.arr[x][y + 2].figure == Figure::Empty && y == 1)
                {
                    moves.push_back(move(x, y, x, y + 2));
                }
            }
            if (x > 0)
            {
                if ((mBoard.arr[x - 1][y + 1].figure <= Figure::Queen && mBoard.arr[x - 1][y + 1].figure >= Figure::Pawn && mBoard.arr[x - 1][y + 1].color == Figure::white) && mBoard.arr[x - 1][y + 1].figure != Figure::Empty)
                {
                    moves.push_back(move(x, y, x - 1, y + 1));
                }
            }
            if (x < 7)
            {
                if ((mBoard.arr[x + 1][y + 1].figure <= Figure::Queen && mBoard.arr[x + 1][y + 1].figure >= Figure::Pawn) && mBoard.arr[x + 1][y + 1].figure != Figure::Empty)
                {
                    moves.push_back(move(x, y, x + 1, y + 1));
                }
            }
        }
    }
}
void chessBoard::King(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::King)
    {
      
        if (x > 0)
        {
            if ((mBoard.arr[x - 1][y].color == Figure::white && ((mBoard.arr[x - 1][y].figure >= Figure::Pawn && mBoard.arr[x - 1][y].figure <= Figure::Queen) || mBoard.arr[x - 1][y].figure == Figure::Empty)) || (mBoard.arr[x - 1][y].color == Figure::black && ((mBoard.arr[x - 1][y].figure <= Figure::Queen && mBoard.arr[x - 1][y].figure >= Figure::Pawn) || mBoard.arr[x - 1][y].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x - 1, y));
            }
        }
        if (x > 0 && y > 0)
        {
            if ((mBoard.arr[x - 1][y - 1].color == Figure::white && ((mBoard.arr[x - 1][y - 1].figure >= Figure::Pawn && mBoard.arr[x - 1][y - 1].figure <= Figure::Queen) || mBoard.arr[x - 1][y - 1].figure == Figure::Empty)) || (mBoard.arr[x - 1][y - 1].color == Figure::black && (mBoard.arr[x - 1][y - 1].figure <= Figure::Queen && mBoard.arr[x - 1][y - 1].figure >= Figure::Pawn) || mBoard.arr[x - 1][y - 1].figure == Figure::Empty))
            {
                moves.push_back(move(x, y, x - 1, y - 1));
            }
        }
        if (x > 0 && y < 7)
        {
            if ((mBoard.arr[x - 1][y + 1].color == Figure::white && ((mBoard.arr[x - 1][y + 1].figure >= Figure::Pawn && mBoard.arr[x - 1][y + 1].figure <= Figure::Queen) || mBoard.arr[x - 1][y + 1].figure == Figure::Empty)) || (mBoard.arr[x - 1][y + 1].color == Figure::black && ((mBoard.arr[x - 1][y + 1].figure >= Figure::Pawn && mBoard.arr[x - 1][y + 1].figure <= Figure::Queen) || mBoard.arr[x - 1][y + 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x - 1, y + 1));
            }
        }
        if (y > 0)
        {
            if ((mBoard.arr[x][y - 1].color == Figure::white && ((mBoard.arr[x][y - 1].figure >=  Figure::Pawn && mBoard.arr[x][y - 1].figure <= Figure::Queen) || mBoard.arr[x][y - 1].figure == Figure::Empty)) || (mBoard.arr[x][y - 1].color == Figure::black && ((mBoard.arr[x][y - 1].figure <=  Figure::Queen && mBoard.arr[x][y - 1].figure >= Figure::Pawn)|| mBoard.arr[x][y - 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x, y - 1));
            }
        }
        if (y < 7)
        {
            if ((mBoard.arr[x][y + 1].color == Figure::white && ((mBoard.arr[x][y + 1].figure >= Figure::Pawn && mBoard.arr[x][y + 1].figure <= Figure::Queen) || mBoard.arr[x][y + 1].figure == Figure::Empty)) || (mBoard.arr[x][y + 1].color == Figure::black && ((mBoard.arr[x][y + 1].figure <= Figure::Queen && mBoard.arr[x][y + 1].figure >= Figure::Pawn) || mBoard.arr[x][y + 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x, y + 1));
            }
        }
        if (x < 7)
        {

            if ((mBoard.arr[x + 1][y].color == Figure::white && ((mBoard.arr[x + 1][y].figure >= Figure::Pawn && mBoard.arr[x + 1][y].figure <= Figure::Queen) || mBoard.arr[x + 1][y].figure == Figure::Empty)) || (mBoard.arr[x + 1][y].color == Figure::black && ((mBoard.arr[x + 1][y].figure <= Figure::Queen && mBoard.arr[x + 1][y].figure >= Figure::Pawn) || mBoard.arr[x + 1][y].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x + 1, y));
            }
        }
        if (x < 7 && y < 7)
        {

            if ((mBoard.arr[x + 1][y + 1].color == Figure::white && ((mBoard.arr[x + 1][y + 1].figure >= Figure::Pawn && mBoard.arr[x + 1][y + 1].figure <= Figure::Queen) || mBoard.arr[x + 1][y + 1].figure == Figure::Empty)) || (mBoard.arr[x + 1][y + 1].figure==Figure::black && ((mBoard.arr[x + 1][y + 1].figure <= Figure::Queen && mBoard.arr[x + 1][y + 1].figure >= Figure::Pawn) || mBoard.arr[x + 1][y + 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x + 1, y + 1));
            }
        }
        if (x < 7 && y > 0)
        {

            if ((mBoard.arr[x + 1][y - 1].color == Figure::white && ((mBoard.arr[x + 1][y - 1].figure <= Figure::Queen && mBoard.arr[x + 1][y - 1].figure >= Figure::Pawn) || mBoard.arr[x + 1][y - 1].figure == Figure::Empty)) || (mBoard.arr[x + 1][y - 1].color==Figure::black && ((mBoard.arr[x + 1][y - 1].figure <=  Figure::Queen && mBoard.arr[x + 1][y - 1].figure >= Figure::Pawn)|| mBoard.arr[x + 1][y - 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x + 1, y - 1));
            }
        }
    }
}

void chessBoard::Knight(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Knight)
    {
       
        if (x > 0 && y < 6)
        {
            if ((mBoard.arr[x - 1][y + 2].color == Figure::white && ((mBoard.arr[x - 1][y + 2].figure >= Figure::Pawn && mBoard.arr[x - 1][y + 2].figure <= Figure::Queen)|| mBoard.arr[x - 1][y + 2].figure == Figure::Empty)) || (mBoard.arr[x - 1][y + 2].color==Figure::black && ((mBoard.arr[x - 1][y + 2].figure <= Figure::Queen && mBoard.arr[x - 1][y + 2].figure >= Figure::Pawn) || mBoard.arr[x - 1][y + 2].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x - 1, y + 2));
            }
        }
        if (x > 0 && y > 1)
        {
            if ((mBoard.arr[x - 1][y - 2].color == Figure::white && ((mBoard.arr[x - 1][y - 2].figure <= Figure::Queen && mBoard.arr[x - 1][y - 2].figure >= Figure::Pawn) || mBoard.arr[x - 1][y - 2].figure == Figure::Empty)) || (mBoard.arr[x - 1][y - 2].color == Figure::black && ((mBoard.arr[x - 1][y - 2].figure <= Figure::Queen && mBoard.arr[x - 1][y - 2].figure >= Figure::Pawn)|| mBoard.arr[x - 1][y - 2].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x - 1, y - 2));
            }
        }
        if (x > 1 && y < 7)
        {
            if ((mBoard.arr[x - 2][y + 1].color == Figure::white && ((mBoard.arr[x - 2][y + 1].figure <= Figure::Queen && mBoard.arr[x - 2][y + 1].figure >= Figure::Pawn)|| mBoard.arr[x - 2][y + 1].figure == Figure::Empty)) || (mBoard.arr[x - 2][y + 1].color == Figure::black && ((mBoard.arr[x - 2][y + 1].figure >= Figure::Pawn && mBoard.arr[x - 2][y + 1].figure <= Figure::Queen)|| mBoard.arr[x - 2][y + 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x - 2, y + 1));
            }
        }
        if (y > 0 && x > 1)
        {
            if ((mBoard.arr[x - 2][y - 1].color == Figure::white && ((mBoard.arr[x - 2][y - 1].figure <= Figure::Queen && mBoard.arr[x - 2][y - 1].figure >= Figure::Pawn) || mBoard.arr[x - 2][y - 1].figure == Figure::Empty)) || (mBoard.arr[x - 2][y - 1].color == Figure::black && ((mBoard.arr[x - 2][y - 1].figure >= Figure::Pawn && mBoard.arr[x - 2][y - 1].figure <= Figure::Queen) || mBoard.arr[x - 2][y - 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x - 2, y - 1));
            }
        }
        if (y < 6 && x < 7)
        {
            if ((mBoard.arr[x +1][y + 2].color == Figure::white && ((mBoard.arr[x + 1][y + 2].figure <= Figure::Queen && mBoard.arr[x + 1][y + 2].figure >= Figure::Pawn) || mBoard.arr[x + 1][y + 2].figure == Figure::Empty)) || (mBoard.arr[x + 1][y + 2].color == Figure::black && ((mBoard.arr[x + 1][y + 2].figure >= Figure::Pawn && mBoard.arr[x + 1][y + 2].figure <= Figure::Queen) || mBoard.arr[x + 1][y + 2].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x + 1, y + 2));
            }
        }
        if (x < 7 && y > 1)
        {

            if ((mBoard.arr[x + 1][y - 2].color == Figure::white && ((mBoard.arr[x + 1][y - 2].figure <= Figure::Queen && mBoard.arr[x + 1][y - 2].figure >= Figure::Pawn) || mBoard.arr[x + 1][y - 2].figure == Figure::Empty)) || (mBoard.arr[x + 1][y - 2].color == Figure::black && ((mBoard.arr[x + 1][y - 2].figure >= Figure::Pawn && mBoard.arr[x + 1][y - 2].figure <= Figure::Queen) || mBoard.arr[x + 1][y - 2].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x + 1, y - 2));
            }
        }
        if (x < 6 && y < 7)
        {

            if ((mBoard.arr[x + 2][y + 1].color == Figure::white && ((mBoard.arr[x + 2][y + 1].figure <= Figure::Queen && mBoard.arr[x + 2][y + 1].figure >= Figure::Pawn) || mBoard.arr[x + 2][y + 1].figure == Figure::Empty)) || (mBoard.arr[x + 2][y + 1].color == Figure::black && ((mBoard.arr[x + 2][y + 1].figure >= Figure::Pawn && mBoard.arr[x + 2][y + 1].figure <= Figure::Queen) || mBoard.arr[x + 2][y + 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x + 2, y + 1));
            }
        }
        if (x < 6 && y > 0)
        {

            if ((mBoard.arr[x + 2][y - 1].color == Figure::white && ((mBoard.arr[x + 2][y - 1].figure <= Figure::Queen && mBoard.arr[x + 2][y - 1].figure >= Figure::Pawn) || mBoard.arr[x + 2][y - 1].figure == Figure::Empty)) || (mBoard.arr[x + 2][y - 1].color == Figure::black && ((mBoard.arr[x + 2][y - 1].figure >= Figure::Pawn && mBoard.arr[x + 2][y - 1].figure <= Figure::Queen) || mBoard.arr[x + 2][y - 1].figure == Figure::Empty)))
            {
                moves.push_back(move(x, y, x + 2, y - 1));
            }
        }
    }
}




void chessBoard::Rook(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Rook)
    {
        
        int offX = 0;
        int offY = 0;
        bool stop = false;
        while (!stop)
        {
            ++offX;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
    }
}

void chessBoard::Bishop(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Bishop)
    {
        
        int offX = 0;
        int offY = 0;
        bool stop = false;
        while (!stop)
        {
            ++offX;
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offX;
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
    }
}

/*void chessBoard::Queen(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Queen)
    {
       
        int offX = 0;
        int offY = 0;
        bool stop = false;
        while (!stop)
        {
            ++offX;
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offX;
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offX;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (mBoard.arr[x + offX][y + offY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((mBoard.arr[x + offX][y + offY].color == Figure::white && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen) || (mBoard.arr[x + offX][y + offY].color == Figure::black && mBoard.arr[x + offX][y + offY].figure <= Figure::Queen && mBoard.arr[x + offX][y + offY].figure >= Figure::Pawn))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
    }
}*/
void chessBoard::Queen(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Queen)
    {
        // Dijagonalno pomicanje (sve četiri dijagonale)
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 && dy == 0) continue; // Preskoči ako nema pomaka

                int nx = x, ny = y;
                while (true)
                {
                    nx += dx;
                    ny += dy;

                    if (nx < 0 || nx > 7 || ny < 0 || ny > 7)
                    {
                        break;
                    }

                    auto& targetSquare = mBoard.arr[nx][ny];
                    if (targetSquare.figure == Figure::Empty)
                    {
                        moves.push_back(move(x, y, nx, ny));
                    }
                    else
                    {
                        // Ako je protivnikova figura
                        if ((targetSquare.color != mBoard.arr[x][y].color) &&
                            (targetSquare.figure >= Figure::Pawn && targetSquare.figure <= Figure::Queen))
                        {
                            moves.push_back(move(x, y, nx, ny));
                        }
                        break;
                    }
                }
            }
        }

        // Horizontalno i vertikalno pomicanje (4 pravca)
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 || dy == 0) // Samo horizontalno ili vertikalno
                {
                    int nx = x, ny = y;
                    while (true)
                    {
                        nx += dx;
                        ny += dy;

                        if (nx < 0 || nx > 7 || ny < 0 || ny > 7)
                        {
                            break;
                        }

                        auto& targetSquare = mBoard.arr[nx][ny];
                        if (targetSquare.figure == Figure::Empty)
                        {
                            moves.push_back(move(x, y, nx, ny));
                        }
                        else
                        {
                            // Ako je protivnikova figura
                            if ((targetSquare.color != mBoard.arr[x][y].color) &&
                                (targetSquare.figure >= Figure::Pawn && targetSquare.figure <= Figure::Queen))
                            {
                                moves.push_back(move(x, y, nx, ny));
                            }
                            break;
                        }
                    }
                }
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
                if (b.arr[i][j].figure == Figure::Pawn && b.arr[i][j].color == Figure::white)
                {
                    wPawn(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::King && b.arr[i][j].color == Figure::white)
                {
                    King(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Knight && b.arr[i][j].color == Figure::white)
                {
                    Knight(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Rook && b.arr[i][j].color == Figure::white)
                {
                    Rook(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Bishop && b.arr[i][j].color == Figure::white)
                {
                    Bishop(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Queen && b.arr[i][j].color == Figure::white)
                {
                    Queen(moves, i, j);
                }
            }
            else
            {
                if (b.arr[i][j].figure == Figure::Pawn && b.arr[i][j].color == Figure::black)
                {
                    bPawn(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::King && b.arr[i][j].color == Figure::black)
                {
                    King(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Knight && b.arr[i][j].color == Figure::black)
                {
                    Knight(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Rook && b.arr[i][j].color == Figure::black)
                {
                    Rook(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Bishop && b.arr[i][j].color == Figure::black)
                {
                    Bishop(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Queen && b.arr[i][j].color == Figure::black)
                {
                    Queen(moves, i, j);
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
            mBoard.arr[req.oX][req.oY] = { Figure::Empty, Figure::none };
            std::vector<move> tempMoves = getLegalMoves(mBoard, !turn);
            bool check = false;
                for (int j = 0; j < tempMoves.size(); ++j)
                {
                    if ((mBoard.arr[tempMoves[j].X][tempMoves[j].Y].figure == Figure::King && mBoard.arr[tempMoves[j].X][tempMoves[j].Y].color == Figure::black) || (mBoard.arr[tempMoves[j].X][tempMoves[j].Y].figure == Figure::King && mBoard.arr[tempMoves[j].X][tempMoves[j].Y].color == Figure::white))
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