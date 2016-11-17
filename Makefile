all: main.o Configurator.o Constants.o CryptoKey.o BigInteger.o Encryptor.o Decryptor.o
	g++ -std=c++11 *.o -o fileEncryptor
main.o: Constants.o Helpers.o
	g++ -std=c++11 -c main.cpp  
Configurator.o: Constants.o Engine.o CryptoKey.o
	g++ -std=c++11 -c Configurator.cpp  
Constants.o:
	g++ -std=c++11 -c Constants.cpp  
Helpers.o:
	g++ -std=c++11 -c Helpers.cpp 
CryptoKey.o: BigInteger.o
	g++ -std=c++11 -c CryptoKey.cpp  
BigInteger.o:
	g++ -std=c++11 -c BigInteger.cpp  
Engine.o: CryptoKey.o
	g++ -std=c++11 -c Engine.cpp  
Encryptor.o: CryptoKey.o
	g++ -std=c++11 -c Encryptor.cpp  
Decryptor.o: CryptoKey.o
	g++ -std=c++11 -c Decryptor.cpp  
clean:
	rm -f ./*.o
