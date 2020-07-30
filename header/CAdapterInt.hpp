#ifndef CADAPTERINT_HPP
#define CADAPTERINT_HPP

#include "CTypedVariantAdapter.hpp"

class CAdapterInt : public CTypedVariantAdapter
{
	private:
	protected:
	public:

		CAdapterInt(CTypedVariant typedVariant);

		static constexpr const char * STR_ID_NAME = "INTEGER";

		CAdapterInt & operator = (int val);
		operator int();

};

#endif
