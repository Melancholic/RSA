#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#include <fstream>
#include <string>
#include "BigInteger.h"
#include <iostream>

struct CryptoKey {
  BigInteger a;
  BigInteger b;
  bool loadFromFile(const std::string&);
	bool saveToFile(const std::string&);

};

#endif
