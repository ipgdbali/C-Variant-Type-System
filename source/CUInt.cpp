#include "CUInt.hpp"

CUInt::CUInt(const CUInt & source) : 
	CStronglyTyped(source)
{
}

CUInt::CUInt(CUInt && source) :
	CStronglyTyped(std::move(source))
{
}

CUInt::CUInt(unsigned int val) : 
	CStronglyTyped()
{
	this->set(val);
}

CUInt::~CUInt()
{
}

void CUInt::set(unsigned int value)
{
	((CVariant*)this)->alloc(&value,sizeof(unsigned int));
}

unsigned int CUInt::get() const
{
	unsigned int value;
	((CVariant*)this)->getData(&value);
	return value;
}

CUInt::operator unsigned int()
{
	return this->get();
}
