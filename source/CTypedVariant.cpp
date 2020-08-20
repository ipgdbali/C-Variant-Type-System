#include "CTypedVariant.hpp"

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

/**
 * Move Constructor
 */
CTypedVariant::CTypedVariant(CTypedVariant && var,const char * typeId) :
	CVariant(std::move(var)),m_TypeId(typeId)
{
	if(typeId != nullptr && typeId != var.getTypeId())
		throw std::domain_error("Type Mismatch");
}

bool CTypedVariant::copy(const CTypedVariant & var,bool reverseType)
{
	if(this->getTypeId() != nullptr && reverseType && this->getTypeId() != var.getTypeId())
		return false;
	else
	{
		CVariant::copy(var);
		this->m_TypeId = var.getTypeId();
		return true;
	}
}

bool CTypedVariant::move(CTypedVariant && var,bool reverseType)
{
	if(this->getTypeId() != nullptr && reverseType && this->getTypeId() != var.getTypeId())
		return false;
	else
	{
		CVariant::move(std::move(var));
		std::swap(this->m_TypeId,var.m_TypeId);
		return true;
	}
}


void CTypedVariant::setTypeId(const char * typeId)
{
	this->m_TypeId = typeId;
}

const char * CTypedVariant::getTypeId() const
{
	return this->m_TypeId;
}

