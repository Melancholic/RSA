#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include "Constants.h"
#include "Helpers.h"
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
        switch(Constants::ARGUMENTS[curArg]){
          case Constants::HELP_CODE: {
            Helpers::printHelp(std::cout);
						return 0;
          } break;
          case Constants::IN_FILE_CODE: {
            configurator.setInputPath(arguments.at(++i));
          } break;
          case Constants::OUT_FILE_CODE: {
            configurator.setOutputPath(arguments.at(++i));
          } break;
          case Constants::ENCRYPT_MODE_CODE: {
            configurator.setMode(Modes::ENCRYPT);
          } break;
          case Constants::DECRYPT_MODE_CODE: {
            configurator.setMode(Modes::DECRYPT);
          } break;
          case Constants::GENERATE_KEY_MODE_CODE: {
            configurator.setMode(Modes::GENERATE);
          } break;
          case Constants::PUBLIC_KEY_CODE: {
            configurator.setPublicKeyPath(arguments.at(++i));
          } break;
          case Constants::PRIVATE_KEY_CODE: {
            configurator.setPrivateKeyPath(arguments.at(++i));
          } break;
          default: {
            std::cout<< "Указан неизвестный аргумент \""<< curArg << "\"" << std::endl;
            Helpers::printHelp(std::cout);
            return 1;
          }
        }
      }
    }
  } catch (const std::out_of_range& e) {
    std::cout << "Неправильно передан набор аргументов" << std::endl;
    Helpers::printHelp(std::cout);
    return 1;
  } catch (const std::exception& e) {
    std::cout<< e.what()<<std::endl;
    Helpers::printHelp(std::cout);
    return 1;
  }

  try {
    configurator.doWork();
  } catch (const std::invalid_argument& e){
    std::cout<< e.what()<<std::endl;
    Helpers::printHelp(std::cout);
    
  }catch (const std::exception& e) {
    std::cout<< e.what()<<std::endl;
    return 1;
  } 


  return 0;
}

