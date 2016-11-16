#ifndef ENGINE_H
#define ENGINE_H

#include <fstream>
#include <stdexcept>
#include "CryptoKey.h"
#include "BigInteger.h"

class Engine {
	void static extEuclid (BigInteger&, BigInteger&, BigInteger& );
public:
	const static unsigned KEY_LENGTH = 80;
  void static genKeys(CryptoKey&, CryptoKey& );
};

#endif
