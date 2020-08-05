#include "CTypedVariant.hpp"

CTypedVariant::CTypedVariant(const char * const typeId,size_t size) : 
	CVariant(size),m_DataTypeId(typeId)
{
}

CTypedVariant::CTypedVariant() : CVariant()
{
	this->m_DataTypeId = nullptr;
}

CTypedVariant::CTypedVariant(const CTypedVariant & var,const char * TypeId)
{
	if(TypeId == nullptr || (TypeId != nullptr && TypeId == var.getTypeId()))
		this->copy(var);
	else
		throw domain_error("Type Mismatch");
}

CTypedVariant::CTypedVariant(CTypedVariant && var,const char * TypeId)
{
	if(TypeId == nullptr || (TypeId != nullptr && TypeId == var.getTypeId()))
		this->move(std::move(var));
	else
		throw domain_error("Type Mismatch");
}

CTypedVariant::~CTypedVariant()
{
}

CTypedVariant & CTypedVariant::operator = (const CTypedVariant & var)
{
	if(
		this->getTypeId() == nullptr || 
		(this->getTypeId() != nullptr && this->getTypeId() == var.getTypeId())
	)
		this->copy(var);
	else
		throw domain_error("Type Mismatch");

	return *this;
}

CTypedVariant & CTypedVariant::operator = (CTypedVariant && var)
{
	if(
		this->getTypeId() == nullptr || 
		(this->getTypeId() != nullptr && this->getTypeId() == var.getTypeId())
	)
		this->move(std::move(var));
	else
		throw domain_error("Type Mismatch");

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
	std::swap(m_DataTypeId,var.m_DataTypeId);
}

