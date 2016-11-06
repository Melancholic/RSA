all: main.o Configurator.o 
	g++ -std=c++11 *.o -o fileEncryptor
main.o:
	g++ -c main.cpp  
Configurator.o:
	g++ -c Configurator.cpp  
clean:
	rm -f ./*.o
