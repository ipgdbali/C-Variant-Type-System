#include "CTypedVariant.hpp"

CTypedVariant::CTypedVariant(const char * const typeId,size_t size) : 
	CVariant(size),m_DataTypeId(typeId)
{
}

CTypedVariant::CTypedVariant() : CVariant()
{
	this->m_DataTypeId = nullptr;
}

CTypedVariant::CTypedVariant(const CTypedVariant & var)
{
	this->copy(var);
}

CTypedVariant::CTypedVariant(CTypedVariant && var)
{
	this->move(std::move(var));
}

CTypedVariant::~CTypedVariant()
{
}

CTypedVariant & CTypedVariant::operator = (const CTypedVariant & var)
{
	this->copy(var);
	return *this;
}

CTypedVariant & CTypedVariant::operator = (CTypedVariant && var)
{
	this->move(std::move(var));
	return *this;
}

const char * CTypedVariant::getTypeId() const
{
	return this->m_DataTypeId;
}

void CTypedVariant::copy(const CTypedVariant & var)
{
	((CVariant*)this)->copy(var);
	this->m_DataTypeId = var.m_DataTypeId;
}

void CTypedVariant::move(CTypedVariant && var)
{
	((CVariant*)this)->move(std::move(var));
	this->m_DataTypeId = var.m_DataTypeId;
	var.m_DataTypeId = nullptr;
}

