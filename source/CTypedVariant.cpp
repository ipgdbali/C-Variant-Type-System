#include "CTypedVariant.hpp"

bool CTypedVariant::write(const void * pData)
{
	return ((CVariant*)this)->write(pData);
}

bool CTypedVariant::read(void * pData)
{
	return ((CVariant*)this)->read(pData);
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

CTypedVariant::CTypedVariant(const char * typeId,size_t size) : 
	CVariant(size),m_DataTypeId(typeId)
{
}

CTypedVariant::~CTypedVariant()
{
}

const char * CTypedVariant::getTypeId() const
{
	return this->m_DataTypeId;
}

