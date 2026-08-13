// String Test Program
// 
// Tests: String(char ch)
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    {//captial letter test case
        // Setup
        char testChar1 = 'X';

        // Test
        String test1(testChar1);

        // Verify
        assert(test1[0] == 'X');
    }
    {//small letter test case
        // Setup
        char testChar2 = 'a';

        // Test
        String test2(testChar2);

        // Verify
        assert(test2[0] == 'a');
    }
    {//digit test case
        // Setup
        char testChar3 = '8';

        // Test
        String test3(testChar3);

        // Verify
        assert(test3[0] == '8');
    }
    {//special character test case
        // Setup
        char testChar4 = '!';

        // Test
        String test4(testChar4);

        // Verify
        assert(test4[0] == '!');
    }
    {//space test case 
        // Setup
        char testChar5 = ' ';

        // Test
        String test5(testChar5);

        // Verify
        assert(test5[0] == ' ');
    }
    {//special character test case
        // Setup
        char testChar6 = '#';

        // Test
        String test6(testChar6);

        // Verify
        assert(test6[0] == '#');
    }
    {//special charcter test case
        // Setup
        char testChar7 = ',';

        // Test
        String test7(testChar7);

        // Verify
        assert(test7[0] == ',');
    }
    {//capital letter test case
        // Setup
        char testChar8 = 'I';

        // Test
        String test8(testChar8);

        // Verify
        assert(test8[0] == 'I');
    }

std::cout << "Done testing constructor String(char ch)." << std::endl;
    return 0;
}
