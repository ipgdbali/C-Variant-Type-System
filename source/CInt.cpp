#include "CInt.hpp"

CInt::CInt()
{
	this->setDataType(10);
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
	CVariant::set(&value,sizeof(int));
}

int CInt::get()
{
	int value;
	CVariant::get(&value);
	return value;
}
