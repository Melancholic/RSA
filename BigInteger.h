#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <ostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

class BigInteger {
          
  short *numbers;
  unsigned  int currentSize;
  unsigned int maxSize;
  // Флаг, указывайющий является ли число положительным
  bool positive;
  void reflect();
  // Удаление незначащих нулей ( 001110 -> 1110)
  void removeSpace();
  // Сравнение абсолютных  значений (true если obj >  *this)
  bool isAbsBigger(const BigInteger &obj);
  BigInteger divMod(const BigInteger &obj, BigInteger &reminder);
public:
  BigInteger();
  BigInteger(unsigned int n);
  ~BigInteger();
  BigInteger(const BigInteger &obj);
  //add obj to the current value as string
  void concat(const BigInteger &obj);
  std::vector <char> toBinary();
  // Текущая длина числа
  int size();
  // Возведение в степень
  BigInteger pow(const unsigned int power);
  //returns A^d(mod m) 
  //A = *this
  BigInteger calcPowMod(const std::vector <char> &d, const BigInteger m);
  void random(unsigned int length);
  // Тест на четность
  bool isEven();
  // Тест М. Робина на простоту
  bool isPrime();
  BigInteger getMaxDiviser(BigInteger b);
  BigInteger abs();
  BigInteger operator=(const BigInteger &obj);
  BigInteger operator=(const int b);
  BigInteger operator+(const BigInteger &obj);
  BigInteger operator+(const int b);
  BigInteger operator*(const BigInteger &obj);
  BigInteger operator*(const int b);
  BigInteger operator-(const BigInteger &obj);
  BigInteger operator-(const int b);
  BigInteger operator%(const BigInteger &obj);
  BigInteger operator%(const int b);
  BigInteger operator/(const BigInteger &obj);
  BigInteger operator/(const int b);
  BigInteger operator+=(const BigInteger &obj);
  BigInteger operator+=(const int b);
  BigInteger operator-=(const BigInteger &obj);
  BigInteger operator-=(const int b);
  bool operator>(const BigInteger &obj);
  bool operator>(const int b);
  bool operator<(const BigInteger &obj);
  bool operator<(const int b);
  bool operator==(const BigInteger &obj);
  bool operator==(const int b);
  bool operator!=(const BigInteger &obj);
  bool operator!=(const int b);
  bool operator>=(const BigInteger &obj);
  bool operator>=(const int b);
  bool operator<=(const BigInteger &obj);
  bool operator<=(const int b);
  friend BigInteger operator-(const BigInteger &obj);
  friend BigInteger operator+(const int a, const BigInteger &b);
  friend BigInteger operator-(const int a, const BigInteger &b);
  friend BigInteger operator*(const int a, const BigInteger &b);
  friend BigInteger operator/(const int a, const BigInteger &b);
  friend BigInteger operator%(const int a, const BigInteger &b);
  friend bool operator>(const int a, const BigInteger &b);
  friend bool operator<(const int a, const BigInteger &b);
  friend bool operator==(const int a, const BigInteger &b);
  friend bool operator!=(const int a, const BigInteger &b);
  friend bool operator>=(const int a, const BigInteger &b);
  friend bool operator<=(const int a, const BigInteger &b);
  friend std::ostream& operator<<(std::ostream &out, const BigInteger &obj);
  friend std::istream& operator>>(std::istream &in, BigInteger &obj);
};

#endif
