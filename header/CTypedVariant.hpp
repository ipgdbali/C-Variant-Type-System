#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

class CTypedVariant : protected CVariant
{
	private:
		const char * m_DataTypeId;

	protected:

	public:

		CTypedVariant(const char * typeId,size_t size = 0);
		virtual ~CTypedVariant();

		const char * getTypeId() const;

		
};

#endif
