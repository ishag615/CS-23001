//Lab 6
//Dynamic memory & Object construction
//isha gupta


#ifndef object_construction_h
#define object_construction_h

#include <iostream>

class testClass{
	public:
		//default constructor
        testClass();

        //copy constructor
        testClass(const testClass& object);

        //assignment
        testClass operator=(const testClass& object);

        //destructor
        ~testClass();
};

#endif