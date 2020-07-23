#ifndef CSTRONGLYTYPED_HPP
#define CSTRONGLYTYPED_HPP

#include "CTypedVariant.hpp"

class CStronglyTyped : public CTypedVariant
{
	private:
	protected:
	public:

		CStronglyTyped();

		CStronglyTyped(const CStronglyTyped & source);

		CStronglyTyped(CStronglyTyped && source);

		//Copy Operator
		virtual CStronglyTyped & operator = (const CStronglyTyped & source);

		//Move Operator
		virtual CStronglyTyped & operator = (CStronglyTyped && source);

		//Copy Method
		virtual void set(const CStronglyTyped & source);

		//Move Method
		virtual void set(CStronglyTyped && source);

		size_t getClassId();

};

#endif
