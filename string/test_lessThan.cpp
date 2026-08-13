// String Test Program
// 
// Tests: LESS THAN
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    {//single char test case
        // Setup
        String testStringA = "A";
        String testStringB = "B";

        // Test
        bool check_1 = testStringA<testStringB;

        // Verify
        assert(check_1);
    }
    {//single char (digit) test case
        // Setup
        String testStringC = "4";
        String testStringD = "9";
        
        // Test
        bool check_2 = testStringC<testStringD;

        // Verify
        assert(check_2);
    }
    {//multiple char test case
        // Setup
        String testStringE = "temp";
        String testStringF = "test";
        
        // Test
        bool check_3 = testStringE<testStringF;

        // Verify
        assert(check_3);
    }
    {//multiple char test case
        // Setup
        String testStringG = "hello";
        String testStringH = "hello world";
        
        // Test
        bool check_4 = testStringG<testStringH;

        // Verify
        assert(check_4);
    }
    {//special characters
        // Setup
        String testStringG = "!!!!!!!!!!!";
        String testStringH = "hello world";
        
        // Test
        bool check_4 = testStringG<testStringH;

        // Verify
        assert(check_4);
    }
    {//special characters
        // Setup
        String testStringI = "hello world";
        String testStringJ = "!!!!!!!!!!!";
        
        // Test
        bool check_5 = !(testStringI<testStringJ);

        // Verify
        assert(check_5);
    }
    {//comparing char and string
        // Setup
        char testChar = 'b';
        String testString("banana");

        // Test
        bool check = testChar < testString;

        // Verify
        assert(check);
    }
    {//comparing char and string
        // Setup
        char testChar = 'a';
        String testString("apple");

        // Test
        bool check = testChar < testString;

        // Verify
        assert(check);
    }
    {//comparing char and string
        // Setup
        char testChar = 'c';
        String testString("cat");

        // Test
        bool check = testChar < testString;

        // Verify
        assert(check);
    }
    {
        // Setup
        const char testCharStr[] = "anaconda";
        String testString("babboon");

        // Test
        bool check = testCharStr < testString;

        // Verify
        assert(check);
    }
    {
        // Setup
        String testString1 = "anaconda";
        String testString2("babboon");

        // Test
        bool check = !(testString1 > testString2);

        // Verify
        assert(check);
    }
    {
        // Setup
        String testString1("babboon");
        String testString2 = "anaconda";

        // Test
        bool check = testString1 > testString2;

        // Verify
        assert(check);
    }
    {
        // Setup
        String testString1("hello");
        String testString2 = "hello";

        // Test
        bool check = testString1 >= testString2;

        // Verify
        assert(check);
    }
    {
        // Setup
        String testString1("!!");
        String testString2 = "!";

        // Test
        bool check = testString1 >= testString2;

        // Verify
        assert(check);
    }
    {
        // Setup
        String testString1("hello");
        String testString2 = "hello world";

        // Test
        bool check = testString1 <= testString2;

        // Verify
        assert(check);
    }
    {
        // Setup
        String testString1(":)");
        String testString2 = ":)";

        // Test
        bool check = testString1 <= testString2;

        // Verify
        assert(check);
    }
    {
        // Setup
        String testString1("cplusplus");
        String testString2 = "cplusplus";

        // Test
        bool check = testString1 <= testString2;

        // Verify
        assert(check);
    }
    std::cout << "Done testing less than (<)." << std::endl;
    return 0;
}
