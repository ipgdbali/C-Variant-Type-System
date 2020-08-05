#ifndef CVALUETYPE_HPP
#define CVALUETYPE_HPP

#include "CTypedVariant.hpp" 


template <typename T>
class CValueType : public CTypedVariant
{
	private:

	protected:

	public:

		static const char * const TYPE_ID;

		CValueType();

		CValueType(const CTypedVariant & val);
		CValueType(CTypedVariant && val);

		// TODO :
		// test assigment operator overloading for CTypedVariant 

		CValueType(T val);

		void set(T val);
		T get();

		CValueType & operator = (T val);

		operator T ();
};

typedef CValueType<int> CInt;
typedef CValueType<unsigned int> CUInt;
typedef CValueType<short> CShort;
typedef CValueType<unsigned short> CUShort;
typedef CValueType<char> CChar;
typedef CValueType<unsigned char> CUChar;
typedef CValueType<float> CFloat;
typedef CValueType<double> CDouble;
typedef CValueType<bool> CBool;

#endif
