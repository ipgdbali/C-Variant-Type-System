#ifndef CINT_HPP
#define CINT_HPP

#include "CTypedVariant.hpp"

class CInt : public CTypedVariant
{
	private:

	protected:
		static size_t getClassId()
		{
			return 10;
		};


	public:

		CInt();

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

		void set(void * value);
		void set(int value);
		int get() const;
		operator int();
};

#endif
