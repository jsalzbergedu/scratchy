#include "sexp/value.hpp"
#include "Rule.hpp"

namespace scratchy {

Rule::Rule(Predicate predicate, Transform transform):predicate(predicate), transform(transform) {
}

bool Rule::test_predicate(sexp::Value value) {
  return predicate(value);
}

Event Rule::call_transform(sexp::Value value) {
  return transform(value);
}

}
