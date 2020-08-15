#include "CTypedVariant.hpp"

CTypedVariant::CTypedVariant(const char * typeId,size_t size) : 
	CVariant(size),m_TypeId(typeId)
{
}

CTypedVariant::CTypedVariant(const CTypedVariant & var,const char * TypeId)
{
	this->copy(var,false);
}


CTypedVariant::CTypedVariant(CTypedVariant && var,const char * TypeId)
{
	this->move(std::move(var),false);
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

