#include "CInt.hpp"

CInt::CInt(const CInt & source) : 
	CStronglyTyped(source)
{
}

CInt::CInt(CInt && source) :
	CStronglyTyped(std::move(source))
{
}

CInt::CInt(int val) : 
	CStronglyTyped()
{
	this->set(val);
}

CInt::~CInt()
{
}

void CInt::set(int value)
{
	((CVariant*)this)->alloc(&value,sizeof(int));
}

int CInt::get() const
{
	int value;
	((CVariant*)this)->getData(&value);
	return value;
}

CInt::operator int()
{
	return this->get();
}
