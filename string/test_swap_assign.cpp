// String Test Program
// 
// Tests: swap assignment
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main ()
{
    //test for copy assignment 
    {//test case 1
    String str1("Hello");
    String str2("World");
    str1 = str2;
    assert(str1 == "World");
    }
    {//test case 1
    String str1("");
    String str2("World");
    str1 = str2;
    assert(str1 == "World");
    }

     //test for swap assignment 
    {//test case 1
    String str1("Hello");
    String str2("World");
    str1.swap(str2);
    assert(str1 == "World");
    assert(str2 == "Hello");
    }
    {//test case 2
    String str1("Hello");
    String str2("");
    str1.swap(str2);
    assert(str1 == "");
    assert(str2 == "Hello");
    }
    {//test case 3
    String str1("Hello");
    String str2("Hello");
    str1.swap(str2);
    assert(str1 == "Hello");
    assert(str2 == "Hello");
    }
    {//test case 4
    String str1("abcdefghijklmnopqrstuvwxyz123456789");
    String str2("987654321zyxwvutsrqponmlkjihgfedsba");
    str1.swap(str2);
    assert(str1 == "987654321zyxwvutsrqponmlkjihgfedsba");
    assert(str2 == "abcdefghijklmnopqrstuvwxyz123456789");
    }
    {//test case 5
    String str1("abcdefghijklmnopqrstuvwxyz123456789 hello world !!!!");
    String str2("987654321zyxwvutsrqponmlkjihgfedsba");
    str1.swap(str2);
    assert(str1 == "987654321zyxwvutsrqponmlkjihgfedsba");
    assert(str2 == "abcdefghijklmnopqrstuvwxyz123456789 hello world !!!!");
    }
    {//test case 6
    String str1("cpp is hard");
    String str2("cpp is hard");
    str1.swap(str2);
    assert(str1 == "cpp is hard");
    assert(str2 == "cpp is hard");
    }
    {//test case 6
    String str1("!!!!");
    String str2("");
    str1.swap(str2);
    assert(str1 == "");
    assert(str2 == "!!!!");
    }
    {//test case 7
    String str1("test for a long string! test for a very long string! test for a very very long string!! test for a very very very long string!!!!");
    String str2("");
    str1.swap(str2);
    assert(str1 == "");
    assert(str2 == "test for a long string! test for a very long string! test for a very very long string!! test for a very very very long string!!!!");
    }
    {//test case 8
    String str1("test for a long string! test for a very long string! test for a very very long string!! test for a very very very long string!!!!");
    String str2("test for a humongously big string! test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!");
    str1.swap(str2);
    assert(str1 == "test for a humongously big string! test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!test for a humongously big string!");
    assert(str2 == "test for a long string! test for a very long string! test for a very very long string!! test for a very very very long string!!!!");
    }
    {//test case 9
    String str1("");
    String str2("");
    str1.swap(str2);
    assert(str1 == "");
    assert(str2 == "");
    }
    
    {//test case 10
    String str1("1");
    String str2("2");
    str1.swap(str2);
    assert(str1 == "2");
    assert(str2 == "1");
    }

    std::cout << "swap-assign and copy-assign done." << std::endl;
}
