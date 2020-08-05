#include "CValueType.hpp"
#include "CCString.hpp"

#include <cassert>
using namespace std;

class CEntitiy
{
	public:

		void setProductName(CCString val)
		{
			this->mem[1] = std::move(val);
		}

		CCString getProductName()
		{
			return this->mem[1];
		}

		void setSalePrice(CInt val)
		{
			this->mem[0] = std::move(val);
		}

		CInt getSalePrice()
		{
			return this->mem[0];
		}

	protected:

	private:
		CTypedVariant mem[10];
};

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

	CTypedVariant *pInt = &i;

	((CInt*)pInt)->set(30);
	assert(i.get() == 30);

	CInt j;
	j.set(20);

	assert(j.get() == 20);

	CEntitiy e;

	e.setSalePrice(10);
	assert(e.getSalePrice() == 10);

	e.setProductName("Arduino UNO");
	cout << e.getProductName();
	return 0;
}
