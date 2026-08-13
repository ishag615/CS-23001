// String Test Program
// 
// Tests: concatenation
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    {//test case 1
        // Setup
        String testString1("Hello");
        String testString2(" World");

        // Test
        testString1 += testString2;

        // Verify
        assert(testString1 == "Hello World");
    }
    {
     //test case 2
        // Setup
        String testString1("lady");
        String testString2("bug");

        // Test
        testString1 += testString2;

        // Verify
        assert(testString1 == "ladybug");
    }
    {
     //test case 3
        // Setup
        String testString1("chat");
        String testString2("noir");

        // Test
        testString1 += testString2;

        // Verify
        assert(testString1 == "chatnoir");
    }
    {
     //test case 4
        // Setup
        String testString1("cats are pretty");
        String testString2("");

        // Test
        testString1 += testString2;

        // Verify
        assert(testString1 == "cats are pretty");
    }
    {
     //test case 5
        // Setup
        String testString1("");
        String testString2("");

        // Test
        testString1 += testString2;

        // Verify
        assert(testString1 == "");
    }
    {
     //test case 6
        // Setup
        String testString1("1");
        String testString2(" billion");

        // Test
        testString1 += testString2;

        // Verify
        assert(testString1 == "1 billion");
    }
    {
     //test case 7
        // Setup
        String testString1("4+4 =");
        String testString2(" 8");

        // Test
        testString1 += testString2;

        // Verify
        assert(testString1 == "4+4 = 8");
    }
    {//test case 8
        // Setup
        String string1("Hello");
        String string2(" World");

        // Test
        String concatenation = string1 + string2;

        // Verify
        assert(concatenation == "Hello World");
    }
    {//test case 9
        // Setup
        String string1("Miraculous Lady");
        String string2("bug");

        // Test
        String concatenation = string1 + string2;

        // Verify
        assert(concatenation == "Miraculous Ladybug");
    }
    {//test case 10
        // Setup
        String string1("cplusplus");
        String string2(" and struggles:(");

        // Test
        String concatenation = string1 + string2;

        // Verify
        assert(concatenation == "cplusplus and struggles:(");
    }
    std::cout << "Done testing concatenation." << std::endl;
    return 0;
}
