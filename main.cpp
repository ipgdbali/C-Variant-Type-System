#include <cstdio>
#include "CVariant.hpp"
#include "CInt.hpp"

int main(int argc,char * argv[])
{
	CInt iVal(10);
	printf("%d\n",iVal.get());
	CTypedVariant var(iVal);
	CInt iVal2(var);
	printf("%d",iVal2.get());

	return 0;
}
