
#include "Iscrtavanje.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"

const std::string defaultTheme[12] = {
                                "./images/Pieces/Default/wp.png",
                            "./images/Pieces/Default/wr.png",
                            "./images/Pieces/Default/wn.png",
                            "./images/Pieces/Default/wb.png",
                            "./images/Pieces/Default/wk.png",
                            "./images/Pieces/Default/wq.png",
                            "./images/Pieces/Default/bp.png",
                            "./images/Pieces/Default/br.png",
                            "./images/Pieces/Default/bn.png",
                            "./images/Pieces/Default/bb.png",
                            "./images/Pieces/Default/bk.png",
                            "./images/Pieces/Default/bq.png" };


void chessWin::FitToHolder()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            boardSquares[i][j].setPosition(sf::Vector2f(Holder.left + (i * Holder.width / 8), Holder.top + (j * Holder.height / 8)));
            boardSquares[i][j].setSize(sf::Vector2f(Holder.width / 8, Holder.height / 8));
        }
    }
}
void chessWin::DrawSquares()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            win.draw(boardSquares[i][j]);
        }
    }
}
void chessWin::DrawPieces()
{
    for (int i = 0; i < 64; ++i)
    {
        if (chessPieces[i].draw == 1)
        {
            win.draw(chessPieces[i].Sprite);
        }
    }
}
void chessWin::MapPieces()
{
    for (int i = 0; i < 64; ++i)
    {

        if (chessPieces[i].draw == 1)
        {
            chessPieces[i].Sprite.setPosition(sf::Vector2f(Holder.left + (chessPieces[i].x * Holder.width / 8), Holder.top + (chessPieces[i].y * Holder.height / 8)));
            chessPieces[i].Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
        }
    }
}
void chessWin::MapPieces(move curr)
{
    chessPiece* current = nullptr;
    bool capture = false;
    for (int i = 0; i < 64; ++i)
    {
        if (chessPieces[i].draw == 1)
        {
            if (chessPieces[i].x == curr.oX && chessPieces[i].y == curr.oY)
            {
                current = &chessPieces[i];
            }
            if (chessPieces[i].x == curr.X && chessPieces[i].y == curr.Y)
            {
                chessPieces[i].draw = 0;
                capture = true;
            }
            chessPieces[i].Sprite.setPosition(sf::Vector2f(Holder.left + (chessPieces[i].x * Holder.width / 8), Holder.top + (chessPieces[i].y * Holder.height / 8)));
            chessPieces[i].Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
        }
    }
    current->x = curr.X;
    current->y = curr.Y;

    current->Sprite.setPosition(sf::Vector2f(Holder.left + (current->x * Holder.width / 8), Holder.top + (current->y * Holder.height / 8)));
    current->Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
}


int setTexture(Figure currFigure)
{
    if (currFigure.color == Figure::white)
    {
        if (currFigure.figure == Figure::Pawn)
        {
            return 0;
        }
        else if (currFigure.figure == Figure::Rook)
        {
            return 1;
        }
        else if (currFigure.figure == Figure::Knight)
        {
            return 2;
        }
        else if (currFigure.figure == Figure::King)
        {
            return 4;
        }
        else if (currFigure.figure == Figure::Bishop)
        {
            return 3;
        }
        else if (currFigure.figure == Figure::Queen)
        {
            return 5;
        }
    }
    else {
        if (currFigure.figure == Figure::Pawn)
        {
            return 6;
        }
        else if (currFigure.figure == Figure::Rook)
        {
            return 7;
        }
        else if (currFigure.figure == Figure::Knight)
        {
            return 8;
        }
        else if (currFigure.figure == Figure::King)
        {
            return 10;
        }
        else if (currFigure.figure == Figure::Bishop)
        {
            return 9;
        }
        else if (currFigure.figure == Figure::Queen)
        {
            return 11;
        }

    }
}

chessWin::chessWin(int width, int height, const char* name, const std::string imgPath[12])
{
    state = GameState::StartScreen;
    bool sColor = 1;
    playerColors[0] = sf::Color(118, 150, 86);
    playerColors[1] = sf::Color(238, 238, 210);
    sX = width;
    sY = height;
    Holder.left = 0;
    Holder.top = 0;
    Holder.width = width;
    Holder.height = height;
    button.setSize(sf::Vector2f(200, 100));
    button.setPosition(300, 350);
    button.setFillColor(sf::Color::Blue);

    
   
    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
    buttonText.setFont(font);
    buttonText.setString("Start");
    buttonText.setCharacterSize(30);
    buttonText.setFillColor(sf::Color::White);

    buttonText.setPosition(350,383);
     
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            boardSquares[i][j].setFillColor(playerColors[sColor]);
            sColor = !sColor;
        }
        sColor = !sColor;
    }
    FitToHolder();
    sf::IntRect blank;
    for (int i = 0; i < 12; ++i)
    {
        pieceTex[i].loadFromFile(imgPath[i], blank);
    }
    int index = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Figure currFigure = cBoard.chessBoard.arr[i][j];
            
            chessPieces[index].pieceID.figure = currFigure.figure;
            chessPieces[index].pieceID.color = currFigure.color;
            chessPieces[index].x = i;
            chessPieces[index].y = j;
            if (currFigure.figure != Figure::Empty)
            {
                int textureIndex = setTexture(currFigure);
                chessPieces[index].Sprite.setTexture(pieceTex[textureIndex], true);
                chessPieces[index].draw = 1;
            }
            ++index;
        }
    }
    MapPieces();
    win.create(sf::VideoMode(width, height), name);
}





void chessWin::handleResized() {
    sX = win.getSize().x;
    sY = win.getSize().y;
    win.setView(sf::View(sf::FloatRect(0, 0, sX, sY)));
    if (sX > sY) {
        Holder.width = sY;
        Holder.height = sY;
        Holder.left = sX / 2 - Holder.width / 2;
        Holder.top = 0;
    }
    else {
        Holder.width = sX;
        Holder.height = sX;
        Holder.top = sY / 2 - Holder.height / 2;
        Holder.left = 0;
    }
    MapPieces();
    FitToHolder();
}

void chessWin::handleMouseButtonPressed(sf::Event& event) {
    if (event.mouseButton.button == sf::Mouse::Button::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(win);
        if (state == GameState::StartScreen) {
            if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                state = GameState::ChessBoard;
                
                MapPieces();
            }
        }
        else if (state == GameState::ChessBoard) {
            int pX = event.mouseButton.x;
            int pY = event.mouseButton.y;
            int projX = ((pX - Holder.left) - ((pX - Holder.left) % (Holder.width / 8))) / (Holder.width / 8);
            int projY = ((pY - Holder.top) - ((pY - Holder.top) % (Holder.height / 8))) / (Holder.height / 8);
            if (cSelect == 0) {
                if (pX >= Holder.left && pX <= Holder.left + Holder.width && pY > Holder.top && pY < Holder.top + Holder.height) {
                    selected[0] = projX;
                    selected[1] = projY;
                    boardSquares[projX][projY].setFillColor(sf::Color(186, 202, 68));
                    cSelect = 1;
                }
            }
            else {
                if (selected[0] == projX && selected[1] == projY) {
                    boardSquares[projX][projY].setFillColor(playerColors[1 - ((projX + projY) % 2)]);
                    cSelect = 0;
                }
                else {

                    move m(selected[0], selected[1], projX, projY);

                    int replace[4] = {0,0,0,0};
                    bool rotation = false;
                    bool end = false;

                    if (cBoard.playMove(m,replace,end,rotation)) {
                        if(rotation)
						{
							 MapPieces(m);
                              move m2 = move(replace[0], replace[1], replace[2], replace[3]);
                              MapPieces(m2);
                              cBoard.nextTurn();
						}
                        else {
                            MapPieces(m);
                            if (end) {
                                DrawSquares();
                                DrawPieces();
                                win.display();
                                drawVictoryWindow(cBoard.turn);
                            }
                            else {
                                cBoard.nextTurn();
                            }
                        }
                    }
                    boardSquares[selected[0]][selected[1]].setFillColor(playerColors[1 - ((selected[0] + selected[1]) % 2)]);
                    cSelect = 0;
                }
            }
        }
    }
    else if (event.mouseButton.button == sf::Mouse::Button::Right) {
        boardSquares[selected[0]][selected[1]].setFillColor(playerColors[1 - ((selected[0] + selected[1]) % 2)]);
        cSelect = 0;
    }
}

void chessWin::handleClosed() {
    win.close();
}


void chessWin::resetGame() {
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cBoard.chessBoard.arr[i][j] = cBoard.chessBoard.start[i][j];
        }
    }

    
    int index = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Figure currFigure = cBoard.chessBoard.arr[i][j];

            chessPieces[index].pieceID.figure = currFigure.figure;
            chessPieces[index].pieceID.color = currFigure.color;
            chessPieces[index].x = i;
            chessPieces[index].y = j;
            if (currFigure.figure != Figure::Empty) {
                int textureIndex = setTexture(currFigure);
                chessPieces[index].Sprite.setTexture(pieceTex[textureIndex], true);
                chessPieces[index].draw = 1;
            }
            else {
                chessPieces[index].draw = 0;
            }
            ++index;
        }
    }

   
    MapPieces();
    FitToHolder();
}


void chessWin::showEndWindow()
{
    
    sf::RenderWindow endWindow(sf::VideoMode(400, 200), "End Window");

    
    sf::RectangleShape button(sf::Vector2f(250, 50));
    button.setFillColor(sf::Color::Green);
    button.setPosition(100, 75);

    
    sf::Font font;
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) 
    {
        return; 
    }

    sf::Text buttonText("Finish the game", font, 24);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(150, 85); 

   
    while (endWindow.isOpen())
    {
        sf::Event event;
        while (endWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                endWindow.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(endWindow);
                    if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        
                        win.close();

                        
                        resetGame();

                       
                        state = GameState::StartScreen;
                        if(cBoard.turn == Figure::black)
						{
							cBoard.nextTurn();
						}   
                       
                        win.create(sf::VideoMode(sX, sY), "chess");

                      
                        FitToHolder();
                        MapPieces();
                        DrawSquares();
                        DrawPieces();

                        
                        return;
                    }
                }
            }
        }

        endWindow.clear();
        endWindow.draw(button);
        endWindow.draw(buttonText);
        endWindow.display();
    }
}


void chessWin::drawVictoryWindow(Figure::Colors turn) {

    sf::RenderWindow Victorywindow(sf::VideoMode(400, 200), "Victory!");


    sf::Font font;
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    std::string s;
    if(turn == Figure::white) {
		s = "white";
	}
	else {
		s = "black";
	}
    std::string message = "The color " + s + " has won!";
    text.setString(message);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(Victorywindow.getSize().x / 2.0f,
        Victorywindow.getSize().y / 2.0f - 20.0f));

    sf::RectangleShape button(sf::Vector2f(100, 50));
    button.setFillColor(sf::Color::Green);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);
    button.setPosition(Victorywindow.getSize().x / 2.0f - 50, Victorywindow.getSize().y / 2.0f + 20);

    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setCharacterSize(18);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setStyle(sf::Text::Bold);
    buttonText.setString("OK");
    buttonText.setOrigin(buttonText.getLocalBounds().left + buttonText.getLocalBounds().width / 2.0f,
        buttonText.getLocalBounds().top + buttonText.getLocalBounds().height / 2.0f);
    buttonText.setPosition(button.getPosition().x + button.getSize().x / 2.0f,
        button.getPosition().y + button.getSize().y / 2.0f);

    while (Victorywindow.isOpen()) {
        sf::Event event;
        while (Victorywindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Victorywindow.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(Victorywindow);
                    if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                        win.close();


                        resetGame();


                        state = GameState::StartScreen;

                        win.create(sf::VideoMode(sX, sY), "chess");


                        FitToHolder();
                        MapPieces();
                        DrawSquares();
                        DrawPieces();


                        return;
                    }
                }
            }

        }
        Victorywindow.clear();

        Victorywindow.draw(text);
        Victorywindow.draw(button);
        Victorywindow.draw(buttonText);

        Victorywindow.display();
    }
}





bool chessWin::Update() {
    sf::Event event;
    while (win.pollEvent(event)) {

        switch (event.type) {
        case sf::Event::Resized:
            handleResized();
            break;

        case sf::Event::MouseButtonPressed:
            handleMouseButtonPressed(event);
            break;

        case sf::Event::Closed:
            handleClosed();
            return false;

            

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape && state == GameState::ChessBoard)
            {
                showEndWindow();
            }
        }
    }

    win.clear();

    if (state == GameState::StartScreen) {
        win.draw(button);
        win.draw(buttonText);
    }
    else if (state == GameState::ChessBoard) {
        DrawSquares();
        DrawPieces();
    }

    win.display();
    return true;
}