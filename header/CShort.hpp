#ifndef CSHORT_HPP
#define CSHORT_HPP

#include "CTypedVariant.hpp" 

class CShort : public CTypedVariant
{
	private:

	protected:

	public:
		CShort();
		CShort(short val);

		void set(short val);
		short get();

		CShort & operator = (short val);
		operator short ();
};

#endif
