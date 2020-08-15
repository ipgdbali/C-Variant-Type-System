#include "CCString.hpp"

CCString::CCString() : CCString(nullptr)
{
}

CCString::CCString(const char * val) :
	CStrongTyped("DT_CSTRING")
{
	this->set(val);
}

CCString::CCString(const CStrongTyped & val) :
	CStrongTyped(val,"DT_CSTRING")
{
}

CCString::CCString(CStrongTyped && val) :
	CStrongTyped(val,"DT_CSTRING")
{
}

void CCString::set(const char * val)
{
	this->deAlloc();
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

