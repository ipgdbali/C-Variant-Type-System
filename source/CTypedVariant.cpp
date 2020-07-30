#include "CTypedVariant.hpp"

void CTypedVariant::setDataTypeId(const char * dataTypeId)
{
	this->m_DataTypeId = dataTypeId;
}

CTypedVariant::CTypedVariant() :
	m_DataTypeId(nullptr)
{
}

CTypedVariant::CTypedVariant(const CTypedVariant &typedVariant) :
	CVariant(typedVariant),m_DataTypeId(typedVariant.m_DataTypeId)
{
}

CTypedVariant::CTypedVariant(CTypedVariant && value) : 
	CVariant(std::move(value)),m_DataTypeId(std::move(value.m_DataTypeId))
{
	value.m_DataTypeId = nullptr;
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
	this->m_DataTypeId = value.m_DataTypeId;
}

void CTypedVariant::set(CTypedVariant && value)
{
	((CVariant*)this)->set(std::move(value));
	this->m_DataTypeId = value.m_DataTypeId;
	value.m_DataTypeId = 0;
}

const char * CTypedVariant::getDataTypeId() const
{
	return this->m_DataTypeId;
}
