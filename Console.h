#ifndef CONSOLE_H
#define CONSOLE_H

#include<map>
#include<string>
#include<iostream>

#define HELP_NAMEF "--help"
#define HELP_NAMES "-h"
#define IN_FILE_NAMEF "--in"
#define IN_FILE_NAMES "-i"
#define OUT_FILE_NAMEF "--out"
#define OUT_FILE_NAMES "-o"
#define ENCRYPT_MODE_NAMEF "--encrypt"
#define ENCRYPT_MODE_NAMES "-e"
#define DECRYPT_MODE_NAMEF "--decrypt"
#define DECRYPT_MODE_NAMES "-d"
#define PUBLIC_KEY_NAMEF "--key"
#define PUBLIC_KEY_NAMES "-k"
#define GENERATE_KEY_MODE_NAMEF "--generate-key"
#define GENERATE_KEY_MODE_NAMES "-g"




namespace Console {
 
  const unsigned int HELP_CODE = 100;
  const unsigned int IN_FILE_CODE = 101;
  const unsigned int OUT_FILE_CODE = 102;
  const unsigned int ENCRYPT_MODE_CODE = 103;
  const unsigned int DECRYPT_MODE_CODE = 104;
  const unsigned int GENERATE_KEY_MODE_CODE =105;
  const unsigned int PUBLIC_KEY_CODE = 106;
 
  std::map<std::string, int> ARGUMENTS = {
    {IN_FILE_NAMEF, IN_FILE_CODE},  
    {IN_FILE_NAMES, IN_FILE_CODE},  
    {OUT_FILE_NAMEF, OUT_FILE_CODE},  
    {OUT_FILE_NAMES, OUT_FILE_CODE},  
    {ENCRYPT_MODE_NAMEF, ENCRYPT_MODE_CODE},  
    {ENCRYPT_MODE_NAMES, ENCRYPT_MODE_CODE},  
    {DECRYPT_MODE_NAMEF, DECRYPT_MODE_CODE},  
    {DECRYPT_MODE_NAMES, DECRYPT_MODE_CODE},  
    {GENERATE_KEY_MODE_NAMEF, GENERATE_KEY_MODE_CODE},  
    {GENERATE_KEY_MODE_NAMES, GENERATE_KEY_MODE_CODE},  
    {PUBLIC_KEY_NAMEF, PUBLIC_KEY_CODE},  
    {PUBLIC_KEY_NAMES, PUBLIC_KEY_CODE},  
    {HELP_NAMEF, HELP_CODE},  
    {HELP_NAMES, HELP_CODE}  
  };

  void printHelp(std::ostream& ostream){
    ostream << std::endl;
    ostream << "fileEncryptor - простой шифратор файлов, поддерживающий дешифрование и генерацию ключей. Использует алгоритм RSA. " << std::endl;
    ostream <<  "Необходимые аргументы:" << std::endl;
    ostream << "Обязательный" <<"\t" << "Аргумент" << "\t" << "Значение" << "\t" << "Описание" << std::endl;
    ostream << " "   <<"\t" << ENCRYPT_MODE_NAMEF  << " | " << ENCRYPT_MODE_NAMES << "\t" << " - " << "\t" << "Режим шифратора. Если не указан, по умолчанию используется режим шифратора." << std::endl;
    ostream << " "   <<"\t" << DECRYPT_MODE_NAMEF  << " | " << DECRYPT_MODE_NAMES << "\t" << " - " << "\t" << "Режим дешифратора. Если не указан, по умолчанию используется режим шифратора." << std::endl;
    ostream << " "   <<"\t" << GENERATE_KEY_MODE_NAMEF  << " | " << GENERATE_KEY_MODE_NAMES << "\t" << " - " << "\t" << "Режим генератора ключей. Если не указан, по умолчанию используется режим шифратора." << std::endl;
    ostream << "*" <<"\t" << IN_FILE_NAMEF << " | " << IN_FILE_NAMES << "\t" << "/path/to/file" << "\t" << "Путь к шифруемому файлу." << std::endl;
    ostream << "*" <<"\t" << PUBLIC_KEY_NAMEF << " | " << PUBLIC_KEY_NAMES << "\t" << "/path/to/public.key" << "\t" << "Путь к публичному ключу." << std::endl;
    ostream << " " <<"\t" << OUT_FILE_NAMEF << " | " << OUT_FILE_NAMES << "\t" << "/path/to/" << "\t" << "Путь, в котором будет расположен зашифрованный файл. Если путь не указан, выходной файл будет расположен в текущем каталоге." << std::endl;
    ostream << " " <<"\t" << HELP_NAMEF << " | " << HELP_NAMES << "\t" << " - " << "\t" << "Распечать эту справку. Другие аргументы  игнорируются." << std::endl;
  }
};
#endif
