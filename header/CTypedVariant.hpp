#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

/*
 * CTypedVariant
 *
 * Special class derived from CVariant with type capability.
 * This class could not be instantiated because constructor is made protected.
 * The only avaiable Constructor is made to Copy or move another instance is as  operator overloading supplied too.
 *
 */
class CTypedVariant : protected CVariant
{
	private:
		// Store data type of Variant
		const char * m_DataTypeId;

	protected:
		CTypedVariant(const char * const typeId,size_t size = 0);

	public:

		//Default Constructor
		CTypedVariant();

		/**
		 * Copy Constructor
		 */
		CTypedVariant(const CTypedVariant & var);

		/**
		 * Move Constructor
		 */
		CTypedVariant(CTypedVariant && var);

		/**
		 * Virtual destructor
		 */
		virtual ~CTypedVariant();

		/**
		 * Copy Operator
		 */
		CTypedVariant & operator = (const CTypedVariant & var);
		/**
		 * Move operator
		 */
		CTypedVariant & operator = (CTypedVariant && var);

		/**
		 * Return TypedId of CTypedVariant
		 */
		const char * getTypeId() const;

		/**
		 * Copy CTypedVariant to this
		 */
		void copy(const CTypedVariant & var);
		/**
		 * Move CTypedVariant var to this and set var to null so cannot be destroyed
		 */
		void move(CTypedVariant && var);
		
};

#endif
