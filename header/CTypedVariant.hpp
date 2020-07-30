#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

class CTypedVariantAdapter;

class CTypedVariant : public CVariant
{
	private:
		size_t m_DataType;

	protected:
		void setDataType(size_t dataType);

		friend CTypedVariantAdapter;

	public:

		/**
		 * Default Constructor
		 * Contruct TypedVariant with DataType is NotSet (0)
		 */
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

		size_t getDataTypeId() const;
};

#endif
