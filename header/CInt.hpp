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
		}

	public:

		CInt();

		//Copy Constructor 
		CInt(CTypedVariant & TypedVariant);

		//Default Value Construtor
		CInt(int val);
		~CInt();

		void set(int value);
		int get();
};

#endif
