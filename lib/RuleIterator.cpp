#include "RuleIterator.hpp"
#include "Event.hpp"

namespace scratchy {

void RuleIterator::add_rule(Predicate predicate, Transform transform) {
  rules.push_back(Rule(predicate, transform));
}

Event RuleIterator::iterate_rules(sexp::Value value) {
  for (auto rule : rules) {
    if (rule.test_predicate(value)) {
        return rule.call_transform(value);
    }
  }
  return Event::NONE;
}

}
