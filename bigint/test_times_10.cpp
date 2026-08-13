// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == 3); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("789009");

        // Test 
        bi = bi.times10(2);

        // Verify
        assert(bi == "78900900"); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("44455666333");

        // Test 
        bi = bi.times10(5);

        // Verify
        assert(bi == "4445566633300000"); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == 0); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == 1); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("444556663339999000000097875544324565455675675786876767868687");

        // Test 
        bi = bi.times10(8);

        // Verify
        assert(bi == "44455666333999900000009787554432456545567567578687676786868700000000"); 
    }
    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

