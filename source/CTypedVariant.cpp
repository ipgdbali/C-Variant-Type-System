#include "CTypedVariant.hpp"

CTypedVariant::CTypedVariant(const char * typeId,size_t size) : 
	CVariant(size),m_TypeId(typeId)
{
}

CTypedVariant::CTypedVariant(const CTypedVariant & var,const char * typeId) : 
	CVariant(var),m_TypeId(typeId)
{
	if(typeId != nullptr && typeId != var.getTypeId())
		throw std::domain_error("Type Mismatch");
}


CTypedVariant::CTypedVariant(CTypedVariant && var,const char * typeId) :
	CVariant(std::move(var)),m_TypeId(nullptr)
{
	if(typeId == nullptr || typeId == var.getTypeId())
		this->m_TypeId = typeId;
	else
		throw std::domain_error("Type Mismatch");
}

CTypedVariant::~CTypedVariant()
{
}

void CTypedVariant::setTypeId(const char * typeId)
{
	this->m_TypeId = typeId;
}

bool CTypedVariant::copy(const CTypedVariant & var,bool reverseType)
{
	if(this->getTypeId() != nullptr && reverseType && this->getTypeId() != var.getTypeId())
		return false;
	else
	{
		CVariant::copy(var);
		this->m_TypeId = var.getTypeId();
		return true;
	}
}

bool CTypedVariant::move(CTypedVariant && var,bool reverseType)
{
	if(this->getTypeId() != nullptr && reverseType && this->getTypeId() != var.getTypeId())
		return false;
	else
	{
		CVariant::move(std::move(var));
		std::swap(this->m_TypeId,var.m_TypeId);
		return true;
	}
}

const char * CTypedVariant::getTypeId() const
{
	return this->m_TypeId;
}

