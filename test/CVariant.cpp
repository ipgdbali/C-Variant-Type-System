#include "CVariant.hpp"
#include <assert.h>

int main(int argc,char * argv[])
{
	/**
	 * Default Constructor Test Case
	 */
	CVariant variant;
	int dummy;

	// Test Size
	assert(variant.getSize() == 0);

	// Test variant.getData
	assert(variant.getData(&dummy) == false);
	
	// Set Data
	dummy = 10;
	variant.alloc(&dummy,sizeof(dummy));
	dummy = 20;
	variant.getData(&dummy);
	assert(dummy == 10);
	assert(variant.getSize() == sizeof(dummy));

	// Clear Data
	variant.clear();
	assert(variant.getSize() == 0);
	assert(variant.getData(&dummy) == false);

	//Copy Contructor
	dummy = 20;
	variant.alloc(&dummy,sizeof(int));
	CVariant variant2(variant); // create variant2 based on variant
	dummy = 30;
	variant2.getData(&dummy);
	assert(dummy == 20);
	
	//Copy Operator
	dummy = 30;
	variant.alloc(&dummy,sizeof(dummy));
	variant2 = variant;
	dummy = 20;
	variant.getData(&dummy);
	assert(dummy == 30);

	//Move Constructor
	
	//Move Operator

	return 0;
}
