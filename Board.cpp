
#include <vector>
#include "Board.h"
#include <iostream>


bool wKing_moved, bKing_moved, wRook1_moved, wRook2_moved, bRook1_moved, bRook2_moved = false;

move::move(int oldX, int oldY, int newX, int newY)
{
    oX = oldX;
    oY = oldY;
    X = newX;
    Y = newY;
}

/*void chessBoard::Pawn(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Pawn && mBoard.arr[x][y].color == turn)
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
}*/
void chessBoard::Pawn(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Pawn && mBoard.arr[x][y].color == turn)
    {
        int direction = (turn == Figure::white) ? -1 : 1; 
        int startRow = (turn == Figure::white) ? 6 : 1;   
        int opponentColor = (turn == Figure::white) ? Figure::black : Figure::white;


        if (y + direction >= 0 && y + direction < 8 && mBoard.arr[x][y + direction].figure == Figure::Empty)
        {
            moves.push_back(move(x, y, x, y + direction));

            if (y == startRow && mBoard.arr[x][y + 2 * direction].figure == Figure::Empty)
            {
                moves.push_back(move(x, y, x, y + 2 * direction));
            }
        }
        if (x > 0 && y + direction >= 0 && y + direction < 8)
        {
            if (mBoard.arr[x - 1][y + direction].color == opponentColor && mBoard.arr[x - 1][y + direction].figure != Figure::Empty)
            {
                moves.push_back(move(x, y, x - 1, y + direction));
            }
        }
        if (x < 7 && y + direction >= 0 && y + direction < 8)
        {
            if (mBoard.arr[x + 1][y + direction].color == opponentColor && mBoard.arr[x + 1][y + direction].figure != Figure::Empty)
            {
                moves.push_back(move(x, y, x + 1, y + direction));
            }
        }
    }
}

void chessBoard::King(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::King)
    {

        int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1, -3,2 };
        int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1, 0,0};

        for (int i = 0; i < 8; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];


            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8)
            {
                
                if (mBoard.arr[newX][newY].color != mBoard.arr[x][y].color || mBoard.arr[newX][newY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, newX, newY));
                }
            }
        }
        if(mBoard.arr[x][y].color == Figure::white && !wKing_moved)
		{
                moves.push_back(move(x, y, x + 2, y));
                moves.push_back(move(x, y, x - 3, y));
		}
        else if(mBoard.arr[x][y].color == Figure::black && !bKing_moved)
		{
            moves.push_back(move(x, y, x + 2, y));
            moves.push_back(move(x, y, x - 3, y));
		}

    }
}


void chessBoard::Knight(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Knight)
    {
        
        int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
        int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

        for (int i = 0; i < 8; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

           
            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8)
            {
               
                if (mBoard.arr[newX][newY].color != mBoard.arr[x][y].color || mBoard.arr[newX][newY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, newX, newY));
                }
            }
        }
    }
}

void chessBoard::Rook(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Rook)
    {
        int dx[] = { 1, -1, 0, 0 };
        int dy[] = { 0, 0, 1, -1 };

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
                if (mBoard.arr[newX][newY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, newX, newY));
                }
                else if (mBoard.arr[newX][newY].color != mBoard.arr[x][y].color)
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
}





void chessBoard::Bishop(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Bishop)
    {
        int dx[] = { 1, 1, -1, -1 };
        int dy[] = { 1, -1, 1, -1 };

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
                if (mBoard.arr[newX][newY].figure == Figure::Empty)
                {
                    moves.push_back(move(x, y, newX, newY));
                }
                else if (mBoard.arr[newX][newY].color != mBoard.arr[x][y].color)
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
}
void chessBoard::Queen(std::vector<move>& moves, int x, int y)
{
    if (mBoard.arr[x][y].figure == Figure::Queen)
    {
        
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

                    auto& targetSquare = mBoard.arr[nx][ny];
                    if (targetSquare.figure == Figure::Empty)
                    {
                        moves.push_back(move(x, y, nx, ny));
                    }
                    else
                    {
                       
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

                        auto& targetSquare = mBoard.arr[nx][ny];
                        if (targetSquare.figure == Figure::Empty)
                        {
                            moves.push_back(move(x, y, nx, ny));
                        }
                        else
                        {
                            
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




std::vector<move> chessBoard::getLegalMoves(board b, Figure::Colors color)
{
    std::vector<move> moves;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
                if (b.arr[i][j].figure == Figure::Pawn && b.arr[i][j].color == color)
                {
                    Pawn(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::King && b.arr[i][j].color == color)
                {
                    King(moves, i, j);
                    b.arr[i][j].hasMoved = true;
                }
                if (b.arr[i][j].figure == Figure::Knight && b.arr[i][j].color == color)
                {
                    Knight(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Rook && b.arr[i][j].color == color)
                {
                    Rook(moves, i, j);
                    b.arr[i][j].hasMoved = true;
                }
                else if (b.arr[i][j].figure == Figure::Bishop && b.arr[i][j].color == color)
                {
                    Bishop(moves, i, j);
                }
                else if (b.arr[i][j].figure == Figure::Queen && b.arr[i][j].color == color)
                {
                    Queen(moves, i, j);
                }
        }
    }
    return moves;
}


bool chessBoard::isKingInCheck(board b,Figure::Colors turn)
{
        int kingX, kingY;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (mBoard.arr[i][j].figure == Figure::King && mBoard.arr[i][j].color == turn)
                {
                    kingX = i;
                    kingY = j;
                    break;
                }
            }
        }
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (mBoard.arr[i][j].color != turn && mBoard.arr[i][j].color != Figure::none)
                {
                    std::vector<move> opponentMoves;
                    switch (mBoard.arr[i][j].figure)
                    {
                    case Figure::Pawn:
                        Pawn(opponentMoves, i, j);
                        break;
                    case Figure::Knight:
                        Knight(opponentMoves, i, j);
                        break;
                    case Figure::Bishop:
                        Bishop(opponentMoves, i, j);
                        break;
                    case Figure::Rook:
                        Rook(opponentMoves, i, j);
                        break;
                    case Figure::Queen:
                        Queen(opponentMoves, i, j);
                        break;
                    case Figure::King:
                        King(opponentMoves, i, j);
                        break;
                    default:
                        break;
                    }

                    
                    for (const auto& m : opponentMoves)
                    {
                        if (m.X == kingX && m.Y == kingY)
                        {
                            return true; 
                        }
                    }
                }
            }
        }
    return false; 
}


bool chessBoard::isSquareUnderAttack(int x, int y)
{
    std::vector<move> moves;
    if (isKingInCheck(mBoard,turn))
    {
        return false;
    }
    if (turn == Figure::white) {
        std::vector<move> moves = getLegalMoves(mBoard, Figure::black);
        for (const auto& m : moves)
        {
            if (m.X == x && m.Y == y)
            {
                return false;
            }
        }
    }
    else {
        std::vector<move> moves = getLegalMoves(mBoard, Figure::white);
        for (const auto& m : moves)
        {
            if (m.X == x && m.Y == y)
            {
                return false;
            }
        }
    }

    return true;
}

bool chessBoard::isCheckmate(board b, Figure::Colors turn) {
    if (!isKingInCheck(b, turn)) {
        return false;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (mBoard.arr[i][j].color == turn) {
                std::vector<move> possibleMoves;
                switch (mBoard.arr[i][j].figure) {
                case Figure::Pawn:
                    Pawn(possibleMoves, i, j);
                    break;
                case Figure::Knight:
                    Knight(possibleMoves, i, j);
                    break;
                case Figure::Bishop:
                    Bishop(possibleMoves, i, j);
                    break;
                case Figure::Rook:
                    Rook(possibleMoves, i, j);
                    break;
                case Figure::Queen:
                    Queen(possibleMoves, i, j);
                    break;
                case Figure::King:
                    King(possibleMoves, i, j);
                    break;
                default:
                    break;
                }
                for (const auto& m : possibleMoves) {
                    board tempBoard = b;
                    tempBoard.arr[m.X][m.Y] = tempBoard.arr[m.oX][m.oY];
                    tempBoard.arr[m.oX][m.oY] = { Figure::Empty, Figure::none };

                    if (!isKingInCheck(tempBoard, turn)) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}





bool chessBoard::playMove(move req,int replace[],bool end[])
{

 
    std::vector<move> moves = getLegalMoves(mBoard, turn);
    move temp;
    for (int i = 0; i < moves.size(); ++i)
    {
        temp = moves[i];
        
        if (temp.oX == req.oX && temp.oY == req.oY && temp.X == req.X && temp.Y == req.Y)
        {
            if (mBoard.arr[req.oX][req.oY].figure == Figure::King && mBoard.arr[req.oX][req.oY].color == Figure::white && req.oX + 2 == temp.X && !wKing_moved && !wRook2_moved)
            {
                if (isSquareUnderAttack(req.oX + 2, req.oY) && isSquareUnderAttack(req.oX + 1, req.Y))
                {
                    mBoard.arr[req.X][req.Y] = mBoard.arr[req.oX][req.oY];
                    mBoard.arr[req.oX][req.oY].figure = Figure::Empty;
                    mBoard.arr[5][7] = mBoard.arr[7][7];
                    mBoard.arr[7][7].figure = Figure::Empty;
                    wKing_moved = true;
                    wRook2_moved = true;
                    replace[0] = 1, replace[1] = 7, replace[2] = 7, replace[3] = 5, replace[4] = 7;               
                }
                else {
                    return false;

                }
            }

            else if (mBoard.arr[req.oX][req.oY].figure == Figure::King && mBoard.arr[req.oX][req.oY].color == Figure::white && req.oX - 3 == temp.X && !wKing_moved && !wRook1_moved)
            {
                if(isSquareUnderAttack(req.oX-3, req.oY) && isSquareUnderAttack(req.oX-2, req.oY) && isSquareUnderAttack(req.oX-1, req.oY))
                {
                    mBoard.arr[req.X][req.Y] = mBoard.arr[req.oX][req.oY];
                    mBoard.arr[2][7] = mBoard.arr[0][7];
                    mBoard.arr[req.oX][req.oY].figure = Figure::Empty;
                    mBoard.arr[0][7].figure = Figure::Empty;
                    wKing_moved = true;
                    wRook1_moved = true;
                    replace[0] = 1, replace[1] = 0, replace[2] = 7, replace[3] = 2, replace[4] = 7;
                }
                else {
                    return false;   
                }
            }
            else if (mBoard.arr[req.oX][req.oY].figure == Figure::King && mBoard.arr[req.oX][req.oY].color == Figure::black && req.oX + 2 == temp.X && !bKing_moved && !bRook1_moved)
            {
                if (isSquareUnderAttack(req.oX+1, req.oY) && isSquareUnderAttack(req.oX + 2, req.oY))
                {
                    mBoard.arr[req.X][req.Y] = mBoard.arr[req.oX][req.oY];
                    mBoard.arr[5][0] = mBoard.arr[7][0];
                    mBoard.arr[req.oX][req.oY].figure = Figure::Empty;
                    mBoard.arr[7][0].figure = Figure::Empty;
                    bKing_moved = true;
                    bRook1_moved = true;
                    replace[0] = 1, replace[1] = 7, replace[2] = 0, replace[3] = 5, replace[4] = 0;
                }
                else {
                    return false;
                }
            }
            else if (mBoard.arr[req.oX][req.oY].figure == Figure::King && mBoard.arr[req.oX][req.oY].color == Figure::black && req.oX - 3 == temp.X && !bKing_moved && !wRook2_moved)
            {
                if (isSquareUnderAttack(req.oX - 3, req.oY) && isSquareUnderAttack(req.oX - 2, req.oY) && isSquareUnderAttack(req.oX-3, req.oY))
                {
                    mBoard.arr[req.X][req.Y] = mBoard.arr[req.oX][req.oY];
                    mBoard.arr[2][0] = mBoard.arr[0][0];
                    mBoard.arr[req.oX][req.oY].figure = Figure::Empty;
                    mBoard.arr[0][0].figure = Figure::Empty;
                    bKing_moved = true;
                    bRook2_moved = true;
                    replace[0] = 1, replace[1] = 0, replace[2] = 0, replace[3] = 2, replace[4] = 0;
                }
                else {
                    return false;
                }

            }
            else {
                mBoard.arr[req.X][req.Y] = mBoard.arr[req.oX][req.oY];
                mBoard.arr[req.oX][req.oY] = { Figure::Empty, Figure::none };

            }
            bool check = false;
        
            if(isKingInCheck(mBoard,turn))
            {
                mBoard = history[history.size() - 1];
                check = true;
                break;
            }
            if (turn == Figure::white)
            {
                if (isCheckmate(mBoard, Figure::black))
                {
                    end[0] = true;
                    return true;
                }
            }
            else {
                if (isCheckmate(mBoard, Figure::white))
                {
                    end[0] = true;
                    return true;
                }
            }
            if (!check)
            {
                if (mBoard.arr[req.X][req.Y].figure == Figure::King)
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
                if (mBoard.arr[req.X][req.Y].figure == Figure::Rook)
				{
					if (turn)
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
                history.push_back(mBoard);
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