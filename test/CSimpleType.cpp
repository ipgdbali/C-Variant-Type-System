#include "CSimpleType.hpp"
#include <cassert>

using namespace std;

int main(int argc,char * argv[])
{
	CInt i(20);
	assert(i.get() == 20);
	i = 10;
	assert(i.get() == 10);
	int vi;
	i.get(&vi);
	assert(vi == 10);
	i = 20;
	i.get(vi);
	assert(vi == 20);

	return 0;
}
