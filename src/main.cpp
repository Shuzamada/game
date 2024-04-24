#include <chrono>
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
        if (i == f.cur_shape_centre[0] && j == f.cur_shape_centre[1])
        {
          rectangle.setFillColor(sf::Color::Yellow);
        }
        else if (j < 4)
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

  f.draw(2,1,1);
  f.draw(1,2,1);
  f.draw(1,1,1);
  f.draw(1,1,1);
  f.draw(3,4,1);
  f.draw(2,2,1);
  f.draw(1,3,1);

  sf::RenderWindow window(sf::VideoMode(1200, 1200), "test");
  std::chrono::milliseconds last_move = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
        std::cout << "pressed Left\n";
        f.move("left");
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
        std::cout << "pressed Right\n";
        f.move("right");
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
        std::cout << "pressed Down\n";
        f.move("down");
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
        std::cout << "pressed Up\n";
        f.move("up");
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
      {
        std::cout << "pressed Enter\n";
        f.draw(5,1,1);
      }
    }
    if (std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()) - last_move > std::chrono::milliseconds(20))
    {
      //f.fall();
      last_move = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
    }

    window.clear();
    drawBaseField(window);
    draw(window, f);
    window.display();
  }

  return 0;
}
