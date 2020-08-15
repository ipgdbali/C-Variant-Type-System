#include <iostream>

#include "CVariant.hpp"
#include <assert.h>

using namespace std;

void testNull(CVariant & var,bool isNull)
{
	assert(var.isNull() == isNull);
	assert(var.isNotNull() == !isNull);
}

/***
 * Helper method
 */
void testAlloc(CVariant & var)
{
	//Allocated Memory
	assert(var.alloc(sizeof(int)) == true); 

	//should be not null
	testNull(var,false);

	// verify size
	assert(var.getSize() == sizeof(int)); // size allocated
}

void testWriteAndRead(CVariant & var,bool isNull = false)
{
	// var should not be null
	testNull(var,false);

	int dummy;

	// Write 
	dummy = 10; // set a value
	assert(var.write(&dummy) == !isNull); // write value to var
	assert(dummy == 10); // dummy should not change

	// Read
	dummy = 20; // set new value to be stored
	assert(var.read(&dummy) == !isNull); // set var to new value
	assert(dummy == 10); // should be back to value stored
}

void testUnRelated(CVariant & var1,CVariant & var2)
{
	// var1 & var2 should not be null
	testNull(var1,false);
	testNull(var2,false);

	int dummy;
	dummy = 10; // set value to be written 
	assert(var1.write(&dummy) == true); // write to var1
	dummy = 20; // set value to be written
	assert(var2.write(&dummy) == true); // write to var2

	assert(var1.read(&dummy) == true); // read var1
	assert(dummy == 10); // verify its value
	assert(var2.read(&dummy) == true); // read var2 
	assert(dummy == 20); // veriy its value


	dummy = 10; // set value to be written 
	assert(var1.write(&dummy) == true); // write to var1
	dummy = 20; // set value to be written
	assert(var2.write(&dummy) == true); // write to var2
	assert(var2.read(&dummy) == true); // read var2 
	assert(dummy == 20); // veriy its value
	assert(var1.read(&dummy) == true); // read var1
	assert(dummy == 10); // verify its value
}

/**
 * *** TEST ***
 */
void testDefaultConstructor()
{
	CVariant var; // test default construtor

	testNull(var,false); // var should be null
	assert(var.getSize() == 0); // No memory means no size

	int dummy;

	// read from Null CVariant
	dummy = 10;
	assert(var.read(&dummy) == false); // if CVariant is Null then no write or read are allowed
	assert(dummy == 10); // dummy should not change

	//Write and read to Null CVariant
	testWriteAndRead(var,true);

	// test for alloc
	testAlloc(var);
	testNull(var,false);

	// test for write and read
	testWriteAndRead(var,false);

	var.deAlloc();
	testNull(var,true);

}

void testConstructor()
{
	CVariant var(sizeof(int));

	testNull(var,false);
	assert(var.getSize() == sizeof(int));  // allocated size

	// test write and read
	testWriteAndRead(var);

	var.deAlloc();
	testNull(var,true);

	//test alloc
	testAlloc(var);
	testNull(var,false);
}

void testCopy()
{
	// Copy Constructor
	CVariant var1; // setup null CVariant
	testNull(var1,true);
	assert(var1.getSize() == 0); // No memory means no size
	testWriteAndRead(var1,true);

	CVariant var2(var1); // create copy from null CVariant
	testNull(var2,true);
	testWriteAndRead(var2,true);

	//Copy Operator
	var2 = var1;
	testWriteAndRead(var1,true);
	testWriteAndRead(var2,true);

	//Copy Method
	var2.copy(var1);
	testWriteAndRead(var1,true);
	testWriteAndRead(var2,true);

}


int main(int argc,char * argv[])
{
	testDefaultConstructor();
	testConstructor();
	testCopy();

	// TODO : Test Move operator

	return 0;
}
