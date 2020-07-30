#include "CVariant.hpp"

/**
 * Default Constructor
 */
CVariant::CVariant() : m_pData(nullptr),m_DataSize(0)
{
}

/**
 * Virtual Destructor
 */
CVariant::~CVariant()
{
	clear();
}

/**
 * Copy Constructor
 */
CVariant::CVariant(const CVariant & source) : CVariant()
{
	this->set(source);
}

/**
 * Move Constructor
 */
CVariant::CVariant(CVariant && source) : CVariant()
{
	this->set(std::move(source));
}

/**
 * Allocating Constructor
 */
CVariant::CVariant(const void * pData,size_t dataSize):CVariant()
{
	this->alloc(pData,dataSize);
}

/**
 * Copy Operator
 */
CVariant & CVariant::operator = (const CVariant & source)
{
	this->set(source);
	return *this;
}

/**
 * Move Operator
 */
CVariant& CVariant::operator = (CVariant && source)
{
	this->set(std::move(source));
	return *this;
}

void CVariant::set(const CVariant & source)
{
	this->alloc((const void *)source.m_pData,source.m_DataSize);
}

void CVariant::set(CVariant && source)
{
	this->clear();
	this->m_pData = source.m_pData;
	this->m_DataSize = source.m_DataSize;
	source.m_pData = nullptr;
	source.m_DataSize = 0;
}

void CVariant::alloc(const void * pData,size_t dataSize)
{
	this->clear();
	this->m_DataSize = dataSize;
	this->m_pData = malloc(this->m_DataSize);
	memcpy(m_pData,pData,this->m_DataSize);
}

void CVariant::write(const char * pData)
{
	memcpy(this->m_pData,pData,this->m_DataSize);
}


size_t CVariant::getSize()
{
	return this->m_DataSize;
}

bool CVariant::getData(void * pData)
{
	if(!this->isNull())
	{
		memcpy(pData,m_pData,this->m_DataSize);
		return true;
	}
	else
		return false;
}

void CVariant::clear()
{
	if(!this->isNull())
		free(this->m_pData);
	this->m_pData = nullptr;
	this->m_DataSize = 0;
}

bool CVariant::isNull()
{
	if(this->m_pData == nullptr && this->m_DataSize == 0)
		return true;
	else
		return false;
}
