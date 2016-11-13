#include "Configurator.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include "Console.h"
#include "File.h"

Configurator::Configurator(){
  this->setPublicKeyPath(File::KEY_PATH + File::PUB_KEY_FNAME);
  this->setOutputPath(File::OUT_PATH);
}

Configurator& Configurator::getInstance(){
  static Configurator configurator;
  return configurator;
}

Configurator::~Configurator(){

}

void Configurator::setInputPath(const std::string path){
  this->inputPath = path;
}

void Configurator::setOutputPath(const std::string path){
  this->outputPath = path;
}

void Configurator::setPublicKeyPath(const std::string path){
  this->publicKeyPath = path;
}

void Configurator::setMode(const Modes mode){
  this->mode = mode;
}

const std::string Configurator::getInputPath(){
  return this->inputPath;
}

const std::string Configurator::getOutputPath(){
  return this->outputPath;
}

const std::string Configurator::getPublicKeyPath(){
  return this->publicKeyPath;
}

const Modes Configurator::getMode(){
  return this->mode;
}

void Configurator::doWork(){
  switch(this->mode){
    case ENCRYPT: {
      if( this->checkEncrypt() ) {
        //do Encrypt
      } else {
        Configurator::throwArgumentsNotCorrectMsg(Console::ENCRYPT_MODE_NAMEF);
      }
    }; break;
    case DECRYPT: {
      if( this->checkDecrypt() ) {
        // do Decrypt
      } else {
        Configurator::throwArgumentsNotCorrectMsg(Console::DECRYPT_MODE_NAMEF);
      }
    }; break;
    case GENERATE: {
      if( this->checkGenerate() ) {
        // do Generate
      } else {
        Configurator::throwArgumentsNotCorrectMsg(Console::GENERATE_KEY_MODE_NAMEF);
      }
    }; break;

  }
}

void Configurator::throwArgumentsNotCorrectMsg(const std::string modeNamef){
  throw std::invalid_argument("Не указан корректный набор аргументов для опции \""+modeNamef+"\".");
}

bool Configurator::checkEncrypt(){
  return this->mode == Modes::ENCRYPT &&
    !this->inputPath.empty() &&
    !this->outputPath.empty() &&
    !this->publicKeyPath.empty();
}

bool Configurator::checkDecrypt(){
  return false;
}
bool Configurator::checkGenerate(){
  return false;
}
