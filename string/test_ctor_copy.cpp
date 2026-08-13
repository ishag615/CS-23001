// String Test Program
// 
// Tests: copy constructor
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main ()
{
    {//test case 1
    String original("Hello");
    String copy(original);
    assert(original == "Hello");
    assert(copy == "Hello");
    }
    {//test case 2
    String original("");
    String copy(original);
    assert(original == "");
    assert(copy == "");
    }
    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}