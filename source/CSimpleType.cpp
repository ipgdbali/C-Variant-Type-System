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

template <>
const char * const CSimpleType<int>::TYPE_ID = "DT_INT";
template class CSimpleType<int>;

template <>
const char * const CSimpleType<unsigned int>::TYPE_ID = "DT_UINT";
template class CSimpleType<unsigned int>;

template <>
const char * const CSimpleType<short>::TYPE_ID = "DT_SHORT";
template class CSimpleType<short>;

template <>
const char * const CSimpleType<unsigned short>::TYPE_ID = "DT_USHORT";
template class CSimpleType<unsigned short>;

template <>
const char * const CSimpleType<char>::TYPE_ID = "DT_CHAR";
template class CSimpleType<char>;

template <>
const char * const CSimpleType<unsigned char>::TYPE_ID = "DT_UCHAR";
template class CSimpleType<unsigned char>;

template <>
const char * const CSimpleType<float>::TYPE_ID = "DT_FLOAT";
template class CSimpleType<float>;

template <>
const char * const CSimpleType<double>::TYPE_ID = "DT_DOUBLE";
template class CSimpleType<double>;

template <>
const char * const CSimpleType<bool>::TYPE_ID = "DT_BOOL";
template class CSimpleType<bool>;
