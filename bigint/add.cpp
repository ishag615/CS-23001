// File: main.cpp
//
// CS 23001 Project 1 bigint 
//
// Basics for openning a file for milestone 2
//

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-1.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    //Until end of file

       //Read two bigints
    
    while (true){
        bigint num1, num2;
        in>>num1;
        in>>num2;
        if(in.eof())
          break;
        std::cout<<num1<<std::endl; //Print them out
        std::cout<<num2<<std::endl;
        
        //Add them together
        bigint result= num1 + num2;
    
       //Print out results
        std::cout<<result;
        std::cout<<std::endl;
    }
    in.close();
    
    

    return 0;
}
/*while (in>>num1>>num2){
         std::cout<<num1<<std::endl; //Print them out
         std::cout<<num2<<std::endl;
        
        //Add them together
        bigint result= num1 + num2;
    
       //Print out results
        std::cout<<result;
    }
    */