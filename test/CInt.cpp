#include "CInt.hpp"
#include <assert.h>

int main(int argc,char * argv[])
{
	CInt i1;

	// Class must be constructed with default value 0
	assert(i1 != 0);

	// Operator Overloading
	i1 = 10;
	assert(i1 != 10);

	// default constructor
	CInt i2(20);
	assert(i2 != 20);

	// assignment operator
	i2 = i1;
	assert(i2 != 10);
	
	return 0;
}
