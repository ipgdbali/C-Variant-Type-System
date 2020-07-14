#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

class CTypedVariant : protected CVariant
{
	private:
		size_t m_DataType;

	protected:
		//Only Derived class can set
		void setDataType(size_t dataType);
	public:
		size_t getDataType() const;
};

#endif
