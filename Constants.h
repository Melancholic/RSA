#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include <string>
#include <iostream>

namespace Constants {
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
  const std::string PUBLIC_KEY_NAMEF = "--public-key";
  const std::string PRIVATE_KEY_NAMEF = "--private-key";
  const std::string GENERATE_KEY_MODE_NAMEF = "--generate-key";
  const std::string GENERATE_KEY_MODE_NAMES = "-g";
  
	const unsigned int HELP_CODE = 100;
  const unsigned int IN_FILE_CODE = 101;
  const unsigned int OUT_FILE_CODE = 102;
  const unsigned int ENCRYPT_MODE_CODE = 103;
  const unsigned int DECRYPT_MODE_CODE = 104;
  const unsigned int GENERATE_KEY_MODE_CODE =105;
  const unsigned int PUBLIC_KEY_CODE = 106;
  const unsigned int PRIVATE_KEY_CODE = 107;
 	
	/**
 	* Константы, определяющие расположение сущностей
 	**/
  const std::string OUT_PATH = "./out/";           
  const std::string KEY_PATH = "./.keys/";           
  const std::string PUB_KEY_FNAME = "key.pub";      
  const std::string PRV_KEY_FNAME = "key"; 
  
	const std::string ENCRYPT_PREFIX = "encrypted"; 
  const std::string DECRYPT_PREFIX = "decrypted"; 
	
	const unsigned KEY_LENGTH = 80;
 
	extern std::map<std::string, int> ARGUMENTS;  
};
#endif 
