#include "CInt.hpp"

void CInt::set(void * value)
{
	((CVariant*)this)->alloc(value,sizeof(int));
}

CInt::CInt()
{
	this->setDataType(CInt::getClassId());
}

CInt::CInt(const CTypedVariant & typedVariant) : 
	CInt()
{
	if(typedVariant.getDataType() == CInt::getClassId())
		((CTypedVariant*)this)->set(typedVariant);
	else
		throw std::invalid_argument("Wrong Class");
}

CInt::CInt(CTypedVariant && typedVariant)
{
	if(typedVariant.getDataType() == CInt::getClassId())
		((CTypedVariant*)this)->set(std::move(typedVariant));
	else
		throw std::invalid_argument("Wrong Class");
}

CInt & CInt::operator = (const CTypedVariant & value)
{
	if(value.getDataType() == CInt::getClassId())
		((CTypedVariant*)this)->set(value);
	else
		throw std::invalid_argument("Wrong Class");
	return *this;
}

CInt & CInt::operator = (CTypedVariant && value)
{
	if(value.getDataType() == CInt::getClassId())
		((CTypedVariant*)this)->set(std::move(value));
	else
		throw std::invalid_argument("Wrong Class");
	return *this;
}

CInt::CInt(int val) : CInt()
{
	this->set(val);
}

CInt::~CInt()
{
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

CInt::operator int()
{
	return this->get();
}
