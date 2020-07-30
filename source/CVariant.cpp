#include "CVariant.hpp"

/**
 * Default Constructor
 */
CVariant::CVariant(size_t size) :
	m_Size(size)
{
	m_pData = calloc(1,size);
}

/**
 * Virtual Destructor
 */
CVariant::~CVariant()
{
	free(m_pData);
	m_pData = nullptr;
	m_Size = 0;
}

void CVariant::write(const void * pData)
{
	memcpy(this->m_pData,pData,this->m_Size);
}

void CVariant::read(void * pData)
{
	memcpy(pData,m_pData,this->m_Size);
}

size_t CVariant::getSize() const
{
	return this->m_Size;
}
