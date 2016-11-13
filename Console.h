#ifndef CONSOLE_H
#define CONSOLE_H

#include <map>
#include <string>
#include <iostream>

namespace Console {
  const std::string HELP_NAMEF  = "--help";
  const std::string HELP_NAMES = "-h";
  const std::string IN_FILE_NAMEF = "--in";
  const std::string IN_FILE_NAMES = "-i";
  const std::string OUT_FILE_NAMEF = "--out";
  const std::string OUT_FILE_NAMES = "-o";
  const std::string ENCRYPT_MODE_NAMEF = "--encrypt";
  const std::string ENCRYPT_MODE_NAMES = "-e";
  const std::string DECRYPT_MODE_NAMEF = "--decrypt";
  const std::string DECRYPT_MODE_NAMES = "-d";
  const std::string PUBLIC_KEY_NAMEF = "--key";
  const std::string PUBLIC_KEY_NAMES = "-k";
  const std::string GENERATE_KEY_MODE_NAMEF = "--generate-key";
  const std::string GENERATE_KEY_MODE_NAMES = "-g";
  const unsigned int HELP_CODE = 100;
  const unsigned int IN_FILE_CODE = 101;
  const unsigned int OUT_FILE_CODE = 102;
  const unsigned int ENCRYPT_MODE_CODE = 103;
  const unsigned int DECRYPT_MODE_CODE = 104;
  const unsigned int GENERATE_KEY_MODE_CODE =105;
  const unsigned int PUBLIC_KEY_CODE = 106;
 
  extern std::map<std::string, int> ARGUMENTS;
  
  extern void printHelp(std::ostream&);
};
#endif 
