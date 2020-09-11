#ifndef CFIXEDSIZETYPE
#define CFIXEDSIZETYPE

#include "CSimpleType.hpp"

template <typename T>
class CFixedSizeType : CSimpleType<T>
{
	public:

		CFixedSizeType();

		CFixedSizeType(const CFixedSizeType & var);
		CFixedSizeType & operator = (const CFixedSizeType & var);

		CFixedSizeType(CFixedSizeType && var);
		CFixedSizeType & operator = (CFixedSizeType && var);

		//
		// Setter
		//
		CFixedSizeType(const T val);
		CFixedSizeType(const T & val);
		CFixedSizeType(T && val);

		CFixedSizeType & operator = (const T val);
		CFixedSizeType & operator = (const T & val);
		CFixedSizeType & operator = (T && val);

		bool set(const T val);

		//
		// Getter
		//
		bool get(T * pVal);
		bool get(T & val);
		T get();

	protected:
	private:
};

typedef CFixedSizeType<int> CInt;
typedef CFixedSizeType<unsigned int> CUInt;
typedef CFixedSizeType<short> CShort;
typedef CFixedSizeType<unsigned short> CUShort;
typedef CFixedSizeType<char> CChar;
typedef CFixedSizeType<unsigned char> CUChar;
typedef CFixedSizeType<float> CFloat;
typedef CFixedSizeType<double> CDouble;
typedef CFixedSizeType<bool> CBool;

#endif
