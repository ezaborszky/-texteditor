#include "site.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Window.hpp>
#include <cstddef>
#include <memory>
#include <SFML/Graphics.hpp>

void newSite::createSite()
{
  float xPos = 30;
  float yPos = 100;

  for(int i = 799; i >= 0; i-- )
  {
    auto rect = std::shared_ptr<siteRect>(new siteRect);
    rect->shape = std::make_shared<Shape>(sf::Vector2(20.f,20.f));
    rect->shape->rectangle.setPosition(sf::Vector2f(xPos, yPos));
    rect->xPos = xPos;
    rect->yPos = yPos;
    xPos += 23;
    if(i != 800 &&(i%32) == 0 ) {xPos = 30; yPos += 22;};
    lineVec.push_back(rect);

  }
 }

void newSite::renderSite(sf::RenderWindow& window, size_t index)
{
  for(std::size_t i = 0; i < lineVec.size(); ++i)
  {
       
       lineVec[i]->isActive = (index == i);
       if(lineVec[i]->isActive) 
       {lineVec[i]->shape->rectangle.setFillColor(sf::Color(200,200,200));}
       else{lineVec[i]->shape->rectangle.setFillColor(sf::Color(20,20,20));};
       window.draw(lineVec[i]->shape->rectangle);

  }


}

std::size_t newSite::returnSize()
{
  return lineVec.size();
}

newSite::newSite(){};
