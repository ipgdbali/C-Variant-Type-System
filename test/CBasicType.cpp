#include "CInt.hpp"
#include "CUInt.hpp"
#include "CCString.hpp"

#include <assert.h>

int main(int argc,char * argv[])
{
	CInt i(10);
	CUInt ui(20);

	assert(i.get() == 10);
	i.set(20);
	assert(i.get() == 20);

	assert(ui.get() == 20);
	ui.set(30);
	assert(ui.get() == 30);

	CCString str("abc");
	assert(str.length() == 3);
	assert(strcmp((const char *)str,"abc") == 0);
	return 0;
}
