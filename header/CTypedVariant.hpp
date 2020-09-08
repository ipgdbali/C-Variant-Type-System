#ifndef CTYPEDVARIANT_HPP
#define CTYPEDVARIANT_HPP

#include "CVariant.hpp"

/*
 * CTypedVariant
 *
 * Special class derived from CVariant with type capability.
 *
 * There are 2 variant for move / copy operation
 * one that reserve previous type and the other not
 *
 */
class CTypedVariant : protected CVariant
{
	private:

		// Store data type of Variant
		const char * m_TypeId;

	protected:

		/**
		 * Set TypeId
		 */
		void setTypeId(const char * typeId);

	public:

		/**
		 * Create CTypedVariant with type typeId and sizes size
		 * Also function as default constructor
		 */
		CTypedVariant(const char * typeId = "DT_NOT_DEFINED",size_t size = 0);

		/**
		 * Virtual destructor
		 */
		virtual ~CTypedVariant();

		/**
		 * Copy Constructor
		 * Used to check var with type typeid
		 */
		CTypedVariant(const CTypedVariant & var,const char * typeId = nullptr);

		/**
		 * Move Constructor
		 */
		CTypedVariant(CTypedVariant && var,const char * typedId = nullptr);

		/**
		 * Copy CTypedVariant to this
		 * if reverseType is true, var should have the same type with this.
		 * @return 
		 *	true - if copy is succeeded otherwise false
		 */
		virtual bool copy(const CTypedVariant & var) = 0;

		/**
		 * Move CTypedVariant var to this and set var to null
		 */
		virtual bool move(CTypedVariant && var) = 0;

		/**
		 * Return TypedId of CTypedVariant
		 */
		const char * getTypeId() const;
		
};

#endif
