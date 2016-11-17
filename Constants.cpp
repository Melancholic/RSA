#include "Constants.h"

std::map<std::string, int> Constants::ARGUMENTS = {
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
    {PRIVATE_KEY_NAMEF, PRIVATE_KEY_CODE},  
    {HELP_NAMEF, HELP_CODE},  
    {HELP_NAMES, HELP_CODE}  
};

void Constants::printHelp(std::ostream& ostream){
    ostream << std::endl;
    ostream << "fileEncryptor - простой шифратор файлов, поддерживающий дешифрование и генерацию ключей. Использует алгоритм RSA. " << std::endl;
    ostream <<  "Необходимые аргументы:" << std::endl;
    ostream << "Обязательный" <<"\t" << "Аргумент" << "\t" << "Значение" << "\t" << "Описание" << std::endl;
    ostream << " "   <<"\t" << ENCRYPT_MODE_NAMEF  << " | " << ENCRYPT_MODE_NAMES << "\t" << " - " << "\t" << "Режим шифратора. Если не указан, по умолчанию используется режим шифратора." << std::endl;
    ostream << " "   <<"\t" << DECRYPT_MODE_NAMEF  << " | " << DECRYPT_MODE_NAMES << "\t" << " - " << "\t" << "Режим дешифратора. Если не указан, по умолчанию используется режим шифратора." << std::endl;
    ostream << " "   <<"\t" << GENERATE_KEY_MODE_NAMEF  << " | " << GENERATE_KEY_MODE_NAMES << "\t" << " - " << "\t" << "Режим генератора ключей. Если не указан, по умолчанию используется режим шифратора." << std::endl;
    ostream << "*" <<"\t" << IN_FILE_NAMEF << " | " << IN_FILE_NAMES << "\t" << "/path/to/file" << "\t" << "Путь к шифруемому файлу." << std::endl;
    ostream << "*" <<"\t" << PUBLIC_KEY_NAMEF << "\t" << "/path/to/public.key" << "\t" << "Путь к публичному ключу." << std::endl;
    ostream << "*" <<"\t" << PRIVATE_KEY_NAMEF << "\t" << "/path/to/private.key" << "\t" << "Путь к приватному ключу." << std::endl;
    ostream << " " <<"\t" << OUT_FILE_NAMEF << " | " << OUT_FILE_NAMES << "\t" << "/path/to/" << "\t" << "Путь, в котором будет расположен зашифрованный файл. Если путь не указан, выходной файл будет расположен в текущем каталоге." << std::endl;
    ostream << " " <<"\t" << HELP_NAMEF << " | " << HELP_NAMES << "\t" << " - " << "\t" << "Распечать эту справку. Другие аргументы  игнорируются." << std::endl;
  }
