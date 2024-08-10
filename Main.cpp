#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>
#include <time.h>
#include <iostream>
#include <fstream>

#include "Iscrtavanje.h"
using namespace sf;


int main()
{

	const char* defaultTheme[12] = { 
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




	chessWin window(800, 800, "chess", defaultTheme);

	while (window.Update())
	{
	
	}
	return 0;
}

