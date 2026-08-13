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
    std::ifstream in;            // Define input stream
    in.open("data1-2.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    //Until end of file

       //Read two bigints
         bigint num1, num2;
         while (in>>num1>>num2){

         std::cout<<num1<<std::endl; //Print them out
         std::cout<<num2<<std::endl;
        
        //Multiply them together
        bigint product= num1 * num2;
    
       //Print out results
       std::cout<<product;
         }
    in.close();
    return 0;
}
