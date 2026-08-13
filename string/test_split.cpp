// String Test Program
// 
// Tests: split method
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main ()
{
    {//test case 1
    String s="hello!world";
    std::vector<String> result = s.split('!');
    std::cerr<<result.size()<<std::endl;
    assert(result.size() == 2);
    assert(result[0] == "hello");
    std::cerr<<result[1]<<std::endl;
    assert(result[1] == "world");
    }
    {//test case 2
    String s= "-a--b-";
    std::vector<String> result = s.split('-');
    assert(result.size() == 5);
    assert(result[0] == "");
    assert(result[1] == "a");
    assert(result[2] == "");
    assert(result[3] == "b");
    assert(result[4] == "");

    }
    {//test case 3
    String s= "abc ef gh";
    std::vector<String> result = s.split(' ');
    assert(result.size() == 3);
    
    assert(result[0] == "abc");
    assert(result[1] == "ef");
    assert(result[2] == "gh");
    
    }
    {//test case 4
    String s= "abc ef gh";
    std::vector<String> result = s.split(' ');
    assert(result.size() == 3);
    assert(result[0] == "abc");
    assert(result[1] == "ef");
    assert(result[2] == "gh");
    }
    {//test case 5
    String s= "----";
    std::vector<String> result = s.split('-');
    std::cout<<result.size()<<std::endl;
    assert(result.size() == 5);
    }
    
    std::cout << "Done testing split method." << std::endl;
    return 0;
}