#include "KeyManager.h" 
KeyManager::KeyManager(const BigInteger& first, const BigInteger& second): a(first), b(second){}

bool KeyManager::loadFromFile(const std::string& filename) {
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

bool KeyManager::saveToFile(const std::string&  filename) {
  std::ofstream out (filename);
  if (out.good()) {
    out << a << std::endl;
    out << b << std::endl;
    out.close();
    return true;
  }
  return false;
}
