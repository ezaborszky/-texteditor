#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <map>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <memory>
#include "site.hpp"

void setIndex(std::map<std::string, bool> states, std::size_t& index, std::size_t maxSize);
void userInput(sf::Event event, std::map<std::string, bool>& states);
void alphaNumInput(sf::Event event, std::string inputChar, std::vector<std::shared_ptr<textBox>> textVec, std::size_t& index);
sf::Vector2f calcDim(sf::Vector2f initMousePos, sf::Vector2f currentMousePos, sf::RectangleShape& rectangle);
