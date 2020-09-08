#include "CWeakTyped.hpp"

CWeakTyped::CWeakTyped() : 
	CTypedVariant(nullptr,0)
{
}

//
// Copy Constructor
//

// Copy Constructor
CWeakTyped::CWeakTyped(const CWeakTyped & val) :
	CTypedVariant(val,val.getTypeId())
{
}

CWeakTyped::CWeakTyped(const CTypedVariant & val) :
	CTypedVariant(val,val.getTypeId())
{
}

// Copy Operator
CWeakTyped & CWeakTyped::operator = (const CWeakTyped & val)
{
	CWeakTyped::copy(val);
	return *this;
}

CWeakTyped & CWeakTyped::operator = (const CTypedVariant & val)
{
	CWeakTyped::copy(val);
	return *this;
}

// Copy method
void CWeakTyped::copy(const CTypedVariant & val)
{
	CTypedVariant::copy(val,false);
}

//
// Move Operation
//

// Move Constructor
CWeakTyped::CWeakTyped(CWeakTyped && val) :
	CTypedVariant(std::move(val),val.getTypeId())
{
}
CWeakTyped::CWeakTyped(CTypedVariant && val) :
	CTypedVariant(std::move(val),val.getTypeId())
{
}

// Move operator
CWeakTyped & CWeakTyped::operator = (CWeakTyped && val)
{
	this->move(std::move(val));
	return *this;
}
CWeakTyped & CWeakTyped::operator = (CTypedVariant && val)
{
	this->move(std::move(val));
	return *this;
}

// Move method
void CWeakTyped::move(CTypedVariant && val)
{
	CTypedVariant::move(std::move(val),false);
}

const char * CWeakTyped::getTypeId() const
{
	return CTypedVariant::getTypeId();
}
