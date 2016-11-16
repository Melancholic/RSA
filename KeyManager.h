#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#include <fstream>
#include <string>
#include "BigInteger.h"


class KeyManager {
  BigInteger a;
  BigInteger b;

public: 
  KeyManager(const BigInteger& a, const BigInteger& b);
	bool loadFromFile(const std::string&);
	bool saveToFile(const std::string&);

};

#endif
