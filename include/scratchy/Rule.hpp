#ifndef RULE_HPP104
#define RULE_HPP104

#include "sexp/value.hpp"
#include <functional>
#include <Event.hpp>
// Each rule contains
// A sexp::Value, which is used as a parameter by
// A predicate, which if it returns true will yeild
// A functor with the sexp::Value, which will yeild the final result
namespace scratchy {

typedef std::function<bool(sexp::Value value)> Predicate;
typedef std::function<Event(sexp::Value value)> Transform;

class Rule {
 public:
  Rule(Predicate predicate, Transform transform);
  bool test_predicate(sexp::Value value);
  Event call_transform(sexp::Value value);
 private:
  const Predicate predicate;
  const Transform transform;
};

}
#endif
