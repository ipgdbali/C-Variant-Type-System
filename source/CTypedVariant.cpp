#include "CTypedVariant.hpp"

CTypedVariant::CTypedVariant(const char * typeId,size_t size) : 
	m_DataTypeId(typeId),CVariant(size)
{
}

CTypedVariant::~CTypedVariant()
{
}

const char * CTypedVariant::getTypeId() const
{
	return this->m_DataTypeId;
}

