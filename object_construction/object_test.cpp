//
//main function
//
#include "object_construction.hpp"

int main(){
    testClass test1;
    testClass test2(test1);
    testClass test3;
    test3= test1;
    test1.~testClass();

    return 0;
}