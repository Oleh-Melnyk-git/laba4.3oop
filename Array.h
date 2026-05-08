#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>

class Array {
public:
  unsigned char data[256];
  int size;

public:
  Array(int n = 0, unsigned char val = 0);
  virtual ~Array() {}

  unsigned char &operator[](int index);
  void rangeCheck(int index);

  virtual void add(const Array &other) = 0;
  virtual void print() const = 0;
};

// ===== BitString =====
class BitString : public Array {
public:
  BitString(int n = 0);
  void add(const Array &other) override;
  void print() const override;

  void bitAnd(const BitString &other);
  void bitOr(const BitString &other);
  void bitXor(const BitString &other);
  void bitNot();
  void shiftLeft(int k);
  void shiftRight(int k);
};

// ===== String =====
class String : public Array {
public:
  String(const std::string &str = "", int maxLen = 255);
  void add(const Array &other) override;
  void print() const override;

  int length() const;
  int find(const std::string &substr) const;
  void insert(int pos, const std::string &substr);
  void erase(int pos, int len);
  void concat(const String &other);
};

#endif
