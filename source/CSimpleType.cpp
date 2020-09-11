#include "CSimpleType.hpp"

template <typename T>
CSimpleType<T>::CSimpleType() :
	CStrongTyped(TYPE_ID,sizeof(T))
{
}

template <typename T>
CSimpleType<T>::CSimpleType(const CSimpleType & var) :
	CStrongTyped(var,TYPE_ID)
{
}

template <typename T>
CSimpleType<T>::CSimpleType(const CStrongTyped & var) :
	CStrongTyped(var,TYPE_ID)
{
}

template <typename T>
CSimpleType<T>::CSimpleType(const CTypedVariant & var) :
	CStrongTyped(var,TYPE_ID)
{
}

template <typename T>
CSimpleType<T> & CSimpleType<T>::operator = (const CSimpleType & var)
{
	CStrongTyped::copy(var);
	return *this;
}

template <typename T>
CSimpleType<T>::CSimpleType(CSimpleType && var) :
	CStrongTyped(std::move(var),TYPE_ID)
{
}

template <typename T>
CSimpleType<T>::CSimpleType(CStrongTyped && var) :
	CStrongTyped(std::move(var),TYPE_ID)
{
}

template <typename T>
CSimpleType<T>::CSimpleType(CTypedVariant && var) :
	CStrongTyped(std::move(var),TYPE_ID)
{
}

template <typename T>
CSimpleType<T> & CSimpleType<T>::operator = (CSimpleType && var)
{
	CStrongTyped::move(std::move(var));
	return *this;
}

