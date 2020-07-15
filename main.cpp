#include <cstdio>
#include "CInt.hpp"

class CPerson
{
	private:
	protected:
	public:

		~CPerson()
		{
			delete age;
		}
		CTypedVariant * age;
		void setAge(int value)
		{
			age = new CInt(value);
		}

		void print()
		{
			CInt * pInt = (CInt*)age;
			printf("%d",(int)*(pInt));
		}
};

int main(int argc,char * argv[])
{
	CPerson person;
	person.setAge(10);
	person.print();
	return 0;
}
