#ifndef CSIMPLETYPE_HPP
#define CSIMPLETYPE_HPP

#include "CStrongTyped.hpp" 

template <typename T>
class CSimpleType : public CStrongTyped
{
	public:

		static const char * const TYPE_ID;

		// Default Constructor
		CSimpleType();

		// setter
		CSimpleType(const CTypedVariant & var);

		/*
		CSimpleType(const CStrongTyped & var);
		CSimpleType(const CSimpleType & var);
		*/

		CSimpleType(T val);
		CSimpleType & operator = (T val);
		virtual void set(T val);

		// getter
		operator T ();
		virtual T get();

	protected:

	private:

};

typedef CSimpleType<int> CInt;
typedef CSimpleType<unsigned int> CUInt;
typedef CSimpleType<short> CShort;
typedef CSimpleType<unsigned short> CUShort;
typedef CSimpleType<char> CChar;
typedef CSimpleType<unsigned char> CUChar;
typedef CSimpleType<float> CFloat;
typedef CSimpleType<double> CDouble;
typedef CSimpleType<bool> CBool;

#endif