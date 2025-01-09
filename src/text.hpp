#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <vector>
#include <memory>

class textChunk

{
public:
sf::Text text;
std::string content;
int textSize;
};


class textCreator {
public:
std::vector<std::shared_ptr<sf::Text>> textList;
void setContent(std::string content, std::size_t index);


};
