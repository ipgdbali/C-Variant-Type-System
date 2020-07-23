#include "CStronglyTyped.hpp"

CStronglyTyped::CStronglyTyped() : 
	CTypedVariant()
{
}

CStronglyTyped::CStronglyTyped(const CStronglyTyped & source) : 
	CTypedVariant(source)
{
}

CStronglyTyped::CStronglyTyped(CStronglyTyped && source) :
	CTypedVariant(std::move(source))
{
}

CStronglyTyped & CStronglyTyped::operator = (const CStronglyTyped & source)
{
	this->set(source);
	return *this;
}

CStronglyTyped & CStronglyTyped::operator = (CStronglyTyped && source)
{
	this->set(std::move(source));
	return *this;
}

void CStronglyTyped::set(const CStronglyTyped & source)
{
	if(this->getDataType() == source.getDataType())
		((CTypedVariant*)this)->set(source);
	else
		throw std::invalid_argument("Wrong class");
}

void CStronglyTyped::set(CStronglyTyped && source)
{
	if(this->getDataType() == source.getDataType())
		((CTypedVariant*)this)->set(std::move(source));
	else
		throw std::invalid_argument("Wrong class");
}


