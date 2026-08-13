// String Test Program
// 
// Tests: findstr
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main (){
    //finds the number of occurences of a string
    {//test case 1
		// Setup
		String testString = "hello world";
			
		// Test
		int result = testString.findstr(0, "a");

		// Verfiy
		assert(result == -1);
	}
	{//test case 2
		// Setup
		String testString = "hello world";
			
		// Test
		int result = testString.findstr(0, "world");

		// Verfiy
		assert(result == 6);
	}
    {//test case 3
		// Setup
		String testString = "my name is amoeba and her name is paramecium",
			
		// Test
		result = testString.findstr(0, "name");

		// Verfiy
		assert(result == 3);
	}
	{//test case 4
		// Setup
		String testString = "my name is amoeba and her name is paramecium",
			
		// Test
		result = testString.findstr(5, "name");

		// Verfiy
		assert(result == 26);
	}
    {//test case 5
		// Setup
		String testString = "my name is amoeba and her name is paramecium",
			
		// Test
		result = testString.findstr(0, "is");

		// Verfiy
		assert(result == 8);
	}
	{//test case 6
		// Setup
		String testString = "my name is amoeba and her name is paramecium",
			
		// Test
		result = testString.findstr(-5, "is");

		// Verfiy
		assert(result == -1);
	}
	
	 std::cout << "Done testing findstr." << std::endl;
    return 0;

}