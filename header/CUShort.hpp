#ifndef CUSHORT_HPP
#define CUSHORT_HPP

#include "CTypedVariant.hpp" 

class CUShort : public CTypedVariant
{
	private:

	protected:

	public:
		CUShort();
		CUShort(unsigned short val);

		void set(unsigned short val);
		unsigned short get();

		CUShort & operator = (unsigned short val);
		operator unsigned short ();
};

#endif
