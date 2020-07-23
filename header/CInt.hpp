#ifndef CINT_HPP
#define CINT_HPP

#include "CStronglyTyped.hpp"

class CInt : public CStronglyTyped
{
	private:

	protected:

	public:

		//Copy Constructor 
		CInt(const CInt & value);

		//Move Constructor 
		CInt(CInt && value);

		//Default Value Construtor
		CInt(int val);
		
		//Destructor
		~CInt();

		void set(int value);

		int get() const;

		operator int();
};

#endif
