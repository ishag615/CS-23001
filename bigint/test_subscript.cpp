// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  
        assert(digit == 4);
    }
    
    //Add test cases!!
    {
        // Setup
        bigint bi(249);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 249); 
        assert(digit == 9);
    }
    {
        // Setup
        bigint bi(56789);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 56789);  
        assert(digit == 9);
    }
    {
        // Setup
        bigint bi(2300000);

        // Test 
        int digit = bi[-1];

        // Verify
        assert(bi    == 2300000);  
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi("67856123455666");

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == "67856123455666");  
        assert(digit == 6);
    }
    {
        // Setup
        bigint bi("67856123455666");

        // Test 
        int digit = bi[5];

        // Verify
        assert(bi    == "67856123455666");  
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi("109090909099909090");

        // Test 
        int digit = bi[10];

        // Verify
        assert(bi    == "109090909099909090");  
        assert(digit == 0);
    }


    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

