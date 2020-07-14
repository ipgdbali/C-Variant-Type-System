#include "CTypedVariant.hpp"

void CTypedVariant::setDataType(size_t dataType)
{
	this->m_DataType = dataType;
}

size_t CTypedVariant::getDataType() const
{
	return this->m_DataType;
}
