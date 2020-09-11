#ifndef CWEAKTYPED_HPP
#define CWEAKTYPED_HPP

#include "CTypedVariant.hpp"

/**
 * Can be instance
 */
class CWeakTyped : public CTypedVariant
{
	public:
		// Default Constructor
		CWeakTyped();

		//
		// Copy Operation
		//

		// Copy Constructor
		CWeakTyped(const CWeakTyped & val);

		// Copy Operator
		CWeakTyped & operator = (const CWeakTyped & val);

		// Copy Method
		bool copy(const CTypedVariant & val);

		// 
		// Move Operation
		//

		// Move Constructor
		CWeakTyped(CWeakTyped && val);

		// Move Operator
		CWeakTyped & operator = (CWeakTyped && val);

		// Move Method
		bool move(CTypedVariant && val);

		const char * getTypeId() const;

	protected:
	private:
};

#endif
