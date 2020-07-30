#include "CTypedVariantAdapter.hpp"

map<const char *,size_t> CTypedVariantAdapter::m_MapperStringIdToId;

size_t CTypedVariantAdapter::getTypeVariantId(const char * strIdName)
{
	map<const char *,size_t>::iterator it;
	it = m_MapperStringIdToId.find(strIdName);
	if(it == m_MapperStringIdToId.end())
		m_MapperStringIdToId[strIdName] = m_MapperStringIdToId.size();
	return m_MapperStringIdToId[strIdName];
}

CTypedVariantAdapter::CTypedVariantAdapter(
		CTypedVariant & typedVariant,
		const char * pStringTypedVariant,
		bool typeChangeable):
	m_TypedVariant(typedVariant)
{
	this->m_TypeVariantId = CTypedVariantAdapter::getTypeVariantId(pStringTypedVariant);	
	this->m_TypeChangeable = typeChangeable;
	if(this->m_TypeChangeable)
	{
		//if data type is different deallo and alloc
		if(typedVariant.getDataTypeId() != this->getTypeVariantId())
		{
			typedVariant.deAlloc();
			typedVariant.alloc(sizeof(int));
		}
	}
	else
	{
		//if data type is not changeable

		//if data type is not set
		if(typedVariant.getDataTypeId() == 0)
			typedVariant.alloc(sizeof(int));
		else
		if(typedVariant.getDataTypeId() != this->getTypeVariantId())
			throw std::domain_error("Data type mismatch");
	}
}

CTypedVariant & CTypedVariantAdapter::getTypedVariant()
{
	return this->m_TypedVariant;
}

size_t CTypedVariantAdapter::getTypeVariantId() const
{
	return m_TypeVariantId;
}

