#include "CTypeWrapper.hpp"

// Default Constructor
CTypeWrapper::CTypeWrapper()
{
}

//
// Copy Operation
//

// Copy Constructor
CTypeWrapper::CTypeWrapper(const CTypeWrapper & var)
{
}

CTypeWrapper::CTypeWrapper(const CWeakTyped & var)
{
}

CTypeWrapper::CTypeWrapper(const CTypedVariant & var)
{
}

// Copy Operator
CTypeWrapper & CTypeWrapper::operator = (const CTypeWrapper & var)
{
	return *this;
}

CTypeWrapper & CTypeWrapper::operator = (const CWeakTyped & var)
{
	return *this;
}

CTypeWrapper & CTypeWrapper::operator = (const CTypedVariant & var)
{
	return *this;
}

// Copy Method
void CTypeWrapper::copy(const CTypedVariant & var)
{
}

//
// Move Operation
//

// Move Constructor
CTypeWrapper::CTypeWrapper(CTypeWrapper && var)
{
}

CTypeWrapper::CTypeWrapper(CWeakTyped && var)
{
}

CTypeWrapper::CTypeWrapper(CTypedVariant && var)
{
}

// Copy Operator
CTypeWrapper & CTypeWrapper::operator = (CTypeWrapper && var)
{
	return *this;
}

CTypeWrapper & CTypeWrapper::operator = (CWeakTyped && var)
{
	return *this;
}

CTypeWrapper & CTypeWrapper::operator = (CTypedVariant && var)
{
	return *this;
}

// Copy Method
void CTypeWrapper::move(CTypedVariant && var)
{
}

#define type_support_impl(t) \
CTypeWrapper::CTypeWrapper(const t & val) : \
	CWeakTyped(val) \
{\
}\
\
CTypeWrapper & CTypeWrapper::operator = (const t & val)\
{\
	this->copy(val);\
	return *this;\
}\
\
CTypeWrapper::CTypeWrapper(t && val)\
{\
	this->move(std::move(val));\
}\
\
CTypeWrapper & CTypeWrapper::operator = (t && val)\
{\
	this->move(std::move(val));\
	return *this;\
}\
\
CTypeWrapper::CTypeWrapper(const t::simple_type val) : \
	CWeakTyped((t)val) \
{\
}\
\
CTypeWrapper & CTypeWrapper::operator = (const t::simple_type val)\
{\
	this->operator = ((t)val);\
	return *this;\
}

type_support_impl(CChar)
type_support_impl(CUChar)
type_support_impl(CShort)
type_support_impl(CUShort)
type_support_impl(CInt)
type_support_impl(CUInt)
type_support_impl(CFloat)
type_support_impl(CDouble)
type_support_impl(CBool)
