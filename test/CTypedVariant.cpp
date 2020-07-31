#include "CTypedVariant.hpp"
#include <assert.h>

class CInt : public CTypedVariant
{
	public:
		CInt(int val) : CTypedVariant("DT_INT",sizeof(int))
		{
			this->write(&val);
		}

		void set(int val)
		{
			this->write(&val);
		}

		int get()
		{
			int dummy;
			this->read(&dummy);
			return dummy;
		}
};

int main(int argc,char * argv[])
{
	CInt i(10);
	assert(i.get() == 10);

	CTypedVariant *pI = &i;

	((CInt*)pI)->set(20);
	assert(((CInt*)pI)->get() == 20);
	return 0;
}
