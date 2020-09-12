#include "CCString.hpp"

CCString::CCString() : CSimpleType()
{
}

// Copy Constructor
CCString::CCString(const CCString & var) :
	CSimpleType(var)
{
}

CCString::CCString(const CSimpleType<char*> & var) :
	CSimpleType(var)
{
}

CCString::CCString(const CStrongTyped & var) :
	CSimpleType(var)
{
}

CCString::CCString(const CTypedVariant & var) :
	CSimpleType(var)
{
}

CCString::CCString(CCString && val) : CSimpleType(std::move(val))
{
}

CCString::CCString(const char * val) : CSimpleType()
{
	this->set(val);
}

bool CCString::set(const char * val)
{
	this->deAlloc();
	this->alloc(strlen(val) + 1);
	return this->write(val);
}

CCString & CCString::operator = (const char * val)
{
	this->set(val);
	return * this;
}

bool CCString::get(char ** val)
{
	return this->read(val);
}

size_t CCString::length() const
{
	return this->getSize() - 1;
}
