// String Test Program
// 
// Tests: length, capacity
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    //testing length
    {//test case 1
        // Setup
        String testString("");

        // Test
        int length = testString.length();

        // Verify
        assert(length == 0);
    }
    {//test case 2
        // Setup
        String testString("hi");

        // Test
        int length = testString.length();

        // Verify
        assert(length == 2);
    }
    {//test case 3
        // Setup
        String testString("hello");

        // Test
        int length = testString.length();

        // Verify
        assert(length == 5);
    }
    {//test case 4
        // Setup
        String testString("pneumonoultramicroscopicsilicovolcanoconiosis");

        // Test
        int length = testString.length();

        // Verify
        assert(length == 45);
    }
    {//test case 5
        // Setup
        String testString("!@#$!^^^&&&");

        // Test
        int length = testString.length();

        // Verify
        assert(length == 11);
    }
    {//test case 6
        // Setup
        String testString("");

        // Test
        int length = testString.length();

        // Verify
        assert(length == 0);
    }
    //testing capacity

    {//test case 7
        // Setup
        String testString("");

         // Verify
        assert(testString.capacity() == 0);

    }
    {//test case 8
        // Setup
        String testString("hello world");

        // Verify
        assert(testString.capacity() == 11);

    }
    {//test case 8
        // Setup
        String testString("....??????****&&&&&&");
            
        // Verify
        assert(testString.capacity() ==20);

    }
    {//test case 8
        // Setup
        String testString("hhhhhhhhhhhhhhhhhhuyytterrtyaukdue cudncfreuofyueryfnoiwenroqinrufyeoriynoire");

         // Verify
        assert(testString.capacity() ==77);
    }
    std::cout << "Done testing length and capacity." << std::endl;
    return 0;
}
