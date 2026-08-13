// String Test Program
// 
// Tests:  default constructor, uses ==
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    // Setup

    // Test 
    String test;

    // Verify
    std::cout << "0 == " << test << std::endl;
    assert(test.length() == 0);

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}

