#include "CReferenceType.hpp"

template <typename T>
CReferenceType<T>::CReferenceType() :
	CStrongTyped(TYPE_ID,sizeof(T))
{
}

template <typename T>
CReferenceType<T>::CReferenceType(const CTypedVariant & var) 
	: CStrongTyped(var,TYPE_ID)
{
}

template <typename T>
CReferenceType<T>::CReferenceType(const CStrongTyped & var) 
	: CStrongTyped(var,TYPE_ID)
{
}

template <typename T>
CReferenceType<T>::CReferenceType(const CReferenceType & var) 
	: CStrongTyped(var,nullptr)
{
}

template <typename T>
CReferenceType<T>::CReferenceType(T val) : CReferenceType()
{
	this->set(val);
}

template <typename T>
void CReferenceType<T>::set(T val)
{
	this->write(&val);
}

template <typename T>
T CReferenceType<T>::get()
{
	T dummy;
	this->read(&dummy);
	return dummy;
}

template <typename T>
CReferenceType<T> & CReferenceType<T>::operator = (T val)
{
	this->set(val);
	return *this;
}

template <typename T>
CReferenceType<T>::operator T ()
{
	return this->get();
}


template <>
const char * const CReferenceType<int>::TYPE_ID = "DT_INT";
template class CReferenceType<int>;

template <>
const char * const CReferenceType<unsigned int>::TYPE_ID = "DT_UINT";
template class CReferenceType<unsigned int>;

template <>
const char * const CReferenceType<short>::TYPE_ID = "DT_SHORT";
template class CReferenceType<short>;

template <>
const char * const CReferenceType<unsigned short>::TYPE_ID = "DT_USHORT";
template class CReferenceType<unsigned short>;

template <>
const char * const CReferenceType<char>::TYPE_ID = "DT_CHAR";
template class CReferenceType<char>;

template <>
const char * const CReferenceType<unsigned char>::TYPE_ID = "DT_UCHAR";
template class CReferenceType<unsigned char>;

template <>
const char * const CReferenceType<float>::TYPE_ID = "DT_FLOAT";
template class CReferenceType<float>;

template <>
const char * const CReferenceType<double>::TYPE_ID = "DT_DOUBLE";
template class CReferenceType<double>;

template <>
const char * const CReferenceType<bool>::TYPE_ID = "DT_BOOL";
template class CReferenceType<bool>;
