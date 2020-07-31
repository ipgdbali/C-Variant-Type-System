#include "CInt.hpp"

CInt::CInt() : CInt(0)
{
}

CInt::CInt(int val) :
	CTypedVariant("DT_INT",sizeof(int))
{
	this->set(val);
}

void CInt::set(int val)
{
	this->write(&val);
}

int CInt::get()
{
	int dummy;
	this->read(&dummy);
	return dummy;
}

