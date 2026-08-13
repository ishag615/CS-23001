//
///
//

#include "object_construction.hpp"

#include <iostream>

//default constructor
testClass::testClass(){
        std::cout << "Called Default Constructor" << std::endl;
}
//copy constructor
testClass::testClass(const testClass& object){
    std::cout << "Called Copy Constructor" << std::endl;
}
//assignment
testClass testClass::operator=(const testClass& object){
    std::cout << "Called Assignment Operator" << std::endl;
}
//destructor
testClass::~testClass(){
    std::cout << "Called Destructor" << std::endl;
}
