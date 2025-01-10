#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <cstddef>
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include <memory>

class Shape
 
{
  public:
    sf::RectangleShape rectangle;
    Shape(sf::Vector2<float> size)
      :rectangle(size)
    {

    }
};

class textBox
{
  public:
    sf::Text text;
    textBox(){};
    int textId = 0;
    int x = 1;
    int y = 1;
    bool isActive;
};

class siteRect
{
  public:
  float xPos = 0.f;
  float yPos = 0.f;

  int x = 1;
  int y = 1;

  int rectId = 0;
  bool isActive = false;
  std::shared_ptr<Shape> shape;
};

class newSite
{
  public:
  sf::Font myFont;
  sf::Window window; 
  std::shared_ptr<Shape> selectAreaRect;
  sf::Vector2f initMousepos = sf::Vector2f(1.f, 1.f);
  std::vector<std::shared_ptr<siteRect>> lineVec;
  std::vector<std::shared_ptr<textBox>> textVec;
  std::vector<std::vector<std::shared_ptr<siteRect>>> lines;
  newSite();
  void createSite();
  void renderSite(sf::RenderWindow& window, size_t index);
  std::size_t returnSize();
  void mouseClick(sf::Event, sf::RenderWindow& window, size_t& index);
  void selectArea(sf::Event, sf::RenderWindow& window);
};






