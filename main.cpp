#include "config.h"
#include "sexp/parser.hpp"
#include "sexp/util.hpp"
#include "AllRules.hpp"
#include "Event.hpp"
#include <iostream>

using scratchy::AllRules;

const auto initval = sexp::Parser::from_string("(init)").get_car();
int main(int argc, char* argv[]) {

  std::cout << "(version \"" << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << "\")" << std::endl;

  auto all_rules = AllRules::deflt();
  while (true) {
    for (std::string line; std::getline(std::cin, line);) {
      switch(all_rules.iterate_rules(sexp::Parser::from_string(line))) {
      case scratchy::Event::EXIT:
	std::cout <<"(event exit)\n";
	return 0;
      case scratchy::Event::NONE:
	std::cout << "(event none)\n";
	break;
      }
    }
  }
}
