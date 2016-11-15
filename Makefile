all: main.o Configurator.o Console.o File.o BigInteger.o
	g++ -std=c++11 *.o -o fileEncryptor
main.o: Console.o
	g++ -std=c++11 -c main.cpp  
Configurator.o: Console.o File.o
	g++ -std=c++11 -c Configurator.cpp  
Console.o:
	g++ -std=c++11 -c Console.cpp  
File.o:
	g++ -std=c++11 -c File.cpp  
BigInteger.o:
	g++ -std=c++11 -c BigInteger.cpp  
clean:
	rm -f ./*.o
