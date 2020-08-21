#ifndef CWEAKTYPED_HPP
#define CWEAKTYPED_HPP

#include "CTypedVariant.hpp"

class CWeakTyped : protected CTypedVariant
{
	public:
		// Default Constructor
		CWeakTyped();

		//
		// Copy Operation
		//

		// Copy Constructor
		CWeakTyped(const CWeakTyped & val);
		CWeakTyped(const CTypedVariant & val);

		// Copy Operator
		CWeakTyped & operator = (const CWeakTyped & val);
		CWeakTyped & operator = (const CTypedVariant & val);

		// Copy Method
		void copy(const CTypedVariant & val);

		// 
		// Move Operation
		//

		// Move Constructor
		CWeakTyped(CWeakTyped && val);
		CWeakTyped(CTypedVariant && val);

		// Move Operator
		CWeakTyped & operator = (CWeakTyped && val);
		CWeakTyped & operator = (CTypedVariant && val);

		// Move Method
		void move(CTypedVariant && val);

		const char * getTypeId() const;

	protected:
	private:
};

#endif
