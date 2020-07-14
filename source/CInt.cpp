#include "CInt.hpp"

CInt::CInt()
{
	this->setDataType(CInt::getClassId());
}

CInt::CInt(CTypedVariant & typedVariant) : 
	CInt()
{
	if(typedVariant.getDataType() == this->getDataType())
	{
		int value;
		typedVariant.get(&value);
		this->set(value);
	}
	else
	{
		throw std::domain_error("Data Type mismatch");
	}
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
	((CVariant*)this)->set(&value,sizeof(int));
}

int CInt::get()
{
	int value;
	CVariant::get(&value);
	return value;
}
