/**
 *
 * @author I Putu Gede Darmawan S.Kom
 * @email darmawan@bali-electro.com
 *
 */
#ifndef CVARIANT_HPP
#define CVARIANT_HPP

#include <cstring>
#include <cstddef>
#include <stdexcept>
#include <iostream>

using namespace std;

/**
 * CVariant enables user to store any kind of data.
 * This functionality is achieved by using dynamic memory allocation at runtime
 *
 */
class CVariant
{
	private:
		/**
		 * Pointer to data
		 * Size of allocated memory stored in m_Data size member
		 */
		void * m_pData;

		/**
		 * Size of data allocated for m_pData
		 */
		size_t m_DataSize;

	protected:

	public:

		/**
		 * Construct an empty CVariant
		 * Set internal data to nullptr and 0.
		 */
		CVariant();

		/**
		 * Destroy Created CVariant by releasing its allocated resource
		 * This destructor calls clear method to clear its allocated 
		 * resource
		 */
		virtual ~CVariant();

		/**
		 * Construct CVariant from another CVariant
		 * Data is deep copied not just its pointer.
		 */
		CVariant(const CVariant & source);

		/**
		 * Move constructor
		 * Construct Object by moving it from source CVariant.
		 * Source CVariant will lose its ownership to data.
		 */
		CVariant(CVariant && source);

		/**
		 * Copy CVariant from another CVariant with assignment operator
		 * @return
		 * Reference pointed by this
		 */
		virtual CVariant & operator = (const CVariant & source);

		/**
		 * Move CVariant by moving it from source
		 */
		virtual CVariant& operator = (CVariant && source);

		/*
		 * Set By Copy from another CVariant source
		 */
		virtual void set(const CVariant & source);

		/**
		 * Set By Move from another CVariant source
		 */
		virtual void set(CVariant && source);

		/*
		 * Allocate data with dataSize
		 */
		void alloc(size_t dataSize);

		/**
		 * Write to allocate dataSize
		 */
		void write(const void * pData);

		/**
		 * copy Data from CVariant into pData
		 * return true if internal data is not null otherwise false,
		 * no data is read.
		 */
		bool read(void * pData);

		/**
		 * Clearing internal's allocated data and set it to nullptr and 0
		 */
		void deAlloc();

		/**
		 * Return size of data
		 * CVariant get is Size when method set is called.
		 */
		size_t getSize() const;

		/**
		 * Test wheter internal variable is null
		 */
		bool isNull();
};

#endif
