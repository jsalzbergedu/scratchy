cmake_minimum_required(VERSION 2.6)
project( lib )

add_library(rule Rule.cpp)
add_library(ruleiterator RuleIterator.cpp)
add_library(app App.cpp)
add_library(allrules AllRules.cpp)

target_link_libraries(rule sexp)
target_link_libraries(ruleiterator rule sexp)
target_link_libraries(allrules ruleiterator sexp app)
