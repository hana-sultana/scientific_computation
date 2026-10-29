#include <iostream>
#include <print>
#include <vector>
#include <stdexcept>
using std::vector, std::println, std::print;

class TriangleStorage {
private:
  int rows;
  vector<long> data;
  static size_t index(int r, int c) {
    return static_cast<size_t>(r - 1) * r / 2 + (c - 1);
  }
  void check(int r, int c) const {
    if (r < 1 || c < 1 || c > r)
      throw std::out_of_range("bad triangle index");
  }
  void extend(int r) {
    if (r > rows) {
      rows = r;
      data.resize(static_cast<size_t>(r) * (r + 1) / 2, 0);
    }
  }
public:
  TriangleStorage() : rows(1), data(1, 0) {}
  TriangleStorage(int n) : rows(n), data(static_cast<size_t>(n) * (n + 1) / 2, 0) {}

  int nrows() const { return rows; }

  long get(int r, int c) const {
    check(r, c);
    return data.at(index(r, c));
  }
  void set(int r, int c, long v) {
    check(r, c);
    extend(r);
    data.at(index(r, c)) = v;
  }
  long& operator[](int r, int c) {
    check(r, c);
    extend(r);
    return data.at(index(r, c));
  }
  long operator[](int r, int c) const { return get(r, c); }
};

class Pascal {
private:
  TriangleStorage tri;
public:
  Pascal(int n) : tri(n) {
    for (int r = 1; r <= n; ++r)
      for (int c = 1; c <= r; ++c)
        if (c == 1 || c == r)
          tri[r, c] = 1;
        else
          tri[r, c] = tri[r - 1, c - 1] + tri[r - 1, c];
  }
  int nrows() const { return tri.nrows(); }
  long getvalue(int i, int j) const { return tri.get(i, j); }
  long operator[](int i, int j) const { return tri[i, j]; }

  void print() const {
    int n = nrows();
    for (int r = 1; r <= n; ++r) {
      std::print("Row {:3}: {}", r, std::string(2 * (n - r), ' '));
      for (int c = 1; c <= r; ++c)
        std::print("{:4}", tri[r, c]);
      println();
    }
  }
  void print(int m) const {
    int n = nrows();
    for (int r = 1; r <= n; ++r) {
      std::print("{}", std::string(n - r, ' '));
      for (int c = 1; c <= r; ++c)
        std::print("{} ", (tri[r, c] % m != 0) ? '*' : ' ');
      println();
    }
  }
};

void test_storage() {
  {
    TriangleStorage tri(11);
    println("Initially {} rows", tri.nrows());
    tri.set(5, 3, 7);
    tri.set(6, 2, tri.get(5, 3));
    println("s/b 7: {}", tri.get(6, 2));
  }
  {
    TriangleStorage tri;
    println("Initially {} rows", tri.nrows());
    tri[5, 3] = 11;
    println("Then {} rows", tri.nrows());
    tri[6, 2] = tri[5, 3];
    println("s/b 11: {}", tri[6, 2]);
  }
}

int main() {
  test_storage();

  int n;
  std::cout << "Number of rows: ";
  std::cin >> n;
  Pascal pascal(n);
  pascal.print();

  int m;
  while (true) {
    std::cout << "Modulus (0 to stop): ";
    if (!(std::cin >> m) || m == 0) break;
    pascal.print(m);
  }
  return 0;
}
