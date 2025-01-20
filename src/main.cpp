#include "site.hpp"
#include "text.hpp"
#include "utilites.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstddef>
#include <imgui-SFML.h>
#include <imgui.h>
#include <map>
#include <string>

int main() {
  std::map<std::string, bool> keyState{
      {"left", false}, {"right", false}, {"up", false}, {"down", false}};
  sf::RenderWindow window(sf::VideoMode(1200, 1720), "ImGui + SFML = <3");
  window.setFramerateLimit(60);
  ImGui::SFML::Init(window);
  textCreator newCreator;
  newSite site;
  site.createSite();
  std::size_t maxSize = site.returnSize();
  std::size_t cursorsIndex = 1;
  std::string inputChar = "x";
  sf::Clock deltaClock;
  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);
      userInput(event, keyState);
      if (event.type == sf::Event::KeyPressed) {
        setIndex(keyState, cursorsIndex, maxSize, site.lineVec);
      }

      alphaNumInput(event, inputChar, site.textVec, cursorsIndex);
      site.selectArea(event, window, cursorsIndex);
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    window.clear();
    site.renderSite(window, cursorsIndex);

    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();

  return 0;
}
