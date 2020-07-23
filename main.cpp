#include <cstdio>
#include "CInt.hpp"
#include "CUInt.hpp"

// TODO :
// Create CUInt

int main(int argc,char * argv[])
{
	CInt i(10),j(20);
	CStronglyTyped st(i),wt(j);
	st = wt;

	return 0;
}
