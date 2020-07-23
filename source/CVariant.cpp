#include "CVariant.hpp"

CVariant::CVariant() : m_pData(nullptr),m_DataSize(0)
{
}

CVariant::~CVariant()
{
	clear();
}

CVariant::CVariant(const CVariant & source) : CVariant()
{
	this->set(source);
}

CVariant::CVariant(CVariant && source) : CVariant()
{
	this->set(std::move(source));
}

CVariant::CVariant(const void * pData,size_t dataSize):CVariant()
{
	this->alloc(pData,dataSize);
}

CVariant::CVariant(void * pData,size_t dataSize):CVariant()
{
	this->copy(pData,dataSize);
}

CVariant & CVariant::operator = (const CVariant & source)
{
	this->set(source);
	return *this;
}

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
	this->copy(source.m_pData,source.m_DataSize);
	source.m_pData = nullptr;
	source.m_DataSize = 0;
}

void CVariant::alloc(const void * pData,size_t dataSize)
{
	if(pData == nullptr || dataSize == 0)
		return;

	this->clear();
	this->m_DataSize = dataSize;
	this->m_pData = malloc(this->m_DataSize);
	memcpy(m_pData,pData,this->m_DataSize);
}

//cannot be join with alloc
//since m_pData is not const
void CVariant::copy(void * pData,size_t dataSize)
{
	if(pData == nullptr || dataSize == 0)
		return;

	this->clear();
	this->m_DataSize = dataSize;
	this->m_pData = pData;
}

size_t CVariant::getSize()
{
	return this->m_DataSize;
}

void CVariant::getData(void * pData)
{
	if(pData != nullptr)
	{
		if(m_pData != nullptr && this->m_DataSize != 0)
			memcpy(pData,m_pData,this->m_DataSize);
		else
			throw std::domain_error("Value is not yet set");
	}
	else
		throw std::invalid_argument("pData cannot be null");
}

void CVariant::clear()
{
	if(this->m_pData != nullptr)
		free(this->m_pData);
	this->m_pData = nullptr;
	this->m_DataSize = 0;
}
