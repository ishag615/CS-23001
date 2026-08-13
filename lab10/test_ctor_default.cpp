//  Stack class test program
//
//  Tests: default constructor 
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>s1;
        // TEST
        //stack<int>  x;

        // VERIFY
        assert(s1.empty());
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>s1;
        // TEST
        s1.push(1);
        s1.push(9);

        // VERIFY
        assert(!s1.empty());
        assert(s1.top() == 9);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char>s_char;
        // TEST
        //stack<int>  x;

        // VERIFY
        assert(s_char.empty());
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char>s_char;
        // TEST
        s_char.push('a');
        s_char.push('b');
        s_char.push('c');
        s_char.push('d');

        // VERIFY
        assert(!(s_char.empty()));
        assert(s_char.top()== 'd');
    }
    
    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}

