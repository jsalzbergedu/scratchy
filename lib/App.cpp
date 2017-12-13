#include "App.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

namespace scratchy {

void App::main(int height, int width, const std::string &title) {
  sf::RenderWindow App(sf::VideoMode(width, height), title);

  sf::Texture texture;
  if (!texture.loadFromFile("image.png")) {
    std::cout << "(error " << "(open-image \"image.png\")" "failed)";
  }
  sf::Sprite sprite;
  sprite.setTexture(texture);
  while (App.isOpen()) {
    sf::Event Event;
    while(App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed) {
        App.close();
      }
      App.clear();
      App.draw(sprite);
      App.display();
    }
  }
}

}
