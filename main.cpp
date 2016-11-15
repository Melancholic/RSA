#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include "Console.h"
#include "Configurator.h"
#include "BigInteger.h"

int main(int argc, char** argv){
  std::vector<std::string> arguments (argv + 1, argv + argc);
  Configurator& configurator = Configurator::getInstance();
  try {
    if (argc == 1 ){
      throw std::invalid_argument("Не указаны обязательные аргументы");
    } else {
      for(int i = 0; i < arguments.size(); ++i){
        std::string curArg = arguments.at(i);
        switch(Console::ARGUMENTS[curArg]){
          case Console::HELP_CODE: {
            Console::printHelp(std::cout);
          } break;
          case Console::IN_FILE_CODE: {
            configurator.setInputPath(arguments.at(++i));
          } break;
          case Console::OUT_FILE_CODE: {
            configurator.setOutputPath(arguments.at(++i));
          } break;
          case Console::ENCRYPT_MODE_CODE: {
            configurator.setMode(Modes::ENCRYPT);
          } break;
          case Console::DECRYPT_MODE_CODE: {
            configurator.setMode(Modes::DECRYPT);
          } break;
          case Console::GENERATE_KEY_MODE_CODE: {
            configurator.setMode(Modes::GENERATE);
          } break;
          case Console::PUBLIC_KEY_CODE: {
            configurator.setPublicKeyPath(arguments.at(++i));
          } break;
          default: {
            std::cout<< "Указан неизвестный аргумент \""<< curArg << "\"" << std::endl;
            Console::printHelp(std::cout);
            return 1;
          }
        }
      }
    }
  } catch (const std::out_of_range& e) {
    std::cout << "Неправильно передан набор аргументов" << std::endl;
    Console::printHelp(std::cout);
    return 1;
  } catch (const std::exception& e) {
    std::cout<< e.what()<<std::endl;
    Console::printHelp(std::cout);
    return 1;
  }

  try {
    configurator.doWork();
  } catch (const std::invalid_argument& e){
    std::cout<< e.what()<<std::endl;
    Console::printHelp(std::cout);
    
  }catch (const std::exception& e) {
    std::cout<< e.what()<<std::endl;
    return 1;
  } 


  return 0;
}

