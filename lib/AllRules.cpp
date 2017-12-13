#include "AllRules.hpp"
#include "App.hpp"
#include "Event.hpp"
#include "sexp/io.hpp"
#include "sexp/parser.hpp"
#include "sexp/util.hpp"

namespace scratchy {

namespace value {
  auto init = sexp::Parser::from_string("(init)").get_car();
  auto exit = sexp::Parser::from_string("(exit)").get_car();
}

namespace predicate {
  auto init(sexp::Value value) -> bool {
    return value.get_car() == value::init;
  }
  auto exit(sexp::Value value) -> bool {
    return value.get_car() == value::exit;
  }
}

namespace transform {
  auto init(sexp::Value value) -> Event {
    auto width = value.get_cdr().get_car().as_int();
    auto height = value.get_cdr().get_cdr().get_car().as_int();
    auto title = value.get_cdr().get_cdr().get_cdr().get_car().as_string();
    App::main(width, height, title);
    return Event::NONE;
  }
  auto exit(sexp::Value value) -> Event {
    return Event::EXIT;
  }
}


auto AllRules::deflt() -> RuleIterator {
  RuleIterator AllRules;
  AllRules.add_rule(predicate::init, transform::init);
  AllRules.add_rule(predicate::exit, transform::exit);
  return AllRules;
}

}
