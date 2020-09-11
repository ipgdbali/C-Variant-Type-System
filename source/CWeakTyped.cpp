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

// Copy Operator
CWeakTyped & CWeakTyped::operator = (const CWeakTyped & val)
{
	this->copy(val);
	return *this;
}

// Copy method
bool CWeakTyped::copy(const CTypedVariant & val)
{
	this->setTypeId(val.getTypeId());
	CVariant::copy(val);
	return true;
}

//
// Move Operation
//

// Move Constructor
CWeakTyped::CWeakTyped(CWeakTyped && val) :
	CTypedVariant(std::move(val),val.getTypeId())
{
}

// Move operator
CWeakTyped & CWeakTyped::operator = (CWeakTyped && val)
{
	this->move(std::move(val));
	return *this;
}

// Move method
bool CWeakTyped::move(CTypedVariant && val)
{
	CTypedVariant::swap(std::move(val));
	return true;
}

const char * CWeakTyped::getTypeId() const
{
	return CTypedVariant::getTypeId();
}
