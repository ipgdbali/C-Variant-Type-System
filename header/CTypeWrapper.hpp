#ifndef CTYPEWRAPPER_HPP
#define CTYPEWRAPPER_HPP

#include "CWeakTyped.hpp"
#include "CSimpleType.hpp"

#define type_support_decl(t) \
	CTypeWrapper(const t & val);\
	CTypeWrapper & operator = (const t & val);\
	\
	CTypeWrapper(t && val);\
	CTypeWrapper & operator = (t && val);\
	\
	CTypeWrapper(const t::simple_type val);\
	CTypeWrapper & operator = (const t::simple_type val);

class CTypeWrapper : public CWeakTyped
{
	public:

	// Default Constructor
	CTypeWrapper();

	//
	// Copy Operation
	//

	// Copy Constructor
	CTypeWrapper(const CTypeWrapper & var);
	CTypeWrapper(const CWeakTyped & var);
	CTypeWrapper(const CTypedVariant & var);

	// Copy Operator
	CTypeWrapper & operator = (const CTypeWrapper & var);
	CTypeWrapper & operator = (const CWeakTyped & var);
	CTypeWrapper & operator = (const CTypedVariant & var);

	// Copy Method
	void copy(const CTypedVariant & var);

	//
	// Move Operation
	//

	// Move Constructor
	CTypeWrapper(CTypeWrapper && var);
	CTypeWrapper(CWeakTyped && var);
	CTypeWrapper(CTypedVariant && var);

	// Copy Operator
	CTypeWrapper & operator = (CTypeWrapper && var);
	CTypeWrapper & operator = (CWeakTyped && var);
	CTypeWrapper & operator = (CTypedVariant && var);

	// Copy Method
	void move(CTypedVariant && var);

	// Type Support
	type_support_decl(CChar)
	type_support_decl(CUChar)
	type_support_decl(CShort)
	type_support_decl(CUShort)
	type_support_decl(CInt)
	type_support_decl(CUInt)
	type_support_decl(CFloat)
	type_support_decl(CDouble)
	type_support_decl(CBool)
};

#undef type_support_decl

#endif
