#include "utilites.hpp"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <map>


void userInput(sf::Event event, std::map<std::string, bool>& states)
{
if(event.key.code == sf::Keyboard::Left) states["left"] = true;
if(event.key.code == sf::Keyboard::Right) states["right"] = true;

if(event.type == sf::Event::KeyReleased)
{
  for (auto& pair : states)
  {
    pair.second = false;
  }
}
}

void setIndex(std::map<std::string, bool> states, std::size_t& index, std::size_t maxSize)
{
  if(states["left"]) {std::cout << "LEFT" << std::endl; index--; return;}
  if(states["right"]) {std::cout << "RIGHT" << std::endl; index++; return;}
}
