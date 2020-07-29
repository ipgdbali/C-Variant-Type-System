#include "CVariant.hpp"

int main(int argc,char * argv[])
{
	/**
	 * Default Constructor Test Case
	 */
	cout << "Default Constructor" << endl;

	CVariant variant;

	//Test Size
	cout << " getSize() ...";
	ASSERT(variant.getSize() != 0);
	cout << "pass" << endl;

	//Test variant.getData should throw exception
	
	//Test clear
	
	//Set Data
	int dummy;
	dummy = 10;
	variant.alloc(&dummy,sizeof(dummy));
	dummy = 20;
	variant.getData(&dummy);
	ASSERT(dummy != 10);
	ASSERT(variant.getSize() != sizeof(dummy));

	variant.clear();

	
	return 0;
}
