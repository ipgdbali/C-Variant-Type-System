#include "CStrongTyped.hpp"

CStrongTyped::CStrongTyped(const char * typeId,size_t size) 
	: CTypedVariant(typeId,size)
{
}

// Copy Constructor
CStrongTyped::CStrongTyped(const CTypedVariant & var,const char * typeId) :
	CTypedVariant(var,typeId)
{
}

// Copy Operator
CStrongTyped & CStrongTyped::operator = (const CTypedVariant & var)
{
	this->copy(var);
	return *this;
}

// Copy method
void CStrongTyped::copy(const CTypedVariant & var)
{
	if(!CTypedVariant::copy(var,true))
		throw domain_error("Type Mismatch");
}

// Move Constructor
CStrongTyped::CStrongTyped(CTypedVariant && var,const char * typeId) 
	: CTypedVariant(std::move(var),typeId)
{
}

// Move operator
CStrongTyped & CStrongTyped::operator = (CTypedVariant && var)
{
	this->move(std::move(var));
	return *this;
}

// Move method
void CStrongTyped::move(CTypedVariant && var)
{
	if(!CTypedVariant::move(std::move(var),true))
		throw domain_error("Type Mismatch");
}

void CStrongTyped::setTypeId(const char * typeId)
{
	CTypedVariant::setTypeId(typeId);
}

const char * CStrongTyped::getTypeId() const
{
	return CTypedVariant::getTypeId();
}
