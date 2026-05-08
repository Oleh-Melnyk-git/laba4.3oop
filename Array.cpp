#include "Array.h"
#include <cstring>

// ===== Array =====
Array::Array(int n, unsigned char val) {
  size = (n <= 256) ? n : 256;
  for (int i = 0; i < size; i++)
    data[i] = val;
}

unsigned char &Array::operator[](int index) {
  rangeCheck(index);
  return data[index];
}

void Array::rangeCheck(int index) {
  if (index < 0 || index >= size) {
    std::cerr << "Error: index out of range!\n";
    exit(1);
  }
}

// ===== BitString =====
BitString::BitString(int n) : Array(n, 0) {
  if (n > 100)
    size = 100;
}

void BitString::add(const Array &other) {
  for (int i = 0; i < size; i++) {
    data[i] = (data[i] + other.data[i]) % 2;
  }
}

void BitString::print() const {
  std::cout << "BitString: ";
  for (int i = 0; i < size; i++)
    std::cout << (int)data[i];
  std::cout << "\n";
}

void BitString::bitAnd(const BitString &other) {
  for (int i = 0; i < size; i++)
    data[i] &= other.data[i];
}

void BitString::bitOr(const BitString &other) {
  for (int i = 0; i < size; i++)
    data[i] |= other.data[i];
}

void BitString::bitXor(const BitString &other) {
  for (int i = 0; i < size; i++)
    data[i] ^= other.data[i];
}

void BitString::bitNot() {
  for (int i = 0; i < size; i++)
    data[i] = !data[i];
}

void BitString::shiftLeft(int k) {
  for (int i = size - 1; i >= k; i--)
    data[i] = data[i - k];
  for (int i = 0; i < k; i++)
    data[i] = 0;
}

void BitString::shiftRight(int k) {
  for (int i = 0; i < size - k; i++)
    data[i] = data[i + k];
  for (int i = size - k; i < size; i++)
    data[i] = 0;
}

// ===== String =====
String::String(const std::string &str, int maxLen) {
  if (maxLen > 255)
    maxLen = 255;
  size = (str.size() <= maxLen) ? str.size() + 1 : maxLen + 1;
  data[0] = size - 1; // length in byte 0
  for (int i = 1; i < size; i++)
    data[i] = str[i - 1];
}

void String::add(const Array &other) {
  int curLen = (int)data[0];
  int otherLen = (int)other.data[0];
  int canCopy = (curLen + otherLen <= 255) ? otherLen : (255 - curLen);
  for (int i = 0; i < canCopy; i++)
    data[curLen + i + 1] = other.data[i + 1];
  data[0] = (unsigned char)(curLen + canCopy);
  size = data[0] + 1;
}

void String::print() const {
  std::cout << "String: ";
  for (int i = 1; i <= data[0]; i++)
    std::cout << data[i];
  std::cout << "\n";
}

int String::length() const { return data[0]; }

int String::find(const std::string &substr) const {
  std::string s((char *)data + 1, data[0]);
  return s.find(substr);
}

void String::insert(int pos, const std::string &substr) {
  std::string s((char *)data + 1, data[0]);
  s.insert(pos, substr);
  size = (s.size() + 1 <= 256) ? s.size() + 1 : 256;
  data[0] = size - 1;
  for (int i = 1; i < size; i++)
    data[i] = s[i - 1];
}

void String::erase(int pos, int len) {
  std::string s((char *)data + 1, data[0]);
  s.erase(pos, len);
  size = s.size() + 1;
  data[0] = size - 1;
  for (int i = 1; i < size; i++)
    data[i] = s[i - 1];
}

void String::concat(const String &other) {
  std::string s((char *)data + 1, data[0]);
  s += std::string((char *)other.data + 1, other.data[0]);
  size = (s.size() + 1 <= 256) ? s.size() + 1 : 256;
  data[0] = size - 1;
  for (int i = 1; i < size; i++)
    data[i] = s[i - 1];
}
