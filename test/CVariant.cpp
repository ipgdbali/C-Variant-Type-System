#include <iostream>

#include "CVariant.hpp"
#include <assert.h>

using namespace std;

int main(int argc,char * argv[])
{
	CVariant var;

	int dummy = 10;

	// get Size
	assert(var.getSize() == 0);

	// read
	assert(var.read(&dummy) == false);

	// dummy will no changes
	assert(dummy == 10);

	// write and read
	assert(var.write(&dummy) == false);
	dummy = 20;
	assert(var.read(&dummy) == false);

	assert(dummy == 20);
	// alloc
	assert(var.alloc(sizeof(int)) == true);

	// write success
	assert(var.write(&dummy) == true);
	dummy = 10;
	assert(var.read(&dummy) == true);

	// dummy back 
	assert(dummy == 20);

	//Copy Constructor
	CVariant var2(var);
	dummy = 10;
	assert(var.read(&dummy) == true);
	assert(dummy == 20);

	dummy = 10;
	assert(var2.write(&dummy) == true);
	assert(var2.read(&dummy) == true);
	assert(dummy == 10);

	assert(var.read(&dummy) == true);
	assert(dummy == 20);

	return 0;
}
