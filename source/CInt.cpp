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
	if(this->getPData() == nullptr && this->getSize() == 0)
		this->alloc(sizeof(int));
	this->write(&val);
}

int CInt::get()
{
	int dummy;
	this->read(&dummy);
	return dummy;
}

CInt & CInt::operator = (int val)
{
	this->set(val);
	return *this;
}

CInt::operator int ()
{
	return this->get();
}

