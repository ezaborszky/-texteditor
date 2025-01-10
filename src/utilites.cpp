#include "utilites.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <map>


bool isAlphanumericKey(sf::Keyboard::Key key) {
    return (key >= sf::Keyboard::A && key <= sf::Keyboard::Z); 
}

void userInput(sf::Event event, std::map<std::string, bool>& states)
{
if(event.type == sf::Event::KeyPressed)
{
  if(event.key.code == sf::Keyboard::Left) states["left"] = true;
  if(event.key.code == sf::Keyboard::Right) states["right"] = true;
  if(event.key.code == sf::Keyboard::Up) states["up"] = true;
  if(event.key.code == sf::Keyboard::Down) states["down"] = true;
}
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
  if(states["left"] && (index > 0)) {std::cout << "LEFT" << std::endl; index--; return;}
  if(states["right"] && (index + 1 < maxSize)) {std::cout << maxSize << std::endl; index++; return;}
  if(states["up"] && (index >= 32)) {std::cout << "UP" << std::endl; index -= 32 ; return;}
  if(states["down"] && (index + 33 < maxSize)) {std::cout << "DOWN" << std::endl; index += 32; return;}

}

void alphaNumInput(sf::Event event, std::string inputChar, std::vector<std::shared_ptr<textBox>> textVec, std::size_t& index)
{
    if (event.type == sf::Event::TextEntered) {
       
      if ((event.text.unicode >= 'A' && event.text.unicode <= 'Z') ||
            (event.text.unicode >= 'a' && event.text.unicode <= 'z') ||
            (event.text.unicode >= '0' && event.text.unicode <= '9')) {

            // Convert the unicode value to a string
            inputChar = std::string(1, static_cast<char>(event.text.unicode));

            // Set the string in the textBox
            textVec[index]->text.setString(inputChar);
            index++;
        }  
    }

    if(event.type == sf::Event::KeyPressed)
    {
      if(event.key.code == sf::Keyboard::BackSpace)
      {
        textVec[index]->text.setString(" ");
        index--;
      }
    }

    if(event.type == sf::Event::KeyPressed)
    {
      if(event.key.code == sf::Keyboard::Space)
      {
        textVec[index]->text.setString(" ");
        index++;
      }
    }
}

sf::Vector2f calcDim(sf::Vector2f initMousePos, sf::Vector2f currentMousePos, sf::RectangleShape& rectangle)
{
 float xDif = currentMousePos.x - initMousePos.x;
 float yDif = currentMousePos.y - initMousePos.y;
 rectangle.setSize(sf::Vector2f(xDif,yDif));
 return sf::Vector2f(xDif, yDif);
}
