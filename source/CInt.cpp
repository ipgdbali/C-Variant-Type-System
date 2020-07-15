#include "CInt.hpp"

CInt::CInt(const CTypedVariant & source) : 
	CStronglyTyped(source)
{
}

CInt::CInt(CTypedVariant && source) :
	CStronglyTyped(std::move(source))
{
}

CInt & CInt::operator = (const CTypedVariant & value)
{
	CStronglyTyped * parent = (CStronglyTyped*)this;
	parent->operator=(value);
	return *this;
}

CInt & CInt::operator = (CTypedVariant && value)
{
	CStronglyTyped * parent = (CStronglyTyped*)this;
	parent->operator=(value);
	return *this;
}

CInt::CInt(int val) : CInt()
{
	this->set(val);
}

CInt::~CInt()
{
}

void CInt::set(void * pSource)
{
	((CVariant*)this)->alloc(pSource,sizeof(int));
}

void CInt::set(int value)
{
	this->set((void*)&value);
}

int CInt::get() const
{
	int value;
	((CVariant*)this)->getData(&value);
	return value;
}

size_t CInt::getClassId()
{
	return 10;
}

CInt::operator int()
{
	return this->get();
}
