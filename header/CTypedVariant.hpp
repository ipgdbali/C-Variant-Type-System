#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

class CTypedVariant : private CVariant
{
	private:
		const char * m_DataTypeId;

	protected:

	public:

		/**
		 * Default Constructor
		 * Contruct TypedVariant with DataType is NotSet (0)
		 */
		CTypedVariant(const char * typeId,size_t size);
		virtual ~CTypedVariant();

		bool alloc(const char * typeId,size_t size);

		void deAlloc();

		const char * getTypeId() const;

};

#endif
