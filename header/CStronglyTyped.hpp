#ifndef CSTRONGLYTYPED_HPP
#define CSTRONGLYTYPED_HPP

#include "CTypedVariant.hpp"

class CStronglyTyped : public CTypedVariant
{
	private:
	protected:
	public:

		CStronglyTyped();

		//Copy Constructor
		CStronglyTyped(const CTypedVariant & source);
		CStronglyTyped(CTypedVariant && source);

		//Copy Operator
		CStronglyTyped & operator = (const CStronglyTyped & source);

		//Move Operator
		CStronglyTyped & operator = (CStronglyTyped && source);

		virtual void set(void * pSource) = 0;

		virtual size_t getClassId() = 0;

};

#endif
