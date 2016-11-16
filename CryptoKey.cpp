#include "CryptoKey.h" 

bool CryptoKey::loadFromFile(const std::string& filename) {
  BigInteger temp(800);
  std::ifstream in (filename);
  if (in.good()) {  
    in >> temp;
    a = temp;
    in >> temp;
    b = temp;
    in.close();
    return true;
  }
  return false;
}

bool CryptoKey::saveToFile(const std::string&  filename) {
	std::ofstream out (filename);
  if (out.good()) {
    out << a << std::endl;
    out << b << std::endl;
    out.close();
    return true;
  }
  return false;
}
