#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>
#include "Encryptor.h"
#include "Decryptor.h"
#include "Engine.h"
#include "BigInteger.h"

enum Modes {ENCRYPT, DECRYPT, GENERATE};
/**
 * Синглтон
**/ 
class Configurator {
  std::string inputPath;
  std::string outputPath;
  std::string publicKeyPath;
  std::string privateKeyPath;
  Modes mode = Modes::ENCRYPT;
  Configurator();
  ~Configurator();
  Configurator(Configurator const&) = delete; 
  Configurator& operator= (Configurator const&) = delete;
  static void argumentError(const std::string);
  static void fileError(const std::string);
  bool checkEncrypt();
  bool checkDecrypt();
  bool checkGenerate();
  public:
  static Configurator& getInstance();
  void setInputPath(const std::string);
  void setOutputPath(const std::string);
  void setPublicKeyPath(const std::string);
  void setPrivateKeyPath(const std::string);
  void setMode(Modes);
  const std::string getInputPath();
  const std::string getOutputPath();
  const std::string getPublicKeyPath();
  const std::string getPrivateKeyPath();
  const Modes getMode();
  void doWork();
};
#endif
