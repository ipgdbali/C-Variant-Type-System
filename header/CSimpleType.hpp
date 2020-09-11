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

	protected:

	private:

};

#endif
