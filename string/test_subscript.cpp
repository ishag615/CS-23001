// String Test Program
// 
// Tests: subscript operator
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    //testing accessor version of subscript operator
    {//test case 1
        // Setup
        String testString("hello");

        // Test
        char result = testString[3];

        // Verify
        assert(result == 'l');
    }
    {//test case 2
        // Setup
        String testString("computer science");

        // Test
        char result = testString[8];

        // Verify
        assert(result == ' ');
    }
    {//test case 3
        // Setup
        String testString("*#!@");

        // Test
        char result = testString[2];

        // Verify
        assert(result == '!');
    }
    {//test case 4
        // Setup
        String testString("abcd123");

        // Test
        char result = testString[5];

        // Verify
        assert(result == '2');
    }
    //testing modifier version of subscript operator
    {//test case 5
        // Setup
        String testString("mello");

        // Test
        testString[0] = 'J';

        // Verify
        assert(testString == "Jello");
    }
    {//test case 6
        // Setup
        String testString("100");

        // Test
        testString[0] = '0';

        // Verify
        assert(testString == "000");
    }
    {//test case 8
        // Setup
        String testString("ladybug");

        // Test
        testString[3] = ' ';

        // Verify
        assert(testString == "lad bug");
    }
    {//test case 9
        // Setup
        String testString("ladybug & cat");

        // Test
        testString[10] = 'b';

        // Verify
        assert(testString == "ladybug & bat");
    }
    std::cout << "Done testing subscript operator." << std::endl;
    return 0;
}
