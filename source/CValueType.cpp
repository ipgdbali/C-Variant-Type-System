#include "CValueType.hpp"

template <typename T>
CValueType<T>::CValueType() : CValueType<T>(0)
{
}

template <typename T>
CValueType<T>::CValueType(const CTypedVariant & val) : CTypedVariant(val,TYPE_ID)
{
}

template <typename T>
CValueType<T>::CValueType(CTypedVariant && val) : CTypedVariant(val,TYPE_ID)
{
}

template <typename T>
CValueType<T>::CValueType(T val) :
	CTypedVariant(TYPE_ID,sizeof(T))
{
	this->set(val);
}

template <typename T>
void CValueType<T>::set(T val)
{
	if(this->getPData() == nullptr && this->getSize() == 0)
	{
		this->deAlloc();
		this->alloc(sizeof(T));
	}
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
const char * const CValueType<unsigned short>::TYPE_ID = "DT_USHORT";

template <>
const char * const CValueType<char>::TYPE_ID = "DT_CHAR";

template <>
const char * const CValueType<unsigned char>::TYPE_ID = "DT_UCHAR";

template <>
const char * const CValueType<float>::TYPE_ID = "DT_FLOAT";

template <>
const char * const CValueType<double>::TYPE_ID = "DT_DOUBLE";

template <>
const char * const CValueType<bool>::TYPE_ID = "DT_BOOL";

