#include "Decryptor.h"

std::string Decryptor::decrypt(const BigInteger& data, const std::vector<char>  &a, const BigInteger &b) {
  std::stringstream mystream;
  BigInteger temp, block;
  int bf;
  std::string buffer, res;
  
  block = data.calcPowMod(a, b);

  while (block.size() > 3) {
    temp = block;
    block = block/1000;

    mystream.clear();
    mystream << temp - block*1000;
    mystream >> bf;

    if (bf > 127) bf =  bf - 256; // UNICODE

    buffer += char(bf);
  }

  if (block != 1) throw std::logic_error("Входные данные нарушены, дешифрование невозможно.");

  for (int i = buffer.length() - 1; i >= 0; --i ) {
    res += buffer[i];
	}

  return res;
}

void Decryptor::decryptTxtFile(const std::string& in, const std::string& out, CryptoKey &key) {
  std::vector <char> a = key.a.toBinary();
  BigInteger buff(Constants::KEY_LENGTH*2);


  std::ifstream input (in);
  if (!input.good()) {
    throw std::logic_error("Невозможно открыть файл \""+in+"\" для чтения.");
	}

  std::ofstream output (out);
  if (!output.good()) {
    throw std::logic_error("Невозможно записать файл \""+out+"\".");
	}

  while(true) {
    input >> buff;
    if (input.eof()) break;
    output << decrypt(buff, a, key.b);
  }

  input.close();
  output.close();
}

//TODO
void Decryptor::decryptBinFile(const std::string& in, const std::string& out, CryptoKey &key) {
//  std::vector <char> a = key.a.toBinary();
//  char * buffer;
//	const unsigned BLOCK_SIZE = Constants::KEY_LENGTH*2;
//  const unsigned READ_BLOCK_SIZE = (Constants::KEY_LENGTH-4)/3;
//  BigInteger buff(BLOCK_SIZE);
//  std::stringstream ssbuffer;
//
//
//  std::ifstream input (in, std::ios::binary);
//  if (!input.good()) {
//    throw std::logic_error("Невозможно открыть файл \""+in+"\" для чтения.");
//	}
//
//  std::ofstream output (out, std::ios::binary);
//  if (!output.good()) {
//    throw std::logic_error("Невозможно записать файл \""+out+"\".");
//	}
//	
// while(!input.eof()) {
// 	//buffer = new char [READ_BLOCK_SIZE];
// 	//input.read(buffer, READ_BLOCK_SIZE);
// 	//ssbuffer << buffer;
// 	//ssbuffer >> buff;
// 	input >> buff;
//	ssbuffer << decrypt(buff, a, key.b);
//	output.write(ssbuffer.str().c_str(), ssbuffer.str().size());
//
// 	ssbuffer.str("");
// 	delete[] buffer;
// }
//
//  input.close();
//  output.close();
}
