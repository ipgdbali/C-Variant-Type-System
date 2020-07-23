#ifndef CUINT_HPP
#define CUINT_HPP

#include "CStronglyTyped.hpp"

typedef unsigned int uint;

class CUInt : public CStronglyTyped
{
	private:

	protected:

	public:

		//Copy Constructor 
		CUInt(const CUInt & value);

		//Move Constructor 
		CUInt(CUInt && value);

		//Default Value Construtor
		CUInt(unsigned int val);
		
		//Destructor
		~CUInt();

		void set(unsigned int value);

		unsigned int get() const;

		operator unsigned int();
};

#endif

