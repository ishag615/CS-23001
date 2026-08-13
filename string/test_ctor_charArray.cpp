// String Test Program
// 
// Tests:  String(const char s[])
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    {//single char test case
        // Setup
        const char testArray1[] = "X";

        // Test
        String test1(testArray1);

        // Verify
        assert(test1 == "X");
    }
    {//special chars test case
        // Setup
        const char testArray2[] = "!,&*()%$#@";

        // Test
        String test2(testArray2);

        // Verify
        assert(test2 == "!,&*()%$#@");
    }
    {//test case#3
        // Setup
        const char testArray3[] = "hello";

        // Test
        String test3(testArray3);

        // Verify
        assert(test3 == "hello");
    }
    {//test case#4
        // Setup
        const char testArray4[] = "hello!";

        // Test
        String test4(testArray4);

        // Verify
        assert(test4 == "hello!");
    }
    {//test case#5
        // Setup
        const char testArray5[] = "hello world!";

        // Test
        String test5(testArray5);

        // Verify
        assert(test5 == "hello world!");
    }
    {//test case#6
        // Setup
        const char testArray6[] = "Hello World:)";

        // Test
        String test6(testArray6);

        // Verify
        assert(test6 == "Hello World:)");
    }
    {//test case#7
        // Setup
        const char testArray7[] = "bibbidi bobbidi boo";

        // Test
        String test7(testArray7);

        // Verify
        assert(test7 == "bibbidi bobbidi boo");
    }
     {//test case#8
        // Setup
        const char testArray8[] = "HELLO STRING! YOU'RE UnDeR DeVeLoPmEnT!";

        // Test
        String test8(testArray8);

        // Verify
        assert(test8 == "HELLO STRING! YOU'RE UnDeR DeVeLoPmEnT!");
    }
std::cout << "Done testing constructor String(const char s[])." << std::endl;
    return 0;
}
