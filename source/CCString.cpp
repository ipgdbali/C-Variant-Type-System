#include "CCString.hpp"

CCString::CCString() : CCString(nullptr)
{
}

CCString::CCString(const char * val) :
	CTypedVariant("DT_CSTRING")
{
	this->set(val);
}

void CCString::set(const char * val)
{
	this->alloc(strlen(val) + 1);
	this->write(val);
}

void CCString::get(char * val)
{
	this->read(val);
}

size_t CCString::length() const
{
	return this->getSize() - 1;
}

CCString::operator const char *()
{
	return (const char *)this->getPData();
}

