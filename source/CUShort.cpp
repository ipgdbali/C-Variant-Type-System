#include "CUShort.hpp"

CUShort::CUShort() : CUShort(0)
{
}

CUShort::CUShort(unsigned short val) :
	CTypedVariant("DT_USHORT",sizeof(unsigned short))
{
	this->set(val);
}

void CUShort::set(unsigned short val)
{
	if(this->getPData() == nullptr && this->getSize() == 0)
		this->alloc(sizeof(unsigned short));
	this->write(&val);
}

unsigned short CUShort::get()
{
	unsigned short dummy;
	this->read(&dummy);
	return dummy;
}

CUShort & CUShort::operator = (unsigned short val)
{
	this->set(val);
	return *this;
}

CUShort::operator unsigned short ()
{
	return this->get();
}

