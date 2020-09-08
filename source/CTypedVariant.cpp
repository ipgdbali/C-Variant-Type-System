#include "CTypedVariant.hpp"


void CTypedVariant::setTypeId(const char * typeId)
{
	this->m_TypeId = typeId;
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

/**
 * Move Constructor
 */
CTypedVariant::CTypedVariant(CTypedVariant && var,const char * typeId) :
	CVariant(std::move(var)),m_TypeId(typeId)
{
	if(typeId != nullptr && typeId != var.getTypeId())
		throw std::domain_error("Type Mismatch");
}

const char * CTypedVariant::getTypeId() const
{
	return this->m_TypeId;
}

