// String Test Program
// 
// Tests: findch
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
		String testString = "abcdefg";
			
		// Test
		int result = testString.findch(0, 'a');

		// Verfiy
		std::cout<<result<<std::endl;
		assert(result == 0);
	}

	{//test case 2
		// Setup
		String testString = "hello world";
			
		// Test
		int result = testString.findch(0, 'a');

		// Verfiy
		assert(result == -1);
	}
    {//test case 3
		// Setup
		String testString = "hello world";
			
		// Test
		int result = testString.findch(5, 'w');

		// Verfiy
		assert(result == 6);
	}
	{//test case 4
		// Setup
		String testString = "hello world";
			
		// Test
		int result = testString.findch(100, 'w');

		// Verfiy
		assert(result == -1);
	}
	{//test case 5
		// Setup
		String testString = "abcabcBC";
			
		// Test
		int result = testString.findch(3, 'c');

		// Verfiy
		assert(result == 5);
	}
	{//test case 6
		// Setup
		String testString = "abcabcBC";
			
		// Test
		int result = testString.findch(6, 'C');

		// Verfiy
		assert(result == 7);
	}
	 std::cout << "Done testing findch." << std::endl;
    return 0;

}