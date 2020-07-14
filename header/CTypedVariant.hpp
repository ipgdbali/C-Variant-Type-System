#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

class CTypedVariant : public CVariant
{
	private:
		size_t m_DataType;
		bool	m_bChangeDataType;

	protected:

		//Only Derived class can set
		void setDataType(size_t dataType);

	public:

		CTypedVariant();

		//Copy Construtor
		CTypedVariant(const CTypedVariant & value);
		//Copy Operator
		CTypedVariant & operator = (const CTypedVariant & value);

		//Move Construtor
		CTypedVariant(CTypedVariant && value);
		//Move Operator
		CTypedVariant & operator = (CTypedVariant && value);

		
		/**
		 * Set Flexibilty
		 * Flexibilty means CTypedVariant may change its data type
		 * after set
		 */
		void setIsFlexible(bool flexible);
		/**
		 * Return flexibility
		 * If class has flexibilty mean it can change type after set
		 * and vice versa
		 */
		bool getIsFlexible() const;

		size_t getDataType() const;
};

#endif
