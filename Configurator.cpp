#include "Configurator.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include "Constants.h"
#include "Helpers.h"

Configurator::Configurator(){
  this->setPublicKeyPath(Constants::KEY_PATH + Constants::PUB_KEY_FNAME);
  this->setPrivateKeyPath(Constants::KEY_PATH + Constants::PRV_KEY_FNAME);
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

void Configurator::setPrivateKeyPath(const std::string path){
  this->privateKeyPath = path;
}

void Configurator::setMode(const Modes mode){
  this->mode = mode;
}

const std::string Configurator::getInputPath(){
  return this->inputPath;
}

const std::string Configurator::getOutputPath(){
  if (this->outputPath.empty()) {
		if( this->mode == Modes::ENCRYPT) {
			// ./out/encrypted-file.name
			return Constants::OUT_PATH + Constants::ENCRYPT_PREFIX + '-' + Helpers::pullFileName(this->inputPath);
		} else if( this->mode == Modes::DECRYPT) {
			// ./out/decrypted-file.name
			return Constants::OUT_PATH + Constants::DECRYPT_PREFIX + '-' + Helpers::pullFileName(this->inputPath);
		}
	}
	// user/path/to/file.out
	return this->outputPath;
}

const std::string Configurator::getPublicKeyPath(){
  return this->publicKeyPath;
}

const std::string Configurator::getPrivateKeyPath(){
  return this->privateKeyPath;
}

const Modes Configurator::getMode(){
  return this->mode;
}

void Configurator::doWork(){
  switch(this->mode){
    case ENCRYPT: {
      if( this->checkEncrypt() ) {
      	CryptoKey publicKey;
        if (!publicKey.loadFromFile(this->getPublicKeyPath())){
          fileError(this->getPublicKeyPath());
				}
        std::cout << "Идет процесс шифрования файла \"" + this->getInputPath() + "\"..." << std::endl;
         Encryptor::encryptTxtFile(this->getInputPath(), this->getOutputPath(), publicKey);
        // Encryptor::encryptBinFile(this->getInputPath(), this->getOutputPath(), publicKey);
        std::cout << "Зашифрованный файл успешно сохранен в \"" + this->getOutputPath() + "\"." << std::endl;
      } else {
        Configurator::argumentError(Constants::ENCRYPT_MODE_NAMEF);
      }
    }; break;
    case DECRYPT: {
      if( this->checkDecrypt() ) {
        CryptoKey privateKey;
        if (!privateKey.loadFromFile(this->getPrivateKeyPath())) {
            fileError(this->getPrivateKeyPath());
				}
        std::cout << "Идет процесс дешифрования файла \"" + this->getInputPath() + "\"..." << std::endl;
         Decryptor::decryptTxtFile(this->getInputPath(), this->getOutputPath(), privateKey);
       // Decryptor::decryptBinFile(this->getInputPath(), this->getOutputPath(), privateKey);
        std::cout << "Дешифрованный файл успешно сохранен в \"" + this->getOutputPath() + "\"." << std::endl;
      } else {
        Configurator::argumentError(Constants::DECRYPT_MODE_NAMEF);
      }
    }; break;
    case GENERATE: {
      if( this->checkGenerate() ) {
          CryptoKey publicKey, privateKey;
        	std::cout << "Идет процесс генерации ключей..." << std::endl;
          Engine::genKeys(publicKey, privateKey);
          publicKey.saveToFile(this->publicKeyPath);
          privateKey.saveToFile(this->privateKeyPath);
        	std::cout << "Публичный ключ успешно сохранен в \""<< this->publicKeyPath <<"\"." << std::endl;
        	std::cout << "Приватный ключ успешно сохранен в \""<< this->privateKeyPath <<"\"." << std::endl;
			} else {
        Configurator::argumentError(Constants::GENERATE_KEY_MODE_NAMEF);
      }
    }; break;

  }
}

void Configurator::argumentError(const std::string modeNamef){
  throw std::invalid_argument("Не указан корректный набор аргументов для опции \""+modeNamef+"\".");
}

void Configurator::fileError(const std::string file){
	throw std::runtime_error("Расположение \"" + file + "\" не найдено.");
}

bool Configurator::checkEncrypt(){
  return this->mode == Modes::ENCRYPT &&
    !this->getInputPath().empty() &&
    !this->getOutputPath().empty() &&
    !this->getPublicKeyPath().empty();
}

bool Configurator::checkDecrypt(){
 std::cerr << this->inputPath <<std::endl;
 return this->mode == Modes::DECRYPT &&
    !this->getInputPath().empty() &&
    !this->getOutputPath().empty() &&
    !this->getPrivateKeyPath().empty();
}
bool Configurator::checkGenerate(){
  return this->mode == Modes::GENERATE &&
    !this->getPublicKeyPath().empty() &&
    !this->getPrivateKeyPath().empty();
}
