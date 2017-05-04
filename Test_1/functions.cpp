#include "stdafx.h"

//#define TESTFUNCTION
#ifdef TESTFUNCTION
#include <iostream>
#endif // TESTFUNCTION
#include "functions.h"

//definition of the function sum
int fun::sum(int x,int y){
#ifdef TESTFUNCTION
	std::cout << "Fnction sum called" << std::endl;
#endif // TESTFUNCTION
	return x+y;
}