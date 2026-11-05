#include "linklib.hpp"
#include <iostream>
#include <stdexcept>

void check(bool condition) {
  if (!condition)
    throw std::runtime_error("A test failed");
}

int main() {
  try {
    List list;

    // Test an empty list.
    check(list.empty());
    check(list.length() == 0);
    check(!list.contains_value(3));

    bool threw = false;
    try {
      list.headnode();
    } catch (const std::out_of_range &) {
      threw = true;
    }
    check(threw);

    // Test the first insertion.
    list.insert(3);
    check(list.length() == 1);
    check(list.contains_value(3));
    check(!list.contains_value(4));

    // Exercise 7: insert at the head.
    list.insert(2);
    check(list.length() == 2);
    check(list.contains_value(2));
    check(list.contains_value(3));
    check(list.headnode().value() == 2);
    check(list.headnode().count() == 1);

    // Exercise 6: insert at the tail.
    list.insert(6);
    check(list.length() == 3);
    check(list.contains_value(6));

    // Exercise 8: insert in the middle.
    list.insert(4);
    check(list.length() == 4);
    check(list.contains_value(4));
    check(list.contains_value(3));

    // Exercise 9: count duplicates in a separate list.
    List duplicates;
    duplicates.insert(3);
    duplicates.insert(3);

    check(duplicates.length() == 1);
    check(duplicates.contains_value(3));
    check(duplicates.headnode().value() == 3);
    check(duplicates.headnode().count() == 2);

    // Verify sorted order and counts throughout the list.
    list.insert(3);
    list.insert(6);

    const int values[] = {2, 3, 4, 6};
    const int counts[] = {1, 2, 1, 2};

    Node current = list.headnode();

    for (int i = 0; i < 4; ++i) {
      check(current.value() == values[i]);
      check(current.count() == counts[i]);
      check(current.has_next() == (i < 3));

      if (i < 3)
        current = *current.nextnode();
    }

    std::cout << "All tests passed!\n";
  } catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }

  return 0;
}
