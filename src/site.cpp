#include "site.hpp"
#include <SFML/Window/Window.hpp>
#include <memory>
#include <SFML/Graphics.hpp>

void newSite::createSite()
{
  int xPos = 100;
  int yPos = 100;

  auto rect = std::shared_ptr<siteRect>(new siteRect);
  rect->shape = std::make_shared<Shape>(sf::Vector2(11.f,11.f));
  lineVec.push_back(rect);
}

void newSite::renderSite(sf::RenderWindow& window)
{
  for(auto a : lineVec)
  {
    window.draw(a->shape->rectangle); 
  }
}

newSite::newSite(){};
