#include "CUInt.hpp"

CUInt::CUInt(unsigned int val) :
	CTypedVariant("DT_UINT",sizeof(unsigned int))
{
	this->set(val);
}

void CUInt::set(unsigned int val)
{
	this->write(&val);
}

unsigned int CUInt::get()
{
	unsigned int dummy;
	this->read(&dummy);
	return dummy;
}

