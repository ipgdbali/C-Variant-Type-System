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
		~CInt();

		void set(int value);
		int get();
};

#endif
