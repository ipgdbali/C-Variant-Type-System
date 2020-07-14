#include "CTypedVariant.hpp"

void CTypedVariant::setDataType(size_t dataType)
{
	this->m_DataType = dataType;
}

CTypedVariant::CTypedVariant() :
	m_bChangeDataType(true),m_DataType(0)
{
}

CTypedVariant::CTypedVariant(const CTypedVariant &typedVariant) :
	CVariant(typedVariant),
	m_DataType(typedVariant.m_DataType),
	m_bChangeDataType(typedVariant.m_bChangeDataType)
{
}

CTypedVariant & CTypedVariant::operator = (const CTypedVariant & value)
{
	if(this->getDataType() == value.getDataType() || this->getIsFlexible())
	{
		//From CVariant Method
		this->set(value);

		// This method
		this->setDataType(value.getDataType());
	}
	else
	{
		throw std::domain_error("Data Type mismatch on flexbility is false");
	}
	return *this;
}

CTypedVariant::CTypedVariant(CTypedVariant && value) : 
	CVariant(std::move(value)),
	m_DataType(std::move(value.m_DataType)),
	m_bChangeDataType(std::move(value.m_bChangeDataType))
{
}

CTypedVariant & CTypedVariant::operator = (CTypedVariant && value)
{
	this->clear();

	this->m_DataType = std::move(value.m_DataType);
	this->m_bChangeDataType = std::move(value.m_bChangeDataType);
	return *this;
}

void CTypedVariant::setIsFlexible(bool flexible)
{
	this->m_bChangeDataType = flexible;
}

bool CTypedVariant::getIsFlexible() const
{
	return this->m_bChangeDataType;
}

size_t CTypedVariant::getDataType() const
{
	return this->m_DataType;
}
