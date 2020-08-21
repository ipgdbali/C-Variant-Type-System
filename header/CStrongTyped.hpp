#ifndef CSTRONGTYPED_HPP
#define CSTRONGTYPED_HPP

#include "CTypedVariant.hpp"

class CStrongTyped : protected CTypedVariant
{
	public:

		// Constructor
		CStrongTyped(const char * typeId = nullptr,size_t size = 0);

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
		void copy(const CTypedVariant & var);
		
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
		void move(CTypedVariant && var);

		// Runtime Type set & getter
		void setTypeId(const char * typeId);
		const char * getTypeId() const;

	protected:

	private:

};

#endif
