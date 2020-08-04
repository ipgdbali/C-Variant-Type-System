#include "CShort.hpp"

CShort::CShort() : CShort(0)
{
}

CShort::CShort(short val) :
	CTypedVariant("DT_INT",sizeof(short))
{
	this->set(val);
}

void CShort::set(short val)
{
	if(this->getPData() == nullptr && this->getSize() == 0)
		this->alloc(sizeof(short));
	this->write(&val);
}

short CShort::get()
{
	short dummy;
	this->read(&dummy);
	return dummy;
}

CShort & CShort::operator = (short val)
{
	this->set(val);
	return *this;
}

CShort::operator short ()
{
	return this->get();
}

