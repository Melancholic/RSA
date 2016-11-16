#include "BigInteger.h"


BigInteger::BigInteger(): currentSize(0),  maxSize(10), positive(true) { 
  numbers = new short [maxSize];
  for (unsigned int i = 0; i < maxSize; i++) {
    numbers[i] = 0;
  }
}


BigInteger::BigInteger(unsigned int n): currentSize(0), maxSize(n), positive(true) { 
  numbers = new short [maxSize]; 
  for (unsigned int i = 0; i < maxSize; i++) {
    numbers[i] = 0;
  }
}


BigInteger::BigInteger(const BigInteger &obj): currentSize(obj.currentSize), maxSize(obj.maxSize),
  positive(obj.positive) {
  numbers = new short [maxSize];
  for (unsigned int i = 0; i < maxSize; i++){
    numbers[i] = obj.numbers[i];
  }
}


BigInteger::~BigInteger() {
   delete [] numbers;
}


BigInteger BigInteger::operator=(const BigInteger &obj) {
  delete [] numbers;
  maxSize = obj.maxSize;
  currentSize = obj.currentSize;
  positive = obj.positive;
  numbers = new short [maxSize];
  for (unsigned int i = 0; i < currentSize; i++) {
    numbers[i] = obj.numbers[i];
  }
  return *this;
}


//convert value to binary 
std::vector <char> BigInteger::toBinary() {
  std::vector <char> result, temp;
  BigInteger q, reminder,hex;
  hex = 16;
  q = *this;
  short hexVal = 0;


  //to hex
  while ( q != 0) {
    q = q.divMod(hex, reminder);

    if (reminder.currentSize == 1) {
      hexVal = reminder.numbers[0];
    } else if (reminder.currentSize == 2) {
        hexVal = reminder.numbers[0]+reminder.numbers[1]*10;
      } else {
        hexVal = 0;
      }
    
    for (int j = 0; j < 4; j++) {
      char buff;
      (hexVal&1)?(buff = 1):(buff = 0);
      temp.push_back(buff);
      hexVal = hexVal>>1;
    }
  }

  bool first = true;
  for (int i = temp.size()-1; i >= 0; i--) {
    if (temp[i] == 1)
      first = false;
    if (!first)
      result.push_back(temp[i]);
  }
  return result;
}


int BigInteger::size()  { 
   return currentSize;
}


BigInteger BigInteger::pow(const unsigned int power) {
 
  BigInteger res;
  if (power == 0) {
    res = 1;
    return res;
  }
  res = *this;
  BigInteger pw;
  pw = power;

  std::vector <char> d = pw.toBinary();

  for(unsigned int i = 1; i < d.size(); i++) {
    if (d[i])
      res = (res*res**this);
    else
      res = (res*res);
  }
  if (pw.isEven()) {
    res.positive = true;
  } else {
    res.positive = positive;
  }
  return res;
}


//a^d(mod m) 
BigInteger BigInteger::calcPowMod(const std::vector <char> &d, const BigInteger m) const { 
  BigInteger res;
  res = *this;

  for(unsigned i = 1; i < d.size(); i++) {
    if (d[i]) {
      res = ((res*res)**this) % m;
    } else {
      res = (res*res) % m;
    }
  }
  return res;
}



 // Тест М. Робина на простоту 
bool BigInteger::isPrime() {
  if ( *this == 1 || currentSize == 0 ) return false;
  if ( *this == 2 || *this == 3 ) return true;
  if ( isEven() )  return false;

  BigInteger temp(*this);
  BigInteger x;
  BigInteger a(currentSize);
  BigInteger t(temp);
  temp -= 1;
  int s = 0;

  do {
    t = t/2;
    s++;
  } while ( t.isEven());


  std::vector <char> bint;
  bint = t.toBinary();

  std::vector <char> bintwo;
  bintwo.push_back(1);
  bintwo.push_back(0);

  unsigned int i = 0;
  
  while (i < currentSize) {
start:

    if ( i == currentSize-1) break;
    i++;

    if (currentSize > 3) {
      int randomSize;
      randomSize = rand()%(currentSize-3)+2;
      a.random(randomSize);
    } else{
      do {
        a.random(1);
      } while (!( a > 1 && a < temp));
    }

    //getting a^t mod *this
    x = a.calcPowMod(bint, *this);


    if ((x == 1) || (x == temp)) continue;


    for (int j = 0; j < s-1; j++) {
      x = x.calcPowMod(bintwo, *this);
      if (x == 1) return false;
      if (x == temp) goto start;
    }

    return false;
  }


  return true;
}


BigInteger BigInteger::getMaxDiviser(BigInteger b) {
  BigInteger a(*this);
  BigInteger c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a.abs();
}


BigInteger BigInteger::abs() {
  BigInteger temp(*this);
  temp.positive = true;
  return temp;
}


BigInteger BigInteger::operator=(const int b) {  
  currentSize = 0;
  positive = true;
  std::string str;
  char temp;
  unsigned int i = 0;

  if (b < 0)
    positive = false;

  if (b == 0) {
    for (unsigned int i = 0; i < maxSize; i++)
      numbers[i] = 0;
    return *this;
  }

  std::stringstream mystream;
  mystream << std::abs(b);
  mystream >> str;

  while (i < str.length()) {
    if (i == maxSize) break;
    temp = str[i];
    mystream.clear();
    mystream << temp;
    mystream >> numbers[i];
    i++;
    currentSize++;
  }


  reflect();
  return *this;
}


BigInteger BigInteger::operator+(const BigInteger &obj) {
  int newsize= (maxSize >= obj.maxSize) ? (maxSize+1) : (obj.maxSize+1);

  BigInteger temp(newsize);
  register  short chache = 0;
  register short summ = 0;
  register short a,b;
  unsigned  int maxpos;


  if (currentSize == 0 && obj.currentSize == 0) return temp;

  maxpos = (currentSize >= obj.currentSize) ? (currentSize-1) : (obj.currentSize-1);

  if ((positive && obj.positive) || (!positive && !obj.positive  )) {
    unsigned int i;
    for ( i = 0; i <= maxpos; i++) {
      summ = chache;
      a = (currentSize > i) ? (numbers[i]) : (0);
      b = (obj.currentSize > i) ? (obj.numbers[i]) : (0);
      summ += a+b;
      chache = short (summ/10.0);
      summ = summ - chache*10;
      temp.numbers[i] = summ;
      temp.currentSize++;
    }
    if (chache) {
      temp.numbers[i] = chache;
      temp.currentSize++;
    }
    if (!positive && !obj.positive)
      temp.positive = false;
  } else
    if ((!positive && obj.positive) || (positive && !obj.positive)) {
      if (!isAbsBigger(obj)) {
        for (unsigned  int i = 0; i <= maxpos; i++) {
          summ = chache;
          chache = 0;

          a = (currentSize > i)?(numbers[i]):(0);
          b = (obj.currentSize > i)?(obj.numbers[i]):(0);

          if ( a + summ >= b)
            summ += a - b;
          else {
            summ += a + 10 - b;
            chache = -1;
          }

          temp.numbers[i] = summ;
          temp.currentSize++;
          if (!positive && obj.positive)
            temp.positive = false;
        }
      }
      else {
        for ( unsigned int i = 0; i <= maxpos; i++)
        {
          summ = chache;
          chache = 0;

          a = (currentSize > i)?(numbers[i]):(0);
          b = (obj.currentSize > i)?(obj.numbers[i]):(0);


          if  (b+summ >= a)
            summ += b - a;
          else {
            summ += b + 10 - a;
            chache = -1;
          }

          temp.numbers[i] = summ;
          temp.currentSize++;
        }
        if (positive && !obj.positive)
          temp.positive = false;
      }
    }

    temp.removeSpace();
    return temp;
}

BigInteger BigInteger::operator+(const int b) {
  BigInteger res, temp;
  temp = b;
  res =  temp + *this;
  return res;
}


BigInteger BigInteger::operator*(const BigInteger &obj) {
  BigInteger temp(currentSize + obj.currentSize); 
  BigInteger res;
  register int shift = 0;
  register  short product;
  register short chache = 0;


  for (unsigned int i = 0; i < currentSize; i++) {
    temp = 0;
    chache = 0;
    for (unsigned int j = 0; j < obj.currentSize; j++) {
      product = chache + numbers[i]*obj.numbers[j];


      chache = short (product/10.0);
      product = product - chache*10;


      temp.numbers[j+shift] = product;
      temp.currentSize++;
    }


    temp.currentSize += shift;
    if (chache) {
      temp.numbers[temp.currentSize] = chache;
      temp.currentSize++;
    }
    shift++;  
    res += temp;  
  }

  if ((!positive && obj.positive) || (positive && !obj.positive)) {
    res.positive = false;
  }
  return res;
}


BigInteger BigInteger::operator*(const int b) {
  BigInteger res, temp;
  temp = b;
  res = *this * temp;
  return res;
}


BigInteger BigInteger::operator-( const BigInteger &obj) {
  BigInteger temp;
  temp = *this + -obj;
  return temp;
}


BigInteger BigInteger:: operator-(const int b) {
  BigInteger res, temp;
  temp = b;
  res = *this - temp;
  return res;
}


BigInteger BigInteger::operator/(const BigInteger &obj) {

  if (obj.currentSize == 0) {
    throw std::overflow_error("division by zero");
  }

  BigInteger res, bf;
  res = divMod(obj, bf);


  if ((!positive && obj.positive) || (positive && !obj.positive)) {
    res.positive = false;
  }

  return res;
}


BigInteger BigInteger::operator/(const int b) {
  if ( b == 0 ) {
    throw std::overflow_error("division by zero");
  }

  BigInteger res,temp;
  temp = b;
  res = *this/temp;

  return res;
}


BigInteger BigInteger::operator%(const BigInteger &obj) {
  if ( obj.currentSize == 0 ) {
    throw std::overflow_error("remainder of division by zero");
  }

  BigInteger part;
  divMod(obj, part);

  if (!positive) {
    part.positive = false;
  }
  return part;
}


BigInteger BigInteger::operator%( const int b) {
  if (b == 0) {
    throw std::overflow_error("remainder of division by zero");
  }

  BigInteger temp, res;
  temp = b;
  res = *this % temp;
  return res;
}


BigInteger BigInteger::operator+=(const BigInteger &obj) {
  *this = *this + obj;
  return *this;
}


BigInteger BigInteger::operator+=(const int b) {
  *this = *this + b;
  return *this;
}


BigInteger BigInteger::operator-=(const BigInteger &obj) {
  *this = *this - obj;
  return *this;
}


BigInteger BigInteger::operator-=(const int b) {
  *this = *this - b;
  return *this;
}


bool BigInteger::operator>(const BigInteger &obj) { 
  if (positive && !obj.positive)
    return true;


  if (!positive && obj.positive)
    return false;


  if (positive && obj.positive) {
    if (currentSize > obj.currentSize)
      return true;
    if (currentSize < obj.currentSize)
      return false;


    for (int i = currentSize-1; i >= 0; i--) { 
      if (numbers[i] > obj.numbers[i])
        return true;
      else
        if (numbers[i] < obj.numbers[i])
          return false;
    } 
  }


  if (!positive && !obj.positive) {
    if (currentSize > obj.currentSize)
      return false;
    if (currentSize < obj.currentSize)
      return true;


    for (int i = currentSize-1; i >= 0; i--) { 
      if (numbers[i] > obj.numbers[i])
        return false;
      else
        if (numbers[i] < obj.numbers[i])
          return true;
    }
  }
  return false;
}


bool BigInteger::operator>(const int b) {
  BigInteger temp;
  temp = b;
  return (*this > temp);
}


bool BigInteger::operator<(const BigInteger &obj) {
  if (positive && !obj.positive) return false;


  if (!positive && obj.positive) return true;


  if (positive && obj.positive) {
    if (currentSize > obj.currentSize) return false;
    if (currentSize < obj.currentSize) return true;


    for (int i = currentSize-1; i >= 0; i--) { 
      if (numbers[i] > obj.numbers[i]) {
        return false;
      } else {
        if (numbers[i] < obj.numbers[i]) return true;
      }
    } 
  }


  if (!positive && !obj.positive) {
    if (currentSize > obj.currentSize) return true;
    if (currentSize < obj.currentSize) return false;


    for (int i = currentSize-1; i >= 0; i--) { 
      if (numbers[i] > obj.numbers[i]) {
        return true;
      } else {
        if (numbers[i] < obj.numbers[i]) return false;
      }
    } 
  }
  return false;
}


bool BigInteger::operator<(const int b) {
  BigInteger temp;
  temp = b;
  return (*this < temp);
}


bool BigInteger::operator==(const BigInteger &obj) {
  if ((positive && !obj.positive) || (!positive && obj.positive)) { 
    return false;
 }

  if (currentSize != obj.currentSize) {
    return false;
  }

  for (unsigned int i = 0; i < currentSize; i++) {
    if (numbers[i] != obj.numbers[i]) return false;
  }

  return true;
}


bool BigInteger::operator==(const int b) {
  BigInteger temp;
  temp = b;
  return (*this == temp);
}


bool BigInteger::operator!=(const BigInteger &obj) {
  return !(*this == obj);
}


bool BigInteger::operator!=(const int b) {
  BigInteger temp;
  temp = b;
  return (!(*this == temp));
}


bool BigInteger::operator>=(const BigInteger &obj) {
  return (*this > obj || *this == obj);
}


bool BigInteger::operator>=(const int b) {
  BigInteger temp;
  temp = b;
  return (*this > temp || *this == temp); 
}


bool BigInteger::operator<=(const BigInteger &obj) {
  return (*this < obj || *this == obj);
}


bool BigInteger::operator<=(const int b) {
  BigInteger temp;
  temp = b;
  return (*this < temp || *this == temp);
}

BigInteger BigInteger::divMod(const BigInteger &obj, BigInteger &reminder) {
  BigInteger  part;
  BigInteger  res(currentSize);
  BigInteger temp(obj.currentSize+1);
  register int position = currentSize-1;
  register  int i = 0;
  register unsigned  int j = 0;
  register int count = 0;


  if (obj.currentSize == 0) return res;
  if (currentSize == 0) return res;

  while (j < obj.currentSize) {
    if ( position < 0 ) break;
    temp.numbers[j] = numbers[position];
    temp.currentSize++;
    position--;
    j++;
  }
  temp.reflect();
 
  if (temp.isAbsBigger(obj)) {
    if (position >= 0) {
      temp.reflect();
      temp.numbers[temp.currentSize] = numbers[position];
      temp.currentSize++;
      position--;
      temp.reflect();
    }
  }
  part = temp;
  
  while (!part.isAbsBigger(obj)) {
    part = part + -obj;
    count ++;
  }


  res.numbers[i] = count;
  res.currentSize++;
  i++;

  while (position >= 0) {
    temp = 0;
    temp.numbers[0] = numbers[position];
    temp.currentSize++;
    position--;
    part.concat(temp);
    temp.removeSpace();
    part.removeSpace();
    temp = part;

    while (temp.isAbsBigger(obj)) {
      if (position < 0) break;
      temp.reflect();
      temp.numbers[temp.currentSize] = numbers[position];
      temp.currentSize++;
      position--;
      temp.reflect();
      res.numbers[i] = 0;
      res.currentSize++;
      i++;
    }
    temp.removeSpace();
    part = temp;
    count = 0;

    while (!part.isAbsBigger(obj)) {
      part = part + -obj;
      count ++;
    }

    res.numbers[i] = count;
    res.currentSize++;
    i++;
  }

  res.reflect();
  res.removeSpace();
  reminder = part;
  return res;
}




BigInteger operator+(const int a, const BigInteger &b) {
  BigInteger res, temp;
  temp = a;
  res = temp + b;
  return res;
}


BigInteger operator-(const int a, const BigInteger &b) {
  BigInteger res, temp;
  temp = a;
  res =  temp - b;
  return res;
}


BigInteger operator*(const int a, const BigInteger &b) {
  BigInteger temp, res;
  temp = a;
  res = temp * b;
  return res;
}


BigInteger operator/(const int a, const BigInteger &b) {
  if (b.currentSize == 0) {
    throw std::overflow_error("division by zero");
  }

  BigInteger res,temp;
  temp = a;
  res = temp/b;
  return res;
}


BigInteger operator%(const int a, const BigInteger &b) {
  if (b.currentSize == 0) {
    throw std::overflow_error("remainder of division by zero.");
  }

  BigInteger temp, res;
  temp = a;
  res = temp % b;
  return res;
}


bool operator>(const int a, const BigInteger &b) {
  BigInteger temp;
  temp = a;
  return(temp > b);
}


bool operator<(const int a, const BigInteger &b) {
  BigInteger temp;
  temp = a;
  return (temp < b);
}


bool operator==(const int a, const BigInteger &b) {
  BigInteger temp;
  temp = a;
  return (temp == b);
}


bool operator!=(const int a, const BigInteger &b) {
  BigInteger temp;
  temp = a;
   return !(temp == b);
}


bool operator>=(const int a, const BigInteger &b) {
  BigInteger temp;
  temp = a;
  return (temp > b || temp == b);
}


bool operator<=(const int a, const BigInteger &b) {
  BigInteger temp;
  temp = a;
  return (temp < b || temp == b);
}


std::ostream& operator<<(std::ostream &out, const BigInteger &obj) {
  if (!obj.positive)
    out << "-";
  for(int i = obj.currentSize-1; i >= 0; i--)
    out << obj.numbers[i];
  if (obj.currentSize == 0)
    out << 0;
  //out << "\nSize:" << obj.currentSize << endl;
  return out;
}


std::istream& operator>>(std::istream &in, BigInteger &obj) {
  char bf;
  obj.positive = true;
  obj.currentSize = 0;
  unsigned  int i = 0;
  while (i < obj.maxSize) {
    bf = in.get();
    if (bf == ' ' || bf == '\n' || in.eof() ) break;
    if (bf == '-') {
      obj.positive = false;
    } else {
      if ( bf == '0' ||  bf == '1' ||  bf == '2' ||  bf == '3' ||  bf == '4' ||
        bf == '5' ||  bf == '6' ||  bf == '7' ||  bf == '8' ||  bf == '9' ) {
        std::stringstream mystream;
        mystream << bf;
        mystream >> obj.numbers[i];
        obj.currentSize++;
        i++;
      }
      else {
        throw std::overflow_error("input data format is incorrect");
      }
    }
  } 
  obj.reflect();
  obj.removeSpace();
  return in;
}

void BigInteger::reflect() {
  if (currentSize > 1) {
    int j = 0;
    short *tmp = new short[currentSize];


    for (unsigned int i = 0; i < currentSize; i++)
      tmp[i] = numbers[i];


    for (int i = currentSize-1; i >= 0; i--) {
      numbers[j] = tmp[i];
      j++;
    }
    delete [] tmp;
  }
}

void BigInteger::removeSpace() {
  unsigned int deletePos = currentSize;
  for (unsigned int i = 0; i <  currentSize; i++) {
    if (numbers[i] == 0) {
      if (deletePos == currentSize) deletePos = i;
    } else {
      deletePos = currentSize;
    }
  }
  currentSize = deletePos;
}

void BigInteger::concat(const BigInteger &obj) {
  int j = currentSize;
  reflect();
  for (int i = obj.currentSize-1; i >=0; i--) {
    numbers[j] = obj.numbers[i];
    currentSize++;
    j++;
  }
  reflect();
}

bool BigInteger::isAbsBigger(const BigInteger &obj) {
  if (obj.currentSize > currentSize) {
    return true;
  } else if (obj.currentSize < currentSize) {
      return false;
  }


  for (int i = currentSize-1; i >= 0; i--) {
    if (obj.numbers[i] > numbers[i] ) {
      return true;
    } else if (obj.numbers[i] < numbers[i]) {
        return false;
    }
  }
  return false;
}

bool BigInteger::isEven() {
  return !(numbers[0] & 1);
}

void BigInteger::random(unsigned int length) {
  if (length <= maxSize) { 
    for (unsigned int i = 0; i < length; i++)
      numbers[i] = (i != length-1)? (rand()%10) : (rand()%9+1);   


    currentSize = length;
    positive = true;
  }
  else {
    throw std::overflow_error("specified size exceeds the maximum capacity of the object");
  }
}

BigInteger operator-(const BigInteger &obj) {
  BigInteger temp(obj);
  temp.positive = !temp.positive;
  return temp;
}
