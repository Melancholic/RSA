#include "Configurator.h"
#include <iostream>


Configurator::Configurator(){

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
