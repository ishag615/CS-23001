//  Stack class test program
//
//  Tests: XXX 
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
        stack<int>s;
        std::cout<<"destructing stack"<<std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>s;
        s.push(1);
        s.push(2);
        s.push(5);
        s.push(5);
        s.push(7);
        s.push(8);
        s.push(22);
        s.push(13);
        std::cout<<"destructing stack"<<std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char>s_char;
        std::cout<<"destructing stack"<<std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char>s_char;
        s_char.push('a');
        s_char.push('b');
        s_char.push('c');
        s_char.push('d');
        std::cout<<"destructing stack"<<std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>s_string;
        
        std::cout<<"destructing stack"<<std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>s_string;
        s_string.push("a");
        s_string.push("a");
        s_string.push("a");
        s_string.push("a");
        s_string.push("a");
        s_string.push("a");
        
        std::cout<<"destructing stack"<<std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>s_string;
        s_string.push("hello");
        s_string.push("world");
        s_string.push("how");
        s_string.push("are");
        s_string.push("you");
        s_string.push("today");
        
        std::cout<<"destructing stack"<<std::endl;
    }

    
    std::cout << "Done testing destructor." << std::endl;
    return 0;
}

