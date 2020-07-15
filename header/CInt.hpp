#ifndef CINT_HPP
#define CINT_HPP

#include "CStronglyTyped.hpp"

class CInt : public CStronglyTyped
{
	private:

	protected:

	public:

		//Copy Constructor 
		CInt(const CTypedVariant & value);

		//Move Constructor 
		CInt(CTypedVariant && value);

		//Default Value Construtor
		CInt(int val);
		
		//Destructor
		~CInt();

		CInt & operator = (const CTypedVariant & TypedVariant);
		CInt & operator = (CTypedVariant && TypedVariant);

		void set(void * pSource);
		void set(int value);
		int get() const;

		size_t getClassId();
		operator int();
};

#endif
