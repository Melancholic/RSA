#include "Encryptor.h"

BigInteger Encryptor::encrypt(const std::string &data, const std::vector<char>  &a, const BigInteger &b) {
  BigInteger block;
  block = 1;
  
  if (data.length() > (Constants::KEY_LENGTH-4)/3) {
    throw std::logic_error("Размер прочитанного файла превышает допустимый размер.");
	}

  for (unsigned int i = 0; i < data.length(); ++i) {
    BigInteger buff;
    buff = int(data[i]);

    if (buff < 0) buff = 256+buff; // UNICODE

    block = block * int( pow(10.0, 3 - buff.size()) );
    block.concat(buff);
  }
  
	return block.calcPowMod(a, b);
}



void Encryptor::encryptTxtFile(const std::string& in, const std::string& out, CryptoKey &key) {
  std::string buff;
  std::vector <char> a = key.a.toBinary();

  std::ifstream input (in);
  if (!input.good()) {
    throw std::logic_error("Невозможно открыть файл \""+in+"\" для чтения.");
  }

  std::ofstream output (out);
  if (!output.good()) {
    throw std::logic_error("Невозможно записать файл \""+out+"\".");
  }

  while (!input.eof()) {
    buff.clear();

    for (int i = 0; i < (Constants::KEY_LENGTH-4)/3; ++i) {
      char bf = input.get();
      if (input.eof()) break;
      buff += bf;
    }


    if (!buff.empty()) {
      output <<  encrypt(buff, a, key.b) << " ";
		}
  }

  input.close();
  output.close();
}

// TODO
void Encryptor::encryptBinFile(const std::string& in, const std::string& out, CryptoKey &key) {
//	char* buffer;
//  const unsigned BLOCK_SIZE = (Constants::KEY_LENGTH-4)/3;
//	std::vector <char> a = key.a.toBinary();
//	std::stringstream ssbuffer;
//  std::ifstream input (in, std::ios::binary);
//  if (!input.good()) {
//    throw std::logic_error("Невозможно открыть файл \""+in+"\" для чтения.");
//  }
//
//  std::ofstream output (out, std::ios::binary);
//  if (!output.good()) {
//    throw std::logic_error("Невозможно записать файл \""+out+"\".");
//  }
//		
//	while (!input.eof() ) {
//		buffer = new char [BLOCK_SIZE];
//		input.read(buffer, BLOCK_SIZE);
//		ssbuffer << encrypt(buffer, a, key.b);	
//		output.write(ssbuffer.str().c_str(), ssbuffer.str().size());
//		ssbuffer.str("");
//		delete[] buffer;
//	}
//  
//	input.close();
//  output.close();
}

