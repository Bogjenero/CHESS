#include "Logic.h"



/*bool isMove = false;
sf::Vector2f oldPos, newPos;
int current_index = -10;
int boardState[8][8] = {
    {1, 2, 3, 4, 5, 3, 2, 1},
    {6, 6, 6, 6, 6, 6, 6, 6},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {-6, -6, -6, -6, -6, -6, -6, -6},
    {-1, -2, -3, -4, -5, -3, -2, -1}
};








bool isValidMove(int oldX, int oldY, int newX, int newY) {
        int piece = boardState[oldY][oldX];
        int target = boardState[newY][newX];

        // Provjera da li je potez unutar granica ploče
        if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8) {
            return false;
        }

        // Ne može se pomaknuti na poziciju koja je već zauzeta od figure iste boje
        if ((piece > 0 && target > 0) || (piece < 0 && target < 0)) {
            return false;
        }

        int dx = newX - oldX;
        int dy = newY - oldY;

        switch (abs(piece)) {
        case 1: // Top (Rook)
            if (dx == 0 || dy == 0) {
                // Provjera da li je put čist
                int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
                int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
                int x = oldX + stepX;
                int y = oldY + stepY;
                while (x != newX || y != newY) {
                    if (boardState[y][x] != 0) {
                        return false;
                    }
                    x += stepX;
                    y += stepY;
                }
                return true;
            }
            break;
        case 2: // Konj (Knight)
            if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) {
                return true;
            }
            break;
        case 3: // Lovac (Bishop)
            if (abs(dx) == abs(dy)) {
                // Provjera da li je put čist
                int stepX = (dx > 0) ? 1 : -1;
                int stepY = (dy > 0) ? 1 : -1;
                int x = oldX + stepX;
                int y = oldY + stepY;
                while (x != newX || y != newY) {
                    if (boardState[y][x] != 0) {
                        return false;
                    }
                    x += stepX;
                    y += stepY;
                }
                return true;
            }
            break;
        case 4: // Kraljica (Queen)
            if (dx == 0 || dy == 0 || abs(dx) == abs(dy)) {
                // Kombinacija pravila topa i lovca
                int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
                int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
                if (dx != 0 && dy != 0) {
                    stepX = (dx > 0) ? 1 : -1;
                    stepY = (dy > 0) ? 1 : -1;
                }
                int x = oldX + stepX;
                int y = oldY + stepY;
                while (x != newX || y != newY) {
                    if (boardState[y][x] != 0) {
                        return false;
                    }
                    x += stepX;
                    y += stepY;
                }
                return true;
            }
            break;
        case 5: // Kralj (King)
            if (abs(dx) <= 1 && abs(dy) <= 1) {
                return true;
            }
            break;
        case 6: // Pijun (Pawn)
            int direction = (piece > 0) ? -1 : 1; // Bijeli pijun se kreće gore, crni dolje
            if (newX == oldX && boardState[newY][newX] == 0) { // Kretanje naprijed
                if (newY == oldY + direction) {
                    return true;
                }
                // Pijun se kreće dva polja naprijed sa početne pozicije
                if ((oldY == 1 && piece < 0) || (oldY == 6 && piece > 0)) {
                    if (newY == oldY + 2 * direction && boardState[oldY + direction][oldX] == 0) {
                        return true;
                    }
                }
            }
            else if (abs(newX - oldX) == 1 && newY == oldY + direction && target != 0) { // Kretanje dijagonalno za uzimanje
                return true;
            }
            break;
        }

        return false;
    }


void handleMouseClick(sf::Event::MouseButtonEvent& mouseEvent) {
    if (mouseEvent.button == sf::Mouse::Left) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int x = pos.x / 60;
        int y = pos.y / 60;

        if (!isMove) {
            if (boardState[y][x] != 0) {
                isMove = true;
                oldPos = sf::Vector2f(x * 60, y * 60);
                current_index = boardState[y][x];
            }
        }
        else {
            newPos = sf::Vector2f(x * 60, y * 60);
            if (isValidMove(oldPos.x / 60, oldPos.y / 60, x, y)) {
                boardState[int(oldPos.y) / 60][int(oldPos.x) / 60] = 0;
                boardState[y][x] = current_index;
                for (int i = 0; i < 32; ++i) {
                    if (f[i].getPosition() == oldPos) {
                        f[i].setPosition(newPos);
                        break;
                    }
                }
            }
            isMove = false;
        }
    }
}*/
