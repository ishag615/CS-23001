//bigint.cpp
#include "bigint.hpp"

bigint::bigint(){
   for(int i=0; i < CAPACITY; ++i){
       numberArray[i]=0;
   }
}
//1504--> [4, 0, 5, 1,....] (store the digits backwards in the array)
// chopping the numbers into the digits
bigint::bigint(int num):bigint(){
   for(int i = 0; i<CAPACITY; ++i){
      numberArray[i]=num%10;
      num= num/10; //150 
   }
}
bigint::bigint(const char stringDigits[]):bigint(){
int i= 0;
while(stringDigits[i] != '\0'){
++i;
}
int k = 0;
    for(int j=i-1; j>=0; --j){
        numberArray[k] = int(stringDigits[j]) - int('0');
        ++k;
    }

}
std::ostream& bigint::debugPrint (std::ostream& os) const{
for (int i=CAPACITY-1; i < 0; --i){
   os << numberArray[CAPACITY-1]<<"|";
}
return os;
    }
std::ostream &operator<<(std::ostream& os,const bigint &b){//prints at most 80 digits per line. no leading zeroes to be printed
    int track = CAPACITY-1;
    while(b.numberArray[track] == 0){
        --track;
    }
    int j=0;
    for (int i=track; i >= 0; --i){
        os << b.numberArray[i];
        j++;
        if (j ==80){
            os <<std::endl;
            j=0;
        }
    }
    if (track == 0)
        os<<"0";
    return os;
 }
 std::istream &operator>>(std::istream & is, bigint &a)
 {
   //Postcondition: Reads char until ;
    //Friend of: bigint class
    char ch;
    char testArray[CAPACITY] = {0};
    int i=0;
    
    while (i < CAPACITY){
      is>> ch;
      if (ch == ';')
         break;
      testArray[i]=ch;
      i++;
    } ;
    a = bigint(testArray);

    return is;
 }
bigint bigint::operator+(const bigint& a) const
{

    bigint temp;
    int num = 0;
    int carry = 0;
    for(int i = 0; i < CAPACITY; i++)
    {
        num = numberArray[i] + a.numberArray[i] + carry;
        carry = num/10;
        num=num%10;

        temp.numberArray[i] = num;
    }

    
    return temp;

}
 bigint bigint::timesDigit(int x) const{
bigint a;
    int product = 0, b = 0;
    for (int i = 0; i<CAPACITY; i++){
        b = (numberArray[i] * x) + b;
        product = b % 10;
        b = b/10;
        a.numberArray[i] = product;
    }
    return a;

 }
 bigint bigint::times10(int x) const{
   bigint a;
    for (int i = CAPACITY - 1 - x; i >= 0; i--){
        a.numberArray[i + x] = numberArray[i];
    }
    for (int j = 0; j<x; j++){
        a.numberArray[j] = 0;
    }
    return a;
}
bigint bigint::operator*(bigint rhs){ 
    bigint product = 0;
    for (int i = 0; i<CAPACITY; i++){
        product = (timesDigit(rhs.numberArray[i])).times10(i) + product;
    }
    return product;
}
//How many trailing zero's are there on 100! ?
//to get to 100, we multiply 5, 10, 15, 25 (5^2), 30, 35, 40, 45, 50 (5^2 *2), 
//55, 60, 65, 70, 75(5^2*3), 80, 85, 90, 95, 100(5^2*4)
// in this process we multiply 5 by 1+1+1+2+1+1+1+1+2+1+1+1+1+2+1+1+1+1+2
//=23
//so 100! has 23 trailing zeroes

 bigint nfact(int x){
   bigint factorial = "1";
   for (int i=1; i <= x; i++ ){
    factorial = factorial*i;
    }
    return factorial;
}
int bigint::numTrailingZeroes(){
    int trail = 0;
    while(numberArray[trail] == 0){
        ++trail;
    }
    return trail;

}


int bigint::operator[](int i)
{
    if (i<0){
    std::cout <<"error"<<std::endl;
    return 0;
    }
        return numberArray[i];
}

bool bigint::operator==(const bigint &a){
   for(int i = 0; i < CAPACITY; ++i){
       if (numberArray[i] != a.numberArray[i]){
       return false;
       }
   }
   return true;
   }