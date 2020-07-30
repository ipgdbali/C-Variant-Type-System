#include "CTypedVariant.hpp"
#include "CAdapterInt.hpp"
#include <assert.h>

int main(int argc,char * argv[])
{
	CTypedVariant var;
	CAdapterInt ai(var);
	int i = 10;

	ai = 20;
	i = ai;
	assert(i == 20);
	printf("%d %d",(int)ai,i);
	return 0;
}
