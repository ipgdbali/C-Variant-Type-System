#ifndef CUINT_HPP
#define CUINT_HPP

#include "CTypedVariant.hpp" 

class CUInt : public CTypedVariant
{
	private:

	protected:

	public:
		CUInt(unsigned int val);

		void set(unsigned int val);
		unsigned int get();

		CUInt & operator = (unsigned int val);
		operator unsigned int ();
};

#endif
