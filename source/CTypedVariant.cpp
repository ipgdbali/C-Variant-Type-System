#include "CTypedVariant.hpp"

CTypedVariant::CTypedVariant(const char * typeId,size_t size)
{
	this->alloc(typeId,size);
}

bool CTypedVariant::alloc(const char * typeId,size_t size)
{
	if(typeId != nullptr)
		this->m_DataTypeId = typeId;
	else
		return false;
	return CVariant::alloc(size);
}

void CTypedVariant::deAlloc()
{
	this->m_DataTypeId = nullptr;
	CVariant::deAlloc();
}

const char * CTypedVariant::getTypeId() const
{
	return this->m_DataTypeId;
}

