#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

class CTypedVariant : public CVariant
{
	private:
		size_t m_DataType;

	protected:
		void setDataType(size_t dataType);

	public:

		CTypedVariant();

		//Copy Construtor
		CTypedVariant(const CTypedVariant & value);

		//Move Construtor
		CTypedVariant(CTypedVariant && value);

		//Copy Operator
		virtual CTypedVariant & operator = (const CTypedVariant & value);

		//Move Operator
		virtual CTypedVariant & operator = (CTypedVariant && value);

		//Copy Set
		virtual void set(const CTypedVariant & value);

		//Move Set
		virtual void set(CTypedVariant && value);

		size_t getDataType() const;
};

#endif
