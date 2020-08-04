#ifndef CINT_HPP
#define CINT_HPP

#include "CTypedVariant.hpp" 

class CInt : public CTypedVariant
{
	private:

	protected:

	public:
		CInt();
		CInt(int val);

		void set(int val);
		int get();

		CInt & operator = (int val);
		operator int ();
};

#endif
