
#include "Iscrtavanje.h"
#include <iostream>
#include <SFML/Graphics.hpp>

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
            Squares[i][j].setPosition(sf::Vector2f(Holder.left + (i * Holder.width / 8), Holder.top + (j * Holder.height / 8)));
            Squares[i][j].setSize(sf::Vector2f(Holder.width / 8, Holder.height / 8));
        }
    }
}
void chessWin::DrawSquares()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            win.draw(Squares[i][j]);
        }
    }
}
void chessWin::DrawPieces()
{
    for (int i = 0; i < 64; ++i)
    {
        if (pieces[i].draw == 1)
        {
            win.draw(pieces[i].Sprite);
        }
    }
}
void chessWin::MapPieces()
{
    for (int i = 0; i < 64; ++i)
    {

        if (pieces[i].draw == 1)
        {
            pieces[i].Sprite.setPosition(sf::Vector2f(Holder.left + (pieces[i].x * Holder.width / 8), Holder.top + (pieces[i].y * Holder.height / 8)));
            pieces[i].Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
        }
    }
}
void chessWin::MapPieces(move curr)
{
    chessPiece* current = nullptr;
    bool capture = false;
    for (int i = 0; i < 64; ++i)
    {
        if (pieces[i].draw == 1)
        {
            if (pieces[i].x == curr.oX && pieces[i].y == curr.oY)
            {
                current = &pieces[i];
            }
            if (pieces[i].x == curr.X && pieces[i].y == curr.Y)
            {
                pieces[i].draw = 0;
                capture = true;
            }
            pieces[i].Sprite.setPosition(sf::Vector2f(Holder.left + (pieces[i].x * Holder.width / 8), Holder.top + (pieces[i].y * Holder.height / 8)));
            pieces[i].Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
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
    sColors[0] = sf::Color(118, 150, 86);
    sColors[1] = sf::Color(238, 238, 210);
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
            Squares[i][j].setFillColor(sColors[sColor]);
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
            Figure currFigure = cBoard.mBoard.arr[i][j];
            
            pieces[index].pieceID.figure = currFigure.figure;
            pieces[index].pieceID.color = currFigure.color;
            pieces[index].x = i;
            pieces[index].y = j;
            if (currFigure.figure != Figure::Empty)
            {
                int textureIndex = setTexture(currFigure);
                pieces[index].Sprite.setTexture(pieceTex[textureIndex], true);
                pieces[index].draw = 1;
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
                    Squares[projX][projY].setFillColor(sf::Color(186, 202, 68));
                    cSelect = 1;
                }
            }
            else {
                if (selected[0] == projX && selected[1] == projY) {
                    Squares[projX][projY].setFillColor(sColors[1 - ((projX + projY) % 2)]);
                    cSelect = 0;
                }
                else {
                    move m(selected[0], selected[1], projX, projY);
                    if (cBoard.playMove(m)) {
                        MapPieces(m);
                        cBoard.nextTurn();
                    }
                    Squares[selected[0]][selected[1]].setFillColor(sColors[1 - ((selected[0] + selected[1]) % 2)]);
                    cSelect = 0;
                }
            }
        }
    }
    else if (event.mouseButton.button == sf::Mouse::Button::Right) {
        Squares[selected[0]][selected[1]].setFillColor(sColors[1 - ((selected[0] + selected[1]) % 2)]);
        cSelect = 0;
    }
}

void chessWin::handleClosed() {
    win.close();
}


void chessWin::resetGame() {
    // Resetiranje ploče na početno stanje
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cBoard.mBoard.arr[i][j] = cBoard.mBoard.start[i][j];
        }
    }

    // Ponovno učitavanje slika figura prema početnom stanju
    int index = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Figure currFigure = cBoard.mBoard.arr[i][j];

            pieces[index].pieceID.figure = currFigure.figure;
            pieces[index].pieceID.color = currFigure.color;
            pieces[index].x = i;
            pieces[index].y = j;
            if (currFigure.figure != Figure::Empty) {
                int textureIndex = setTexture(currFigure);
                pieces[index].Sprite.setTexture(pieceTex[textureIndex], true);
                pieces[index].draw = 1;
            }
            else {
                pieces[index].draw = 0;
            }
            ++index;
        }
    }

    // Ažuriraj prikaz figura
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
                        // Zatvori trenutni prozor igre
                        win.close();

                        // Resetiraj igru
                        resetGame();

                        // Postavi stanje igre na početni ekran
                        state = GameState::StartScreen;

                        // Ponovno otvorite glavni prozor igre
                        win.create(sf::VideoMode(sX, sY), "chess");

                        // Inicijalizacija i prikaz početnog ekrana
                        FitToHolder();
                        MapPieces();
                        DrawSquares();
                        DrawPieces();

                        // Izađite iz petlje
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

            // Možeš dodati druge evente ovdje, ako su potrebni

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