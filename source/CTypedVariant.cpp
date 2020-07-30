#include "CTypedVariant.hpp"

void CTypedVariant::setDataType(size_t dataType)
{
	this->m_DataType = dataType;
}

CTypedVariant::CTypedVariant() :
	m_DataType(0)
{
}

CTypedVariant::CTypedVariant(const CTypedVariant &typedVariant) :
	CVariant(typedVariant),m_DataType(typedVariant.m_DataType)
{
}

CTypedVariant::CTypedVariant(CTypedVariant && value) : 
	CVariant(std::move(value)),m_DataType(std::move(value.m_DataType))
{
	value.m_DataType = 0;
}

CTypedVariant & CTypedVariant::operator = (const CTypedVariant & value)
{
	this->set(value);
	return *this;
}

CTypedVariant & CTypedVariant::operator = (CTypedVariant && value)
{
	this->set(std::move(value));
	return *this;
}

void CTypedVariant::set(const CTypedVariant & value)
{
	((CVariant*)this)->set(value);
	this->m_DataType = value.m_DataType;
}

void CTypedVariant::set(CTypedVariant && value)
{
	((CVariant*)this)->set(std::move(value));
	this->m_DataType = value.m_DataType;
	value.m_DataType = 0;
}

size_t CTypedVariant::getDataTypeId() const
{
	return this->m_DataType;
}
