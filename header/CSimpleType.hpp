#ifndef CSIMPLETYPE_HPP
#define CSIMPLETYPE_HPP

#include "CTypedVariant.hpp"
#include "CStrongTyped.hpp" 

template <typename T>
class CSimpleType : public CStrongTyped
{
	public:

		typedef T simple_type;

		static const char * const TYPE_ID;

		// Default Constructor
		CSimpleType();

		//
		// Copy Operation
		//

		// Copy Constructor
		CSimpleType(const CSimpleType & var);
		CSimpleType(const CStrongTyped & var);
		CSimpleType(const CTypedVariant & var);

		// Copy Operator
		CSimpleType & operator = (const CSimpleType & var);

		//
		// Move Operation
		//

		// Move Constructor
		CSimpleType(CSimpleType && var);
		CSimpleType(CStrongTyped && var);
		CSimpleType(CTypedVariant && var);

		// Move Operator
		CSimpleType & operator = (CSimpleType && var);

		//
		// Setter
		//
		CSimpleType(const T val);
		CSimpleType & operator = (const T val);
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
