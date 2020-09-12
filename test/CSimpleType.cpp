#include "CSimpleType.hpp"
#include <cassert>

using namespace std;

int main(int argc,char * argv[])
{
	CInt i(20);

	int vi;
	i.get(&vi);
	assert(vi == 20);

	i = 10;
	i.get(&vi);
	assert(vi == 10);

	return 0;
}
