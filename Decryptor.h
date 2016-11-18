#ifndef DECRYPTOR_H
#define DECRYPTOR_H

#include <fstream>
#include "BigInteger.h"
#include "CryptoKey.h"
#include "Engine.h"

class Decryptor {
  std::string static decrypt(const BigInteger&, const std::vector<char>& , const BigInteger& );
public:
  void static decryptTxtFile(const std::string&, const std::string&, CryptoKey& );
  void static decryptBinFile(const std::string&, const std::string&, CryptoKey& );
};

#endif
