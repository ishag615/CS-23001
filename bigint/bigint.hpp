//bigint.hpp
#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP
#include <iostream>

const int CAPACITY = 250;

class bigint{
public:
   bigint();
   bigint(int);
   bigint(const char stringDigits[]);//['1', '5','0','4',.....'/0']
   bigint operator+(const bigint&) const;
   bigint operator*(bigint);
   bigint timesDigit(int) const;
   bigint times10(int) const;
   int numTrailingZeroes();
   int operator[](int);
   std::ostream& debugPrint (std::ostream&) const;
   friend std::ostream &operator<<(std::ostream &,const bigint &);
   friend std::istream &operator>>(std::istream &, bigint &);
   bool operator==(const bigint &a);
private:
int numberArray[CAPACITY];   
};
bigint nfact(int);
#endif