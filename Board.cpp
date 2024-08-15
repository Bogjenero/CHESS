#include <vector>
#include "Board.h"
#include <iostream>
#include <algorithm>
#include <array>

move::move(int oldX, int oldY, int newX, int newY)
{
    oX = oldX;
    oY = oldY;
    X = newX;
    Y = newY;
}

void chessBoard::Pawn(board& Board,std::vector<move>& moves, int x, int y)
{
    if (Board.arr[x][y].figure == Figure::Pawn && Board.arr[x][y].color == turn)
    {
        int direction = (turn == Figure::white) ? -1 : 1; 
        int startRow = (turn == Figure::white) ? 6 : 1;   
        int opponentColor = (turn == Figure::white) ? Figure::black : Figure::white;


        if (y + direction >= 0 && y + direction < 8 && Board.arr[x][y + direction].figure == Figure::Empty)
        {
            moves.push_back(move(x, y, x, y + direction));

            if (y == startRow && Board.arr[x][y + 2 * direction].figure == Figure::Empty)
            {
                moves.push_back(move(x, y, x, y + 2 * direction));
            }
        }
        if (x > 0 && y + direction >= 0 && y + direction < 8)
        {
            if (Board.arr[x - 1][y + direction].color == opponentColor && Board.arr[x - 1][y + direction].figure != Figure::Empty)
            {
                moves.push_back(move(x, y, x - 1, y + direction));
            }
        }
        if (x < 7 && y + direction >= 0 && y + direction < 8)
        {
            if (Board.arr[x + 1][y + direction].color == opponentColor && Board.arr[x + 1][y + direction].figure != Figure::Empty)
            {
                moves.push_back(move(x, y, x + 1, y + direction));
            }
        }
    }
}

void chessBoard::King(board& Board, std::vector<move>& moves, int x, int y)
{

    if (Board.arr[x][y].figure != Figure::King)
        return;
   
        std::array<int, 8> dx = { -1, -1, -1, 0, 0, 1, 1, 1, };
        std::array<int, 8> dy = { -1, 0, 1, -1, 1, -1,0 , 1,};


        for (int i = 0; i < 8; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];


            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8)
            {
                
                if (Board.arr[newX][newY].color != Board.arr[x][y].color || Board.arr[newX][newY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, newX, newY));
                }
            }
        }
        if(Board.arr[x][y].color == Figure::white && !wKing_moved)
		{
            if (Board.arr[x + 2][y].figure == Figure::Empty && Board.arr[x + 1][y].figure == Figure::Empty)
            {
                moves.push_back(move(x, y, x + 2, y));
            }
            if(Board.arr[x - 3][y].figure == Figure::Empty && Board.arr[x - 1][y].figure == Figure::Empty && Board.arr[x - 2][y].figure == Figure::Empty)
            {
                moves.push_back(move(x, y, x - 3, y));
            }
		}
        else if(Board.arr[x][y].color == Figure::black && !bKing_moved)
		{
            if (Board.arr[x + 2][y].figure == Figure::Empty && Board.arr[x + 1][y].figure == Figure::Empty)
            {
                moves.push_back(move(x, y, x + 2, y));
            }
            if (Board.arr[x - 3][y].figure == Figure::Empty && Board.arr[x - 1][y].figure == Figure::Empty && Board.arr[x - 2][y].figure == Figure::Empty)
            {
                moves.push_back(move(x, y, x - 3, y));
            }
		}
}


void chessBoard::Knight(board& Board, std::vector<move>& moves, int x, int y)
{

    if (Board.arr[x][y].figure != Figure::Knight)
        return;


        std::array<int, 8> dx = { -2, -1, 1, 2, 2, 1, -1, -2 };
        std::array<int, 8> dy = { 1, 2, 2, 1, -1, -2, -2, -1 };

        for (int i = 0; i < 8; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

           
            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8)
            {
               
                if (Board.arr[newX][newY].color != Board.arr[x][y].color || Board.arr[newX][newY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, newX, newY));
                }
            }
        }
}

void chessBoard::Rook(board& Board, std::vector<move>& moves, int x, int y)
{

    if (Board.arr[x][y].figure != Figure::Rook)
        return;

        std::array<int, 4> dx = { 1, -1, 0, 0 };
        std::array<int, 4> dy = { 0, 0, 1, -1 };

        for (int i = 0; i < 4; ++i)
        {
            int newX = x;
            int newY = y;

            while (true)
            {
                newX += dx[i];
                newY += dy[i];
                if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8)
                {
                    break;
                }
                if (Board.arr[newX][newY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, newX, newY));
                }
                else if (Board.arr[newX][newY].color != Board.arr[x][y].color)
                {
                    moves.push_back(move(x, y, newX, newY));
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }






void chessBoard::Bishop(board& Board, std::vector<move>& moves, int x, int y)
{

    if (Board.arr[x][y].figure != Figure::Bishop)
        return;

        std::array<int, 4> dx = { 1, 1, -1, -1 };
        std::array<int, 4> dy = { 1, -1, 1, -1 };


        for (int i = 0; i < 4; ++i)
        {
            int newX = x;
            int newY = y;

            while (true)
            {
                newX += dx[i];
                newY += dy[i];

                
                if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8)
                {
                    break;
                }
                if (Board.arr[newX][newY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, newX, newY));
                }
                else if (Board.arr[newX][newY].color != Board.arr[x][y].color)
                {
                    moves.push_back(move(x, y, newX, newY));
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }

void chessBoard::Queen(board& Board, std::vector<move>& moves, int x, int y)
{

    if (Board.arr[x][y].figure != Figure::Queen)
        return;
        
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 && dy == 0) continue;

                int nx = x, ny = y;
                while (true)
                {
                    nx += dx;
                    ny += dy;

                    if (nx < 0 || nx > 7 || ny < 0 || ny > 7)
                    {
                        break;
                    }

                    auto& targetSquare = Board.arr[nx][ny];
                    if (targetSquare.figure == Figure::Empty)
                    {
                        moves.push_back(move(x, y, nx, ny));
                    }
                    else
                    {
                       
                        if ((targetSquare.color != Board.arr[x][y].color) &&
                            (targetSquare.figure >= Figure::Pawn && targetSquare.figure <= Figure::Queen))
                        {
                            moves.push_back(move(x, y, nx, ny));
                        }
                        break;
                    }
                }
            }
        }

      
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 || dy == 0) 
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

                        auto& targetSquare = Board.arr[nx][ny];
                        if (targetSquare.figure == Figure::Empty)
                        {
                            moves.push_back(move(x, y, nx, ny));
                        }
                        else
                        {
                            
                            if ((targetSquare.color != Board.arr[x][y].color) &&
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




std::vector<move> chessBoard::getLegalMoves(board b, Figure::Colors color)
{
    std::vector<move> moves;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
                if (b.arr[i][j].figure == Figure::Pawn && b.arr[i][j].color == color)
                {
                    Pawn(b,moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::King && b.arr[i][j].color == color)
                {
                    King(b,moves, i, j);
                }
                if (b.arr[i][j].figure == Figure::Knight && b.arr[i][j].color == color)
                {
                    Knight(b,moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Rook && b.arr[i][j].color == color)
                {
                    Rook(b,moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Bishop && b.arr[i][j].color == color)
                {
                    Bishop(b,moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Queen && b.arr[i][j].color == color)
                {
                    Queen(b,moves, i, j);
                }
        }
    }
    return moves;
}


bool chessBoard::isKingInCheck(board b,Figure::Colors color)
{
    int kingX, kingY;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (b.arr[i][j].figure == Figure::King && b.arr[i][j].color == color)
            {
                kingX = i;
                kingY = j;
                break;
            }
        }
    }
    std::vector<move> opponentMoves;
    if (color == Figure::white) 
    {
         opponentMoves = getLegalMoves(b, Figure::black);
    }
    else 
    {
		 opponentMoves = getLegalMoves(b, Figure::white);
	}
    return !std::all_of(opponentMoves.begin(), opponentMoves.end(), [&](const move& m) {
        return m.X != kingX || m.Y != kingY;
        });
}

bool chessBoard::isCheckmate(board b, Figure::Colors color) {
    
    if (!isKingInCheck(b, color)) {
        return false; 
    }

    std::vector<move> allPossibleMoves = getLegalMoves(b, color);

    return std::none_of(allPossibleMoves.begin(), allPossibleMoves.end(), [&](const move& m) {
        board tempBoard = b;
        tempBoard.arr[m.X][m.Y] = tempBoard.arr[m.oX][m.oY];
        tempBoard.arr[m.oX][m.oY] = { Figure::Empty, Figure::none };       
        return !isKingInCheck(tempBoard, color);
        });

 
}




bool chessBoard::isSquareUnderAttack(int x, int y)
{
    std::vector<move> moves;
    if (isKingInCheck(chessBoard,turn))
    {
        return false;
    }
    if (turn == Figure::white) {
        std::vector<move> moves = getLegalMoves(chessBoard, Figure::black);
        return std::all_of(moves.begin(), moves.end(), [x, y](const move& m) {
            return !(m.X == x && m.Y == y);
            });
    }
    else {
        std::vector<move> moves = getLegalMoves(chessBoard, Figure::white);
        return std::all_of(moves.begin(), moves.end(), [x, y](const move& m) {
            return !(m.X == x && m.Y == y);
            });
    }
    return true;
}










bool chessBoard::playMove(move req, std::array<int,4>& replace,bool& end,bool& rotation)
{

 
    std::vector<move> moves = getLegalMoves(chessBoard, turn);
    move temp;
    for (int i = 0; i < moves.size(); ++i)
    {
        temp = moves[i];
        
        if (req==moves[i])
        {
            if (chessBoard.arr[req.oX][req.oY].figure == Figure::King && chessBoard.arr[req.oX][req.oY].color == Figure::white && req.oX + 2 == temp.X && !wKing_moved && !wRook2_moved)
            {
                if (isSquareUnderAttack(req.oX + 2, req.oY) && isSquareUnderAttack(req.oX + 1, req.Y))
                {
                    chessBoard.arr[req.X][req.Y] = chessBoard.arr[req.oX][req.oY];
                    chessBoard.arr[req.oX][req.oY].figure = Figure::Empty;
                    chessBoard.arr[5][7] = chessBoard.arr[7][7];
                    chessBoard.arr[7][7].figure = Figure::Empty;
                    wKing_moved = true;
                    wRook2_moved = true;
                    replace[0] = 7, replace[1] = 7, replace[2] = 5, replace[3] = 7;               
                    rotation = true;
                }
                else {
                    return false;

                }
            }

            else if (chessBoard.arr[req.oX][req.oY].figure == Figure::King && chessBoard.arr[req.oX][req.oY].color == Figure::white && req.oX - 3 == temp.X && !wKing_moved && !wRook1_moved)
            {
                if(isSquareUnderAttack(req.oX-3, req.oY) && isSquareUnderAttack(req.oX-2, req.oY) && isSquareUnderAttack(req.oX-1, req.oY))
                {
                    chessBoard.arr[req.X][req.Y] = chessBoard.arr[req.oX][req.oY];
                    chessBoard.arr[2][7] = chessBoard.arr[0][7];
                    chessBoard.arr[req.oX][req.oY].figure = Figure::Empty;
                    chessBoard.arr[0][7].figure = Figure::Empty;
                    wKing_moved = true;
                    wRook1_moved = true;
                    replace[0] = 0, replace[1] = 7, replace[2] = 2, replace[3] = 7;
                    rotation = true;
                }
                else {
                    return false;   
                }
            }
            else if (chessBoard.arr[req.oX][req.oY].figure == Figure::King && chessBoard.arr[req.oX][req.oY].color == Figure::black && req.oX + 2 == temp.X && !bKing_moved && !bRook1_moved)
            {
                if (isSquareUnderAttack(req.oX+1, req.oY) && isSquareUnderAttack(req.oX + 2, req.oY))
                {
                    chessBoard.arr[req.X][req.Y] = chessBoard.arr[req.oX][req.oY];
                    chessBoard.arr[5][0] = chessBoard.arr[7][0];
                    chessBoard.arr[req.oX][req.oY].figure = Figure::Empty;
                    chessBoard.arr[7][0].figure = Figure::Empty;
                    bKing_moved = true;
                    bRook1_moved = true;
                    replace[0] = 7, replace[1] = 0, replace[2] = 5, replace[3] = 0;
                    rotation = true;
                }
                else {
                    return false;
                }
            }
            else if (chessBoard.arr[req.oX][req.oY].figure == Figure::King && chessBoard.arr[req.oX][req.oY].color == Figure::black && req.oX - 3 == temp.X && !bKing_moved && !wRook2_moved)
            {
                if (isSquareUnderAttack(req.oX - 3, req.oY) && isSquareUnderAttack(req.oX - 2, req.oY) && isSquareUnderAttack(req.oX-3, req.oY))
                {
                    chessBoard.arr[req.X][req.Y] = chessBoard.arr[req.oX][req.oY];
                    chessBoard.arr[2][0] = chessBoard.arr[0][0];
                    chessBoard.arr[req.oX][req.oY].figure = Figure::Empty;
                    chessBoard.arr[0][0].figure = Figure::Empty;
                    bKing_moved = true;
                    bRook2_moved = true;
                    replace[0] = 0, replace[1] = 0, replace[2] = 2, replace[3] = 0;
                    rotation = true;
                }
                else {
                    return false;
                }
            }
            else {
                chessBoard.arr[req.X][req.Y] = chessBoard.arr[req.oX][req.oY];
                chessBoard.arr[req.oX][req.oY] = { Figure::Empty, Figure::none };

            }
            bool check = false;
            Figure::Colors opponentColor = (turn == Figure::white) ? Figure::black : Figure::white;
            if (isCheckmate(chessBoard, opponentColor))
            {
                end = true;
                return true;
            }
           if(isKingInCheck(chessBoard,turn))
           {
               chessBoard = history[history.size() - 1];
               check = true;
               break;             
            }

            if (!check)
            {
                if (chessBoard.arr[req.X][req.Y].figure == Figure::King)
                {
                    if (turn == Figure::white)
                    {
                        wKing_moved = true;
                    }
                    else if(turn == Figure::black)
                    {
                        bKing_moved = true;
                    }
                }
                if (chessBoard.arr[req.X][req.Y].figure == Figure::Rook)
				{
					if (turn == Figure::white)
					{
						if (req.oX == 0 && req.oY == 7)
						{
							wRook1_moved = true;
						}
						else if (req.oX == 7 && req.oY == 7)
						{
							wRook2_moved = true;
						}
					}
					else
					{
						if (req.oX == 0 && req.oY == 0)
						{
							bRook1_moved = true;
						}
						else if (req.oX == 7 && req.oY == 7)
						{
							bRook2_moved = true;
						}
					}
				}
                history.push_back(chessBoard);
                return true;
            }
        }
    }
    return false;
}
void chessBoard::nextTurn()
{
    if(turn == Figure::white)
	{
		turn = Figure::black;
	}
	else
	{
		turn = Figure::white;
	}
}