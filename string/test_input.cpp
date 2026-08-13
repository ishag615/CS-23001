// String Test Program
// 
// Tests: input operator
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    //testing length
    {//test case 1

        // Test
        String input;
        std::cout<<"please input 'ants'";
        std::cin>>input;

        // Verify
        assert(input == "ants");
    }
    {//test case 2

        // Test
        String input;
        std::cout<<"please input 'hello_world'";
        std::cin>>input;

        // Verify
        assert(input == "hello_world");
    }


    std::cout << "Done testing input operator." << std::endl;
    return 0;
}
