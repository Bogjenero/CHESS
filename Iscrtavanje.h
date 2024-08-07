#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>
#include "Board.h";

struct chessPiece {
	sf::Sprite Sprite; // prikazuje vizualni prikaz figure
	int pieceID, x, y; // ID figure, x i y koordinate figure
	bool draw = 0; // jel figuru treba crtati ili ne 
};


class chessWin {
private:
	sf::RenderWindow win; // prozor
	sf::RectangleShape Squares[8][8]; //šahovska ploča
	sf::IntRect Holder; // pravokutnik za šahovsku ploču
	sf::Color sColors[2]; // boje za polja
	sf::Texture pieceTex[12]; // figure (bijele,crne)
	chessPiece pieces[64]; // figure
	chessBoard cBoard; //šahovska ploča
	int selected[2]; // odabrana figura
	bool cSelect = 0; // jel odabrana figura
	int sX, sY; // x,y koordinate

	//sf::Sound sounds[4];
	void FitToHolder(); // prilagođava veličinu i poziciju kvadrata na šahovskoj ploči prema veličini pravokutnika
	void DrawSquares(); // crta kvadrate na šahovskoj ploči
	void DrawPieces(); // crta figure
	void MapPieces(move curr); // postavlja figure na šahovsku ploču prema zadnjem potezu
	void MapPieces(); // ažurira pozicije svih figura na početku igre.
public:
	chessWin(int width, int height, const char* name, const char* imgPath[12]); // konstruktor
	bool Update(); // rukuje događajima koji su izvedeni na prozoru
};