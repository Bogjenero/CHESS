#pragma once

#include <SFML/Graphics.hpp>



void handleMouseClick(sf::Event::MouseButtonEvent& mouseEvent);
extern sf::Vector2f oldPos, newPos;
extern int current_index;
extern int boardState[8][8];
extern bool isValidMove(int oldX, int oldY, int newX, int newY);