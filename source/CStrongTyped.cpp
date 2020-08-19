#include "CStrongTyped.hpp"

CStrongTyped::CStrongTyped(const char * typeId,size_t size) 
	: CTypedVariant(typeId,size)
{
}

CStrongTyped::CStrongTyped(const CTypedVariant & var,const char * typeId) :
	CTypedVariant(var,typeId)
{
}

CStrongTyped & CStrongTyped::operator = (const CTypedVariant & var)
{
	this->copy(var);
	return *this;
}

CStrongTyped::CStrongTyped(const CStrongTyped & var,const char * typeId) 
	: CTypedVariant(var,typeId)
{
}

CStrongTyped & CStrongTyped::operator = (const CStrongTyped & var)
{
	this->copy(var);
	return *this;
}

void CStrongTyped::copy(const CTypedVariant & var)
{
	if(!CTypedVariant::copy(var,true))
		throw domain_error("Type Mismatch");
}

CStrongTyped::CStrongTyped(CTypedVariant && var,const char * typeId) 
	: CTypedVariant(std::move(var),typeId)
{
}

CStrongTyped & CStrongTyped::operator = (CTypedVariant && var)
{
	this->move(std::move(var));
	return *this;
}

CStrongTyped::CStrongTyped(CStrongTyped && var,const char * typeId) 
	: CTypedVariant(std::move(var),typeId)
{
}

CStrongTyped & CStrongTyped::operator = (CStrongTyped && var)
{
	this->move(std::move(var));
	return *this;
}

void CStrongTyped::move(CTypedVariant && var)
{
	if(!CTypedVariant::move(std::move(var),true))
		throw domain_error("Type Mismatch");
}

void CStrongTyped::setTypeId(const char * typeId)
{
	CTypedVariant::setTypeId(typeId);
}
