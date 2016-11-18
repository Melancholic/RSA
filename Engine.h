#ifndef ENGINE_H
#define ENGINE_H

#include <fstream>
#include <stdexcept>
#include "Constants.h"
#include "CryptoKey.h"
#include "BigInteger.h"

class Engine {
	void static extEuclid (BigInteger&, BigInteger&, BigInteger& );
public:
  void static genKeys(CryptoKey&, CryptoKey& );
};

#endif
