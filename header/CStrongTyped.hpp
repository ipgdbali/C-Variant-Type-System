#ifndef CSTRONGTYPED_HPP
#define CSTRONGTYPED_HPP

#include "CTypedVariant.hpp"

class CStrongTyped : public CTypedVariant
{
	public:

		// Default Constructor
		CStrongTyped();

		// Constructor
		CStrongTyped(const char * typeId = nullptr,size_t size = 0);

		// ** Copy Operation ** 
		
		// Copy CTypedVariant
		CStrongTyped(const CTypedVariant & var,const char * typeId = nullptr);
		CStrongTyped & operator = (const CTypedVariant & var);

		// Copy CStrongTyped
		CStrongTyped(const CStrongTyped & var,const char * typeId = nullptr);
		CStrongTyped & operator = (const CStrongTyped & var);

		// Copy Method
		bool copy(const CTypedVariant & var);

		// ** Move Operation **
		
		// Moving CTypedVariant
		CStrongTyped(CTypedVariant && var,const char * typeId = nullptr);
		CStrongTyped & operator = (CTypedVariant && var);

		// Moving CStrongTyped
		CStrongTyped(CStrongTyped && var,const char * typeId = nullptr);
		CStrongTyped & operator = (CStrongTyped && var);

		// Move Method  
		bool move(CTypedVariant && var);

		// Runtime Type setter
		void setTypeId(const char * typeId);

	protected:

	private:

};

#endif
