#include "CStrongTyped.hpp"

//
// Copy Operation
//

// Copy Constructor
CStrongTyped::CStrongTyped(const CStrongTyped & var,const char * typeId) :
	CTypedVariant(var,typeId)
{
}

CStrongTyped::CStrongTyped(const CTypedVariant & var,const char * typeId) :
	CTypedVariant(var,typeId)
{
}

// Copy Operator
CStrongTyped & CStrongTyped::operator = (const CStrongTyped & var)
{
	this->copy(var);
	return *this;
}

CStrongTyped & CStrongTyped::operator = (const CTypedVariant & var)
{
	this->copy(var);
	return *this;
}

// Copy method
bool CStrongTyped::copy(const CTypedVariant & var)
{
	if(this->getTypeId() == nullptr)
	{
		this->setTypeId(var.getTypeId());
		CVariant::copy(var);
		return true;
	}
	else
	if (
			this->getTypeId() == var.getTypeId() 
			|| 
			strcmp(this->getTypeId(),var.getTypeId()) == 0
	)
	{
		CVariant::copy(var);
		return true;
	}
	else
	{
		return false;
	}
}

//
// Move Operation
//

// Move Constructor
CStrongTyped::CStrongTyped(CStrongTyped && var,const char * typeId) 
	: CTypedVariant(std::move(var),typeId)
{
}

CStrongTyped::CStrongTyped(CTypedVariant && var,const char * typeId) 
	: CTypedVariant(std::move(var),typeId)
{
}

// Move operator
CStrongTyped & CStrongTyped::operator = (CStrongTyped && var)
{
	this->move(std::move(var));
	return *this;
}

CStrongTyped & CStrongTyped::operator = (CTypedVariant && var)
{
	this->move(std::move(var));
	return *this;
}

// Move method
bool CStrongTyped::move(CTypedVariant && var)
{
	if(this->getTypeId() == nullptr || this->getTypeId() == var.getTypeId())
	{
		CTypedVariant::swap(std::move(var));
		return true;
	}
	else
	{
		return false;
	}
}

// Constructor
CStrongTyped::CStrongTyped(const char * typeId,size_t size) 
	: CTypedVariant(typeId,size)
{
}

