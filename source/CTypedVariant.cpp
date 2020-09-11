#include "CTypedVariant.hpp"


void CTypedVariant::setTypeId(const char * typeId)
{
	this->m_TypeId = typeId;
}

void CTypedVariant::swap(CTypedVariant && var)
{
	std::swap(m_TypeId,var.m_TypeId);
	CVariant::move(std::move(var));
}

/**
 * Constructor
 */
CTypedVariant::CTypedVariant(const char * typeId,size_t size) : 
	CVariant(size),m_TypeId(typeId)
{
}

/**
 * Virtual Destructor
 */
CTypedVariant::~CTypedVariant()
{
}

/**
 * Copy Constructor
 */
CTypedVariant::CTypedVariant(const CTypedVariant & var,const char * typeId) : 
	CVariant(var),m_TypeId(typeId)
{
	if(typeId != nullptr && typeId != var.getTypeId())
		throw std::domain_error("Type Mismatch");
}

CTypedVariant & CTypedVariant::operator = (const CTypedVariant & var)
{
	this->copy(var);
	return *this;
}

/**
 * Move Constructor
 */
CTypedVariant::CTypedVariant(CTypedVariant && var,const char * typeId) :
	CVariant(std::move(var)),m_TypeId(typeId)
{
	if(typeId != nullptr && typeId != var.getTypeId())
		throw std::domain_error("Type Mismatch");
}
/**
 * Move Operator
 */
CTypedVariant & CTypedVariant::operator = (CTypedVariant && var)
{
	this->move(std::move(var));
	return *this;
}

const char * CTypedVariant::getTypeId() const
{
	return this->m_TypeId;
}

