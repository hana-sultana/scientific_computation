#ifndef LINKLIB_HPP
#define LINKLIB_HPP

#include <iostream>
#include <memory>
#include <stdexcept>

class Node {
private:
  int datavalue{0};
  int datacount{0};
  std::shared_ptr<Node> next{nullptr};

public:
  Node() = default;

  Node(int value, std::shared_ptr<Node> tail = nullptr)
      : datavalue(value), datacount(1), next(tail) {}

  int value() const { return datavalue; }
  int count() const { return datacount; }

  bool has_next() const {
    return next != nullptr;
  }

  std::shared_ptr<Node> nextnode() const {
    return next;
  }

  bool contains_value(int val) const {
    if (val == datavalue)
      return true;

    if (val < datavalue || next == nullptr)
      return false;

    return next->contains_value(val);
  }

  int length() const {
    if (next == nullptr)
      return 1;

    return 1 + next->length();
  }

  // List handles values smaller than the head.
  void insert(int val) {
    if (val < datavalue)
      throw std::invalid_argument("Use List::insert");

    if (val == datavalue) {
      // Duplicate: increase this node's count.
      ++datacount;
    } else if (next == nullptr || val < next->value()) {
      // Insert at the tail or between nodes.
      next = std::make_shared<Node>(val, next);
    } else {
      next->insert(val);
    }
  }

  void print() const {
    std::cout << datavalue << ':' << datacount;

    if (next != nullptr) {
      std::cout << ' ';
      next->print();
    }
  }
};

class List {
private:
  std::shared_ptr<Node> head{nullptr};

public:
  List() = default;

  bool empty() const {
    return head == nullptr;
  }

  Node headnode() const {
    if (empty())
      throw std::out_of_range("Empty list has no head");

    return *head;
  }

  void insert(int value) {
    if (empty() || value < head->value()) {
      // Create the first node or a new smallest node.
      head = std::make_shared<Node>(value, head);
    } else {
      head->insert(value);
    }
  }

  bool contains_value(int val) const {
    return !empty() && head->contains_value(val);
  }

  // Length counts distinct values.
  int length() const {
    return empty() ? 0 : head->length();
  }

  int length_iterative() const {
    int count = 0;

    for (auto node = head; node != nullptr;
         node = node->nextnode())
      ++count;

    return count;
  }

  void print() const {
    if (!empty())
      head->print();

    std::cout << '\n';
  }
};

#endif
