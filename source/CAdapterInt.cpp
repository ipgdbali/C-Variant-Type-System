#include "CAdapterInt.hpp"

CAdapterInt::CAdapterInt(CTypedVariant typedVariant) : 
	CTypedVariantAdapter(typedVariant,CAdapterInt::STR_ID_NAME)
{

}

CAdapterInt & CAdapterInt::operator = (int val)
{
	this->getTypedVariant().write(&val);
	return *this;
}

CAdapterInt::operator int()
{
	int dummy;
	this->getTypedVariant().read(&dummy);
	return dummy;
}
