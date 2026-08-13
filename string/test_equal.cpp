// string Test PrograM
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    {
		// Setup
		String testStr1;

		// Test
		testStr1 = 'a';
		// Verify
		assert(testStr1 == "a");
        std::cout << testStr1;
        std::cout << std::endl;
	}
    {
        // Setup
        String stringA("Hello");
        String stringB("Hello");
        // Test
        assert(stringA == stringB);
    
        // Verify
        std::cout << stringA;
        std::cout << " == ";
        std::cout << stringB;
        std::cout << std::endl;
    }

    {
        // Setup
        String stringC("Hello World! This is a test case for a very hard project");
        String stringD("Hello World! This is a test case for a very easy project");
        // Test
        assert(!(stringC == stringD));
        
        // Verify
        std::cout << stringC;
        std::cout << " != ";
        std::cout << stringD;
        std::cout << std::endl;
    }
    {
        // Setup
        String stringE("Hello World! I am tired");
        String stringF("Hello World! I am tired because this project has drained me");
        // Test
        assert(!(stringE == stringF));
        
        // Verify
        std::cout << stringE;
        std::cout << " != ";
        std::cout << stringF;
        std::cout << std::endl;
    }
    {
        // Setup
        String stringG("Hello World!");
        String stringH("");
        // Test
        assert(!(stringG == stringH));
        
        // Verify
        std::cout << stringG;
        std::cout << " != ";
        std::cout << stringH;
        std::cout << std::endl;
    }
    {
        // Setup
        String stringI("12390!");
        String stringJ("");
        // Test
        assert(!(stringI == stringJ));

        // Verify
        std::cout << stringI;
        std::cout << " != ";
        std::cout << stringJ;
        std::cout << std::endl;
    }
    {
        // Setup
        char testChar = 'e';
        String testString("Hello");

        // Test
        bool check = !(testChar == testString);

        // Verify
        assert(check);
    }
    {
        // Setup
        char testChar = 'X';
        String testString("Y");

        // Test
        bool check = !(testChar == testString);

        // Verify
        assert(check);
    }
    {
        // Setup
        char testChar = 'T';
        String testString("Tiger");

        // Test
        bool check = !(testChar == testString);

        // Verify
        assert(check);
    }
    {
        // Setup
        const char testCharArr[] = "B";
        String testString("A");

        // Test
        bool check = !(testCharArr == testString);

        // Verify
        assert(check);
    }
    {
        // Setup
        const char testCharArr[] = "hello";
        String testString("hello");

        // Test
        bool check = (testCharArr == testString);

        // Verify
        assert(check);
    }
    {
        // Setup
        const char testCharArr[] = "hello world!";
        String testString("hello world!");

        // Test
        bool check = (testCharArr == testString);

        // Verify
        assert(check);
    }

    std::cout << "Done testing ==." << std::endl;
    return 0;
}
