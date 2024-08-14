﻿#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>
#include "Board.h"


struct chessPiece {
	sf::Sprite Sprite; // prikazuje vizualni prikaz figure
	Figure pieceID;
	int x, y; // ID figure, x i y koordinate figure
	bool draw = 0; // jel figuru treba crtati ili ne 
};

enum class GameState { StartScreen, ChessBoard };

class chessWin {
private:
	
	sf::RenderWindow win; // prozor
	sf::RectangleShape button; // button
	sf::RectangleShape boardSquares[8][8]; //šahovska ploča
	sf::IntRect Holder; // pravokutnik za šahovsku ploču
	sf::Color playerColors[2]; // boje za polja
	sf::Texture pieceTex[12]; // figure (bijele,crne)
	chessPiece chessPieces[64]; // figure
	int selected[2]; // odabrana figura
	bool cSelect = 0; // jel odabrana figura
	int sX, sY; // x,y koordinate
	sf::Text buttonText; // tekst na gumbu
	sf::Font font; // font za tekst
	GameState state;

	//sf::Sound sounds[4];
	void FitToHolder(); // prilagođava veličinu i poziciju kvadrata na šahovskoj ploči prema veličini pravokutnika
	void DrawSquares(); // crta kvadrate na šahovskoj ploči
	void DrawPieces(); // crta figure
	void MapPieces(move curr); // postavlja figure na šahovsku ploču prema zadnjem potezu
	void MapPieces(); // ažurira pozicije svih figura na početku igre.
	
	void handleResized(); // Nova funkcija za rukovanje promjenom veličine prozora
	void handleMouseButtonPressed(sf::Event& event); // Nova funkcija za rukovanje pritiskom tipke miša
	void handleClosed(); // Nova funkcija za rukovanje zatvaranjem prozora
	void showEndWindow();
	void resetGame();
	void drawVictoryWindow(Figure::Colors turn);
public:
	chessBoard cBoard; //šahovska ploča
	bool Update();// rukuje događajima koji su izvedeni na prozoru
	chessWin(int width, int height, const char* name, const std::string imgPath[12]); 

};

