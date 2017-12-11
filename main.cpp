#include "config.h"
#include "sexp/io.hpp"
#include "sexp/parser.hpp"
#include "sexp/util.hpp"
#include "sexp/value.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#define noop

void app_main(int height, int width, const std::string &title) {
  sf::Window App(sf::VideoMode(height, width), title);
  while (App.isOpen()) {
    sf::Event Event;
    while(App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed) {
        App.close();
      }
      App.display();
    }
  }
}

int main(int argc, char* argv[]) {

  std::cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << std::endl;

  auto initval = sexp::Parser::from_string("(init)").get_car();
  for (std::string line; std::getline(std::cin, line);) {
    auto init_sexp = sexp::Parser::from_string(line);
    if (initval == init_sexp.get_car()) {
      auto height = init_sexp.get_cdr().get_car().as_int();
      auto width = init_sexp.get_cdr().get_cdr().get_car().as_int();
      auto title = init_sexp.get_cdr().get_cdr().get_cdr().get_car().as_string();
      app_main(height, width, title);
      return 0;
    }
  }
}
