cmake_minimum_required(VERSION 3.20)

project(Linkedlist
  DESCRIPTION "Linkedlist homework"
  VERSION 1.0
  LANGUAGES CXX
)

# First executable: library tests.
add_executable(linktester linktests.cpp linklib.hpp)
target_compile_features(linktester PRIVATE cxx_std_23)

# Second executable: Exercise 10.
add_executable(exercise10 exercise10.cpp linklib.hpp)
target_compile_features(exercise10 PRIVATE cxx_std_23)

enable_testing()
add_test(NAME linked_list_tests COMMAND linktester)

install(TARGETS linktester exercise10 DESTINATION .)
