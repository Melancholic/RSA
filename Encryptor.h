#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <fstream>
#include <stdexcept>
#include <sstream>
#include "BigInteger.h"
#include "CryptoKey.h"
#include "Engine.h"

class Encryptor {
  BigInteger static encrypt(const std::string& , const std::vector<char>& , const BigInteger&);
public:
  void static encryptTxtFile(const std::string&, const std::string&, CryptoKey& );
  void static encryptBinFile(const std::string&, const std::string&, CryptoKey& );
};

#endif
