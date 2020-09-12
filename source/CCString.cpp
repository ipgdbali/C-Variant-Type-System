#include "CCString.hpp"

CCString::CCString() : CStrongTyped(TYPE_ID,0)
{
}

// Copy Constructor
CCString::CCString(const CCString & var) :
	CStrongTyped(var)
{
}

CCString::CCString(const CStrongTyped & var) :
	CStrongTyped(var,TYPE_ID)
{
}

CCString::CCString(const CTypedVariant & var) :
	CStrongTyped(var,TYPE_ID)
{
}

CCString::CCString(CCString && val) : CStrongTyped(std::move(val))
{
}

CCString::CCString(const char * val) : CStrongTyped(TYPE_ID,0)
{
	this->set(val);
}

void CCString::set(const char * val)
{
	this->deAlloc();
	this->alloc(strlen(val) + 1);
	this->write(val);
}

CCString & CCString::operator = (const char * val)
{
	this->set(val);
	return * this;
}

void CCString::get(char * val)
{
	this->read(val);
}

size_t CCString::length() const
{
	return this->getSize() - 1;
}

const char * const CCString::TYPE_ID = "DT_STRING";
