#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <cstddef>
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

class siteRect
{
  public:
  int xPos = 0;
  int yPos = 0;
  bool isActive = false;
  std::shared_ptr<Shape> shape;
};

class newSite
{
  public:
  sf::Window window; 
  std::vector<std::shared_ptr<siteRect>> lineVec;
  std::vector<std::vector<std::shared_ptr<siteRect>>> lines;
  newSite();
  void createSite();
  void renderSite(sf::RenderWindow& window, size_t index);
  std::size_t returnSize();
};






