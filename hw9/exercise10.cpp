#include "linklib.hpp"
#include <iostream>

int main() {
  List list;
  int value;

  // Read positive integers until zero is entered.
  while (true) {
    if (!(std::cin >> value)) {
      if (std::cin.eof())
        break;

      std::cerr << "Invalid input: enter integers only.\n";
      return 1;
    }

    if (value == 0)
      break;

    if (value < 0) {
      std::cerr << "Enter a positive integer or 0 to stop.\n";
      continue;
    }

    // Insert in sorted order and count duplicates.
    list.insert(value);
  }

  list.print();
  return 0;
}
