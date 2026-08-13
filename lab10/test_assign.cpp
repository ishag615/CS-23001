//  Stack class test program
//
//  Tests: assignment operator 
//
#include "../string/string.hpp"
#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //two empty stacks
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> s1;
        stack<int> s2;

        // TEST
        s1 = s2;  //stack 1 is empty and after assignment stack 2 should be equal to stack 1

        // VERIFY
        assert(s1.empty());      //so stack 1 should be empty too
    }


    // ADD ADDITIONAL TESTS AS NECESSARY

    {
        //testing an empty and a non empty stack
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> s3;
        stack<int> s4;
        s3.push(1);
        s3.push(2);
        s3.push(3);

        // TEST
        s4 = s3;  //

        // VERIFY
        assert(!s4.empty()); 
        assert(s4.top() == 3);
    }


    {
        //two non empty stacks
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> s3;
        stack<int> s4;
        s3.push(1);
        s3.push(2);
        s3.push(3);

        s4.push(4);
        s4.push(5);
        s4.push(6);
        // TEST
        assert(s4.top() == 6);
        assert(s3.top() == 3);

        s3 = s4;  //

        // VERIFY
        assert(!s4.empty()); 
        assert(s3.top() == 6);
        assert(s4.top() == 6);
    }
   
    std::cout << "Done testing assignment operator." << std::endl;
    return 0;
}

