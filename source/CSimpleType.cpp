#include "CSimpleType.hpp"

template <typename T>
CSimpleType<T>::CSimpleType() :
	CStrongTyped(TYPE_ID,0)
{
}

template <typename T>
CSimpleType<T>::CSimpleType(const CSimpleType<T> & var) :
	CStrongTyped(var)
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

template <typename T>
CSimpleType<T>::CSimpleType(const T val) : CSimpleType<T>()
{
	this->set(val);
}

template <typename T>
CSimpleType<T> & CSimpleType<T>::operator = (const T val)
{
	this->set(val);
	return *this;
}

template <typename T>
bool CSimpleType<T>::set(const T val)
{
	this->deAlloc();
	this->alloc(sizeof(T));
	return this->write(&val);
}

//
// Getter
//
template <typename T>
bool CSimpleType<T>::get(T * pVal)
{
	return this->read(pVal);
}

template <typename T>
bool CSimpleType<T>::get(T & val)
{
	return this->read(&val);
}

template <typename T>
T CSimpleType<T>::get()
{
	T tmp;
	this->get(&tmp);
	return tmp;
}

template <typename T>
bool CSimpleType<T>::isNull()
{
	return CVariant::isNull();
}

template <typename T>
bool CSimpleType<T>::isNotNull()
{
	return CVariant::isNotNull();
}

template <>
const char * const CSimpleType<int>::TYPE_ID = "DT_INT";
template <>
const char * const CSimpleType<unsigned int>::TYPE_ID = "DT_UINT";
template <>
const char * const CSimpleType<short>::TYPE_ID = "DT_SHORT";
template <>
const char * const CSimpleType<unsigned short>::TYPE_ID = "DT_USHORT";
template <>
const char * const CSimpleType<char>::TYPE_ID = "DT_CHAR";
template <>
const char * const CSimpleType<unsigned char>::TYPE_ID = "DT_UCHAR";
template <>
const char * const CSimpleType<float>::TYPE_ID = "DT_FLOAT";
template <>
const char * const CSimpleType<double>::TYPE_ID = "DT_DOUBLE";
template <>
const char * const CSimpleType<bool>::TYPE_ID = "DT_BOOL";

template class CSimpleType<int>;
template class CSimpleType<unsigned int>;
template class CSimpleType<short>;
template class CSimpleType<unsigned short>;
template class CSimpleType<char>;
template class CSimpleType<unsigned char>;
template class CSimpleType<float>;
template class CSimpleType<double>;
template class CSimpleType<bool>;
