#include "iscrtavanje.h"


    sf::Texture t1, t2;
    sf::Sprite board;
    sf::Sprite figure;
    sf::Sprite f[32];
    void Inicijalizacija() {
        t1.loadFromFile("images/board.png");
        t2.loadFromFile("images/figures.png");
        board.setTexture(t1);
        figure.setTexture(t2);
        f[0] = sf::Sprite(t2, sf::IntRect(0, 0, 60, 60));
        f[1] = sf::Sprite(t2, sf::IntRect(50, 0,60, 58));
        f[2] = sf::Sprite(t2, sf::IntRect(110, 0, 60, 58));
        f[3] = sf::Sprite(t2, sf::IntRect(170, 0, 60, 58));
        f[4] = sf::Sprite(t2, sf::IntRect(230, 0, 60, 58));
        f[5] = sf::Sprite(t2, sf::IntRect(110, 0, 60, 58));
        f[6] = sf::Sprite(t2, sf::IntRect(50, 0, 60, 58));
        f[7] = sf::Sprite(t2, sf::IntRect(0, 0, 60, 58));

        f[9] = sf::Sprite(t2, sf::IntRect(290, 0, 60, 58));
        f[10] = sf::Sprite(t2, sf::IntRect(290, 0, 60, 58));
        f[8] = sf::Sprite(t2, sf::IntRect(290, 0, 60, 58));
        f[11] = sf::Sprite(t2, sf::IntRect(290, 0, 60, 58));
        f[13] = sf::Sprite(t2, sf::IntRect(290, 0, 60, 58));
        f[14] = sf::Sprite(t2, sf::IntRect(290, 0, 60, 58));
        f[15] = sf::Sprite(t2, sf::IntRect(290, 0, 60, 58));
        f[12] = sf::Sprite(t2, sf::IntRect(290, 0, 60, 58));       
        
        f[16] = sf::Sprite(t2, sf::IntRect(0, 60, 60, 60));
        f[17] = sf::Sprite(t2, sf::IntRect(50, 60, 60, 58));
        f[18] = sf::Sprite(t2, sf::IntRect(110, 60, 60, 58));
        f[19] = sf::Sprite(t2, sf::IntRect(170, 60, 60, 58));
        f[20] = sf::Sprite(t2, sf::IntRect(230, 60, 60, 58));
        f[21] = sf::Sprite(t2, sf::IntRect(110, 60, 60, 58));
        f[22] = sf::Sprite(t2, sf::IntRect(50, 60, 60, 58));
        f[23] = sf::Sprite(t2, sf::IntRect(0, 60, 60, 58));

        f[24] = sf::Sprite(t2, sf::IntRect(290, 60, 60, 58));
        f[25] = sf::Sprite(t2, sf::IntRect(290, 60, 60, 58));
        f[26] = sf::Sprite(t2, sf::IntRect(290, 60, 60, 58));
        f[27] = sf::Sprite(t2, sf::IntRect(290, 60, 60, 58));
        f[28] = sf::Sprite(t2, sf::IntRect(290, 60, 60, 58));
        f[29] = sf::Sprite(t2, sf::IntRect(290, 60, 60, 58));
        f[30] = sf::Sprite(t2, sf::IntRect(290, 60, 60, 58));
        f[31] = sf::Sprite(t2, sf::IntRect(290, 60, 60, 58));


        f[0].setPosition(25, 25);
        f[1].setPosition(80, 25);
        f[2].setPosition(140, 25);
        f[3].setPosition(200, 25);
        f[4].setPosition(260, 25);
        f[5].setPosition(305, 25);
        f[6].setPosition(360, 25);
        f[7].setPosition(415, 25);
        int k1 = 30;
        for (int i = 8; i < 13; ++i)
        {
            f[i].setPosition(k1, 80);
            k1 += 60;
        }
        f[13].setPosition(320, 80);
        f[14].setPosition(375, 80);
        f[15].setPosition(430, 80);


        f[16].setPosition(25, 420);
        f[17].setPosition(80, 420);
        f[18].setPosition(140, 420);
        f[19].setPosition(200, 420);
        f[20].setPosition(260, 420);
        f[21].setPosition(305, 420);
        f[22].setPosition(360, 420);
        f[23].setPosition(415, 420);

        int k2 = 30;
        for (int i = 24; i < 29; ++i)
        {
            f[i].setPosition(k2, 365);
            k2 += 60;
        }
        f[29].setPosition(320, 365);
        f[30].setPosition(375, 365);
        f[31].setPosition(430, 365);

    }