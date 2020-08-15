#ifndef CVALUETYPE_HPP
#define CVALUETYPE_HPP

#include "CStrongTyped.hpp" 

template <typename T>
class CValueType : public CStrongTyped
{
	public:

		static const char * const TYPE_ID;

		// Default Constructor
		CValueType();

		// setter
		CValueType(const CTypedVariant & var);
		CValueType(const CStrongTyped & var);
		CValueType(const CValueType & var);

		CValueType(T val);
		CValueType & operator = (T val);
		void set(T val);

		// getter
		operator T ();
		T get();

	protected:

	private:

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
