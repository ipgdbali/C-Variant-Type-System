#include <cassert>
#include "CSimpleType.hpp"

int main(int argc,char * argv[])
{
	CStrongTyped arrStrong[10];

	for(int li = 0;li < 10;li++)
	assert(arrStrong[li].getTypeId() == nullptr);

	CInt i;
	CUInt ui;

	i = 10;
	ui = 20;

	arrStrong[0] = i;
	arrStrong[1] = ui;

	assert(arrStrong[0].getTypeId() == CInt::TYPE_ID);
	assert(arrStrong[1].getTypeId() == CUInt::TYPE_ID);

	i = 20;
	i = arrStrong[0];
	assert(i == 10);

	ui = 10;
	ui = arrStrong[1];
	assert(ui == 20);

	return 0;
}
