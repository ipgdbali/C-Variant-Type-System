#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

class CTypedVariantAdapter;

class CTypedVariant : public CVariant
{
	private:
		const char * m_DataTypeId;

	protected:
		void setDataTypeId(const char * dataTypeId);

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

		//Get data type identifier
		const char * getDataTypeId() const;
};

#endif
