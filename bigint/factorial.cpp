// File: main.cpp
// CS 23001 Project 1 bigint 
//
// milestone 3
//

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    bigint factorial;
    factorial = nfact(100);
    std::cout<<"factorial of 100 is"<<factorial<<std::endl;
    std::cout<<factorial<<"has"<<factorial.numTrailingZeroes()<<"trailing zeroes"<<std::endl;
}
    