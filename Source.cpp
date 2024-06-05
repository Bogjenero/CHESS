#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
#include "Iscrtavanje.h";

using namespace sf;


int main()
{

	RenderWindow window(VideoMode(500, 500), "CHESS");

	Inicijalizacija();
	while(window.isOpen())
	{
		Event e;
		while(window.pollEvent(e))
		{
			if(e.type == Event::Closed)
			{
				window.close();
			}

		}

		window.clear();
		window.draw(board);


		for (int i = 0; i < 32; ++i)
		{
			window.draw(f[i]);
		}
				
		window.display();
	}
	return 0;
}

