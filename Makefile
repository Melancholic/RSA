all: main.o Configurator.o Console.o CryptoKey.o BigInteger.o Encryptor.o Decryptor.o
	g++ -std=c++11 *.o -o fileEncryptor
main.o: Console.o
	g++ -std=c++11 -c main.cpp  
Configurator.o: Console.o Engine.o CryptoKey.o
	g++ -std=c++11 -c Configurator.cpp  
Console.o:
	g++ -std=c++11 -c Console.cpp  
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
