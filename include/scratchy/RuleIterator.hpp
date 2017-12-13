#ifndef RULEITERATOR_HPP147
#define RULEITERATOR_HPP147

#include "Rule.hpp"
#include <vector>

namespace scratchy {

class RuleIterator {
 public:
  void add_rule(Predicate predicate, Transform transform);
  Event iterate_rules(sexp::Value value);
 private:
  std::vector<Rule> rules;
};

}
#endif
