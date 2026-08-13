//  Stack class test program
//
//  Tests: push and pop 
//
#include "../string/string.hpp"
#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> s1;

        // TEST
        s1.push(1);
        s1.push(2);
        s1.push(3);


        // VERIFY
        assert(s1.top() == 3);
        assert(s1.pop() == 3);
        assert(s1.top() == 2);
        assert(s1.pop() == 2);
        assert(s1.top() == 1);
        assert(s1.pop() == 1);
        assert(s1.empty());
    }

    
    std::cout << "Done testing push and pop." << std::endl;
    return 0;
}

