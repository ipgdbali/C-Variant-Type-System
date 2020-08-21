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
class CTypedVariant : public CVariant
{
	private:

		// Store data type of Variant
		const char * m_TypeId;

	protected:

	public:

		/**
		 * Create CTypedVariant with type typeId and sizes size
		 * Also function as default constructor  ?
		 */
		CTypedVariant(const char * typeId = nullptr,size_t size = 0);

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
		bool copy(const CTypedVariant & var,bool reserveType=false);

		/**
		 * Move CTypedVariant var to this and set var to null
		 */
		bool move(CTypedVariant && var,bool reverseType=false);

		/**
		 * Set TypeId
		 */
		void setTypeId(const char * typeId);
		/**
		 * Return TypedId of CTypedVariant
		 */
		const char * getTypeId() const;
		
};

#endif
