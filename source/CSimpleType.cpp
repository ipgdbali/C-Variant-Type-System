#include "CSimpleType.hpp"

template <typename T>
CSimpleType<T>::CSimpleType() :
	CStrongTyped(TYPE_ID,sizeof(T))
{
}

template <typename T>
CSimpleType<T>::CSimpleType(const CTypedVariant & var) :
	CStrongTyped(var,TYPE_ID)
{
}

template <typename T>
CSimpleType<T>::CSimpleType(T val) : CSimpleType()
{
	this->set(val);
}

template <typename T>
void CSimpleType<T>::set(T val)
{
	this->write(&val);
}

template <typename T>
T CSimpleType<T>::get()
{
	T dummy;
	this->read(&dummy);
	return dummy;
}

template <typename T>
CSimpleType<T> & CSimpleType<T>::operator = (T val)
{
	this->set(val);
	return *this;
}

template <typename T>
CSimpleType<T>::operator T ()
{
	return this->get();
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
