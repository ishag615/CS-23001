// String Test Program
// 
// Tests: substring
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main ()
{
	{//test case 1
		// Setup
		String testString = "abcdefg",
			
		// Test
		result = testString.substr(0, 2);

		// Verfiy
		assert(result == "abc");
	}
	{//test case 2
		// Setup
		String testString = "hello world",
			
		// Test
		result = testString.substr(0, 5);

		// Verfiy
		assert(result == "hello ");
	}
	{//test case 3
		// Setup
		String testString = "!!!",
			
		// Test
		result = testString.substr(0, 1);

		// Verfiy
		assert(result == "!!");
	}
	
	 std::cout << "Done testing substr(int, int) const." << std::endl;
    return 0;

}