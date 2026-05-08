#include "Array.h"

int main() {
  // ===== BitString demo =====
  BitString b1(5), b2(5);
  b1[0] = 1;
  b1[1] = 0;
  b1[2] = 1;
  b1[3] = 1;
  b1[4] = 0;
  b2[0] = 1;
  b2[1] = 1;
  b2[2] = 0;
  b2[3] = 0;
  b2[4] = 1;

  Array *arr1 = &b1;
  Array *arr2 = &b2;

  std::cout << "=== BitString operations ===\n";
  b1.print();
  b2.print();

  arr1->add(*arr2);
  std::cout << "Addition result: ";
  b1.print();

  b1.bitNot();
  std::cout << "After NOT: ";
  b1.print();

  b1.shiftLeft(2);
  std::cout << "After shift left: ";
  b1.print();

  b1.shiftRight(2);
  std::cout << "After shift right: ";
  b1.print();

  // ===== String demo =====
  String s1("Hello");
  String s2("World");

  Array *arr3 = &s1;
  Array *arr4 = &s2;

  std::cout << "\n=== String operations ===\n";
  s1.print();
  s2.print();

  arr3->add(*arr4);
  std::cout << "Addition result: ";
  s1.print();

  std::cout << "Length of s1: " << s1.length() << "\n";
  std::cout << "Find 'lo': " << s1.find("lo") << "\n";

  s1.insert(2, "INSERT");
  std::cout << "After insert: ";
  s1.print();

  s1.erase(2, 6);
  std::cout << "After erase: ";
  s1.print();

  s1.concat(s2);
  std::cout << "After concatenation: ";
  s1.print();

  return 0;
}
