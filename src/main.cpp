#include <chrono>
#include <iostream>

#include "SliderSFML.h"
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

void drawForceVector(sf::RenderWindow& window, float angle)
{
  angle += 90;
  sf::ConvexShape arrow(7);
  arrow.setPoint(0, sf::Vector2f(-50, 0));
  arrow.setPoint(1, sf::Vector2f(0, -10));
  arrow.setPoint(2, sf::Vector2f(0, -5));
  arrow.setPoint(3, sf::Vector2f(50, -5));
  arrow.setPoint(4, sf::Vector2f(50, 5));
  arrow.setPoint(5, sf::Vector2f(0, 5));
  arrow.setPoint(6, sf::Vector2f(0, 10));
  arrow.setFillColor(sf::Color::Red);
  arrow.setOutlineColor(sf::Color::Black);
  arrow.setOutlineThickness(1);
  arrow.setOrigin(0, 0);
  arrow.setPosition(270, 300);
  arrow.setRotation(angle);
  window.draw(arrow);
}

void caclPixel(sf::RenderWindow& window, Field& f)
{
  int count = 0;
  for (char i = 0; i < f.length; i++)
  {
    for (char j = 0; j < f.height; j++)
    {
      if (f.checkMoveable(i, j))
      {
        count++;
      }
    }
  }
  std::cout << count << "\n";
}

int main()
{
  SliderSFML slider(600, 100);
  slider.create(0, 360);
  slider.setSliderValue(180);

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
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        std::cout << "pressed Space\n";
        //f.fall(slider.sliderValue);
        caclPixel(window, f);
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
      {        
        std::cout << "pressed Enter\n";
        f.draw(5,5,1);
        // f.draw(6,1,1);
        // f.draw(7,1,1);
        // f.draw(5,2,1);
        // f.draw(6,2,1);
        // f.draw(7,2,1);
        // f.draw(5,3,1);
        // f.draw(6,3,1);
        // f.draw(7,3,1);
      }
    }
    if (std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()) - last_move > std::chrono::milliseconds(20))
    {
      f.fall(slider.sliderValue);
      last_move = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
      std::cout << slider.sliderValue << '\n';
      caclPixel(window, f);
    }

    window.clear();
    drawBaseField(window);
    draw(window, f);
    slider.draw(window);
    drawForceVector(window, slider.sliderValue);
    window.display();
  }

  return 0;
}