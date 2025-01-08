#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>

class textChunk

{
friend class textCreator;
textChunk();
public:
sf::Font Font;
std::string content;
int textSize;
};


class textCreator {
public:
void create();
};
