#include "GameAPI.h"
#include <SFML/Graphics.hpp>

GameAPI::GameAPI() :Game()
{
    View();
}

GameAPI::GameAPI(int rows, int columns) : Game(rows, columns)
{
    View();
}

GameAPI::~GameAPI() {}

void GameAPI::View()
{

    const int cell_size = 30;
    bool stop = false;
    const sf::Vector2f CELL_VECTOR(cell_size, cell_size);
    sf::RenderWindow window(sf::VideoMode(cell_size * getWiersze(), cell_size * getKolumny()), "Gra w zycie");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Space)
                    stop = !stop;
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left && stop == true)
                {
                    int x = double(event.mouseButton.x) / cell_size;
                    int y = double(event.mouseButton.y) / cell_size;

                    Arr[x][y] = !Arr[x][y];
                }
                break;

            }

        }

        window.clear(sf::Color::Black);

        for (int i = 0; i < getWiersze(); i++)
        {

            for (int j = 0; j < getKolumny(); j++)
            {
                sf::RectangleShape cell;
                cell.setPosition(i * cell_size, j * cell_size);
                cell.setSize(CELL_VECTOR);
                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color::Blue);


                if (Arr[i][j] == 1) { cell.setFillColor(sf::Color::White); }

                else { cell.setFillColor(sf::Color::Black); }

                window.draw(cell);
            }

        }

        if (stop == false) { Analize(); }

        window.display();
        sf::sleep(sf::milliseconds(300));
    }
}
