#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

class CTypedVariant : private CVariant
{
	private:
		const char * m_DataTypeId;

	protected:
		bool write(const void * pData);
		bool read(void * pData);

		bool alloc(const char * typeId,size_t size);
		void deAlloc();
	public:

		CTypedVariant(const char * typeId,size_t size);
		virtual ~CTypedVariant();

		const char * getTypeId() const;
};

#endif
