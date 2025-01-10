#include "site.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <cstddef>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "utilites.hpp"

void newSite::createSite()
{
  float xPos = 30;
  float yPos = 100;
  int x = 0;
  int y = 0; 

  if(!myFont.loadFromFile("ARIAL.TTF")){std::cout << "Couldn't load font." << std::endl;};
  for(int i = 799; i >= 0; i-- )
  {
    auto rect = std::shared_ptr<siteRect>(new siteRect);
    rect->shape = std::make_shared<Shape>(sf::Vector2(20.f,20.f));
    rect->shape->rectangle.setPosition(sf::Vector2f(xPos, yPos));
    rect->xPos = xPos;
    rect->x = x;
    rect->y = y;
    rect->yPos = yPos;
    rect->rectId = i;
    lineVec.push_back(rect);

    auto text = std::make_shared<textBox>();
    text->text.setPosition(sf::Vector2f(xPos + 5, yPos));
    text->text.setFont(myFont);
    text->text.setFillColor(sf::Color::White);
    text->text.setCharacterSize(15);
    text->text.setString(" ");
    text->textId = i;
    textVec.push_back(text);
    xPos += 23;
    ++x;
    if(i != 800 &&(i%32) == 0 ) {xPos = 30; yPos += 22; x = 0; ++y;};

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

  for(std::size_t x = 0; x < textVec.size(); ++x)
  {
   textVec[x]->isActive = (index == x);
   if(textVec[x]->isActive)
   {
     textVec[x]->text.setFillColor(sf::Color::Black);
   }else{textVec[x]->text.setFillColor(sf::Color::White);};
   window.draw(textVec[x]->text);
   }

  if(selectAreaRect != nullptr)
  { 
    sf::Vector2f curMousepos =  sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    calcDim(initMousepos, curMousepos, selectAreaRect->rectangle);
    window.draw(selectAreaRect->rectangle);
  }
}

std::size_t newSite::returnSize()
{

  size_t size = lineVec.size();
  return size;
}

newSite::newSite(){};

 void newSite::selectArea(sf::Event event, sf::RenderWindow& window)
{
  if(event.type == sf::Event::MouseButtonPressed)
  {
  selectAreaRect = std::make_shared<Shape>(sf::Vector2f(50.f, 50.f));
  initMousepos =  sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
  selectAreaRect->rectangle.setPosition(initMousepos);
  }

  if(event.type == sf::Event::MouseButtonReleased)
  {
  selectAreaRect = nullptr; 
  }


 }
