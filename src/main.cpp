#include <ctime>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "field.hpp"


size_t cell_size = 30;

void drawBaseField(sf::RenderWindow& window)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			sf::RectangleShape rectangle2(sf::Vector2f(cell_size, cell_size));
			rectangle2.setPosition(cell_size + i * cell_size, cell_size + j * cell_size);
			rectangle2.setFillColor(sf::Color::Black);
			window.draw(rectangle2);
			sf::RectangleShape rectangle(sf::Vector2f(cell_size - 2, cell_size - 2));
			rectangle.setPosition(cell_size + i * cell_size - 1, cell_size + j * cell_size - 1);
			rectangle.setFillColor(sf::Color::White);
			window.draw(rectangle);
		}
	}
}

void draw(sf::RenderWindow& window, Field& f)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (f.checkLight(i, j))
			{
				sf::RectangleShape rectangle(sf::Vector2f(cell_size - 5, cell_size - 5));
				if (j < 4)
				{
					rectangle.setFillColor(sf::Color::Green);
				}
				else
				{
					rectangle.setFillColor(sf::Color::Red);
				}
				rectangle.setPosition(cell_size + i * cell_size, cell_size + j * cell_size);
				window.draw(rectangle);
			}
		}
	}
}


int main()
{
	Field f;

	f.draw(4, 4, 1);
	f.draw(5, 4, 1);
	f.draw(6, 4, 1);
	f.draw(6, 5, 1);

	sf::RenderWindow window(sf::VideoMode(1200, 1200), "test");
	std::time_t last_move = std::time(nullptr);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				std::cout << "pressed Left\n";
				f.move("left");
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				std::cout << "pressed Right\n";
				f.move("right");
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				std::cout << "pressed Down\n";
				f.move("down");
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				std::cout << "pressed Up\n";
				f.move("up");
			}
		}
			if (std::time(nullptr) - last_move > 0.5)
			{
				f.fall();
				last_move = std::time(nullptr);
			}

		window.clear();
		drawBaseField(window);
		draw(window, f);
		window.display();
	}

	return 0;
}
