#ifndef CSTRONGTYPED_HPP
#define CSTRONGTYPED_HPP

#include "CTypedVariant.hpp"

/**
 * Cannot be instanced
 * Default constructor is protected
 */
class CStrongTyped : public CTypedVariant
{
	public:
		//
		// Copy Operation
		// 

		// Copy Constructor
		CStrongTyped(const CStrongTyped & var, const char * typeId = nullptr);
		CStrongTyped(const CTypedVariant & var,const char * typeId = nullptr);

		// Copy Operator
		CStrongTyped & operator = (const CStrongTyped & var);
		CStrongTyped & operator = (const CTypedVariant & var);

		// Copy Method
		bool copy(const CTypedVariant & var);
		
		//
		// Move Operation
		//

		// Move Constructor
		CStrongTyped(CStrongTyped && var,const char * typeId = nullptr);
		CStrongTyped(CTypedVariant && var,const char * typeId = nullptr);

		// Move Operator
		CStrongTyped & operator = (CStrongTyped && var);
		CStrongTyped & operator = (CTypedVariant && var);

		// Move Method
		bool move(CTypedVariant && var);

	protected:

		// Constructor
		CStrongTyped(const char * typeId = nullptr,size_t size = 0);

	private:

};

#endif
