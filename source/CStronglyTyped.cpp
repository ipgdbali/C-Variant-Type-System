#include "CStronglyTyped.hpp"

CStronglyTyped::CStronglyTyped()
{
	this->setDataType(this->getClassId());
}

CStronglyTyped::CStronglyTyped(const CTypedVariant & source)
{
	if(source.getDataType() == this->getClassId())
	{
		((CTypedVariant*)this)->set(source);
	}
	else
	{
		throw std::invalid_argument("Wrong class");
	}
}

CStronglyTyped::CStronglyTyped(CTypedVariant && source)
{
	if(source.getDataType() == this->getClassId())
	{
		((CTypedVariant*)this)->set(std::move(source));
	}
	else
	{
		throw std::invalid_argument("Wrong class");
	}
}

CStronglyTyped & CStronglyTyped::operator = (const CStronglyTyped & source)
{
	if(this->getDataType() == source.getDataType())
	{
		((CTypedVariant*)this)->set(source);
	}
	else
	{
		throw std::invalid_argument("Wrong class");
	}
	return *this;
}

CStronglyTyped & CStronglyTyped::operator = (const CStronglyTyped & source)
{
	if(this->getDataType() == source.getDataType())
	{
		((CTypedVariant*)this)->set(std::move(source));
	}
	else
	{
		throw std::invalid_argument("Wrong class");
	}
	return *this;
}

