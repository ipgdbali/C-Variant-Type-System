#include "CVariant.hpp"

CVariant::CVariant() : m_pData(nullptr),m_DataSize(0)
{
}

CVariant::~CVariant()
{
	clear();
}

CVariant::CVariant(const CVariant & value) : CVariant()
{
	this->set(value.m_pData,value.m_DataSize);
}

CVariant & CVariant::operator = (CVariant & value)
{
	this->set(value);
	return *this;
}

CVariant::CVariant(CVariant && value) :
	m_pData(std::move(value.m_pData)),
	m_DataSize(std::move(value.m_DataSize))

{
	value.m_pData = nullptr;
	this->m_DataSize = 0;
}

CVariant& CVariant::operator = (CVariant && value)
{
	this->clear();
	this->m_pData = std::move(value.m_pData);
	value.m_pData = nullptr;
	this->m_DataSize = std::move(value.m_DataSize);
	this->m_DataSize = 0;

	return *this;
}

CVariant::CVariant(const void * pData,size_t dataSize):CVariant()
{
	this->set(pData,dataSize);
}

void CVariant::set(const CVariant & value)
{
	this->set(value.m_pData,value.m_DataSize);
}

void CVariant::set(const void * pData,size_t dataSize)
{
	if(pData == nullptr)
		throw std::invalid_argument("pData cannot be null");

	if(dataSize == 0)
		throw std::invalid_argument("dataSize cannot be null");

	//clear previous old value
	this->clear();

	this->m_DataSize = dataSize;
	this->m_pData = malloc(this->m_DataSize);
	memcpy(m_pData,pData,this->m_DataSize);
}

size_t CVariant::getSize()
{
	return this->m_DataSize;
}

void CVariant::get(void * pData)
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
	{
		free(this->m_pData);
		this->m_pData = nullptr;
		this->m_DataSize = 0;
	}
}
