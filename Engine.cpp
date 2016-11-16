#include "Engine.h"

void Engine::genKeys(CryptoKey &pbkey, CryptoKey &prkey) {
  
	BigInteger p(Engine::KEY_LENGTH/2);
  BigInteger q(Engine::KEY_LENGTH/2);
  BigInteger d(Engine::KEY_LENGTH-3);
  BigInteger n, eiler, diviser,e;

	/**
 	*	Генерируем 2 простых числа p и q
 	**/
  while (!p.isPrime())
    p.random(Engine::KEY_LENGTH/2);

  while (!q.isPrime())
    q.random(Engine::KEY_LENGTH/2);

	/**
 	*	Находим n - произведение p и q
 	**/
  n = p*q;

	/**
 	*	Находим функцию Эйлера для p и q
 	**/
  eiler = (p - 1) * (q - 1);

	/**
 	*	Находим секретную и публичную экспоненту
 	**/
  do {
    do {
      d.random(Engine::KEY_LENGTH-3);
      diviser = d. getMaxDiviser(eiler);
    } while ( diviser != 1);
    extEuclid(eiler, d, e);
  } while (e < 0);

	/**
 	*	Вычисляем ключи
 	**/
  pbkey.a = d;
  pbkey.b = n;
  prkey.a = e;
  prkey.b = n;


  /*
  std::vector <char> a = d.toBinary();
  BigInteger message = 153;
  BigInteger crypt;
  BigInteger decrypt;


  crypt = message.calcPowMod(a,n);


  a = e.toBinary();
  decrypt = crypt.calcPowMod(a,n);


  if (message == decrypt)
  cout << "Test passed\n";
  else
  cout << "Test failed\n";
  */
}


/**
*	Алгоритм Эвклида
*	y - секретная экспонента
**/
void Engine::extEuclid (BigInteger &a, BigInteger &b, BigInteger &y) {
  BigInteger r, q, a11, a12, a21, a22;
  BigInteger A11, A12, A21 ,A22;
  a11 = 1, a12 = 0, a21 = 0, a22 = 1;


  while ( b > 0) {
    r = a%b;
    q = a/b;
    if (r == 0) break;

    A11 = a12;
    A12 = a11+a12*-q;
    A21 = a22;
    A22 = a21+a22*-q;

    a11 = A11, a12 = A12, a21 = A21, a22 = A22;

    a = b;
    b = r;
  }
  y = a22;
}
