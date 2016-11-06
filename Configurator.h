#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>

enum Modes {ENCRYPT, DECRYPT, GENERATE};
/**
 * Синглтон
**/ 
class Configurator {
  std::string inputPath;
  std::string outputPath;
  std::string publicKeyPath;
  Modes mode = Modes::ENCRYPT;
  Configurator();
  ~Configurator();
  Configurator(Configurator const&) = delete; 
  Configurator& operator= (Configurator const&) = delete;
  public:
  static Configurator& getInstance();
  void setInputPath(const std::string);
  void setOutputPath(const std::string);
  void setPublicKeyPath(const std::string);
  void setMode(Modes);
  const std::string getInputPath();
  const std::string getOutputPath();
  const std::string getPublicKeyPath();
  const Modes getMode();
};
#endif
