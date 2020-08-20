#ifndef CSTRONGTYPED_HPP
#define CSTRONGTYPED_HPP

#include "CTypedVariant.hpp"

class CStrongTyped : protected CTypedVariant
{
	public:

		// Constructor
		CStrongTyped(const char * typeId = nullptr,size_t size = 0);

		// Copy Operation
		CStrongTyped(const CTypedVariant & var,const char * typeId = nullptr);
		CStrongTyped & operator = (const CTypedVariant & var);
		void copy(const CTypedVariant & var);
		
		// Move Operation
		CStrongTyped(CTypedVariant && var,const char * typeId = nullptr);
		CStrongTyped & operator = (CTypedVariant && var);
		void move(CTypedVariant && var);

		// Runtime Type set & getter
		void setTypeId(const char * typeId);
		const char * getTypeId() const;

	protected:

	private:

};

#endif
