#pragma once
#include <map>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
void setIndex(std::map<std::string, bool> states, std::size_t& index, std::size_t maxSize);
void userInput(sf::Event event, std::map<std::string, bool>& states);


