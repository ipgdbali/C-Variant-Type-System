#include "CFixedSizeType.hpp"

template <typename T>
CFixedSizeType<T>::CFixedSizeType() : CSimpleType<T>()
{
}

template <typename T>
CFixedSizeType<T>::CFixedSizeType(const CFixedSizeType<T> & var) : 
	CSimpleType<T>(var)
{
}

template <typename T>
CFixedSizeType<T> & CFixedSizeType<T>::operator = (const CFixedSizeType<T> & var)
{
	this->copy(var);
	return *this;
}

template <typename T>
CFixedSizeType<T>::CFixedSizeType(CFixedSizeType<T> && var)
	: CSimpleType<T>(std::move(var))
{
}

template <typename T>
CFixedSizeType<T> & CFixedSizeType<T>::operator = (CFixedSizeType && var)
{
	this->move(std::move(var));
	return *this;
}

template <typename T>
CFixedSizeType<T>::CFixedSizeType(const T val) : CSimpleType<T>()
{
	this->set(val);
}

template <typename T>
CFixedSizeType<T>::CFixedSizeType(const T & val) : CSimpleType<T>()
{
	this->set(val);
}

template <typename T>
CFixedSizeType<T> & CFixedSizeType<T>::operator = (const T val)
{
	this->set(val);
	return *this;
}

template <typename T>
CFixedSizeType<T> & CFixedSizeType<T>::operator = (const T & val)
{
	this->set(val);
	return * this;
}


template <typename T>
bool CFixedSizeType<T>::set(const T val)
{
	this->write(&val);
	return true;
}

//
// Getter
//
template <typename T>
bool CFixedSizeType<T>::get(T * pVal)
{
	this->read(pVal);
	return true;
}

template <typename T>
bool CFixedSizeType<T>::get(T & val)
{
	this->read(&val);
	return true;
}

template <typename T>
T CFixedSizeType<T>::get()
{
	T tmp;
	this->get(&tmp);
	return tmp;
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

template class CFixedSizeType<int>;
template class CFixedSizeType<unsigned int>;
template class CFixedSizeType<short>;
template class CFixedSizeType<unsigned short>;
template class CFixedSizeType<char>;
template class CFixedSizeType<unsigned char>;
template class CFixedSizeType<float>;
template class CFixedSizeType<double>;
template class CFixedSizeType<bool>;

