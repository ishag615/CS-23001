//  Stack class test program
//
//  Tests: copy constructor 
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    //test case 1
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> s1;        
        // TEST
        stack<int> s2(s1);

        // VERIFY
        assert(s2.empty());    }
    
    //test case 2

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> s1;
        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.push(4);
        s1.push(5);
        // TEST
        stack<int>s2(s1);

        // VERIFY
        assert(!s2.empty());
        assert(s2.top()==5);
    }
    //test case 3

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> s1;
        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.push(4);
        s1.push(5);

        stack<int> s2;
        s2.push(2);
        s2.push(3);
        s2.push(4);
        s2.push(5);
        s2.push(6);

        // TEST
        assert(s1.top() == 5);
        stack<int>s3(s2);

        // VERIFY
        assert(s3.top()==6);
    }
    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}

