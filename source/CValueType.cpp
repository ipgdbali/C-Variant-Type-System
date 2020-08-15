#include "CValueType.hpp"

template <typename T>
CValueType<T>::CValueType() :
	CStrongTyped(TYPE_ID,sizeof(T))
{
}

template <typename T>
CValueType<T>::CValueType(const CTypedVariant & var) 
	: CStrongTyped(var,TYPE_ID)
{
}

template <typename T>
CValueType<T>::CValueType(const CStrongTyped & var) 
	: CStrongTyped(var,TYPE_ID)
{
}

template <typename T>
CValueType<T>::CValueType(const CValueType & var) 
	: CStrongTyped(var,nullptr)
{
}

template <typename T>
CValueType<T>::CValueType(T val) : CValueType()
{
	this->set(val);
}

template <typename T>
void CValueType<T>::set(T val)
{
	this->write(&val);
}

template <typename T>
T CValueType<T>::get()
{
	T dummy;
	this->read(&dummy);
	return dummy;
}

template <typename T>
CValueType<T> & CValueType<T>::operator = (T val)
{
	this->set(val);
	return *this;
}

template <typename T>
CValueType<T>::operator T ()
{
	return this->get();
}


template <>
const char * const CValueType<int>::TYPE_ID = "DT_INT";
template class CValueType<int>;

template <>
const char * const CValueType<unsigned int>::TYPE_ID = "DT_UINT";
template class CValueType<unsigned int>;

template <>
const char * const CValueType<short>::TYPE_ID = "DT_SHORT";
template class CValueType<short>;

template <>
const char * const CValueType<unsigned short>::TYPE_ID = "DT_USHORT";
template class CValueType<unsigned short>;

template <>
const char * const CValueType<char>::TYPE_ID = "DT_CHAR";
template class CValueType<char>;

template <>
const char * const CValueType<unsigned char>::TYPE_ID = "DT_UCHAR";
template class CValueType<unsigned char>;

template <>
const char * const CValueType<float>::TYPE_ID = "DT_FLOAT";
template class CValueType<float>;

template <>
const char * const CValueType<double>::TYPE_ID = "DT_DOUBLE";
template class CValueType<double>;

template <>
const char * const CValueType<bool>::TYPE_ID = "DT_BOOL";
template class CValueType<bool>;
