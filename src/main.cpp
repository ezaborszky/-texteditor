#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "text.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include "site.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    textCreator newCreator;
    newSite site;
    site.createSite();
    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }

        ImGui::SFML::Update(window, deltaClock.restart());

        window.clear();
        site.renderSite(window);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
