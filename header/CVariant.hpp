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
		size_t m_Size;

	protected:

		/**
		 * Return internal data
		 */
		void * getPData();

	public:

		/**
		 * Default Constructor
		 * Create CVariant instance without allocating memory CVariant(0)
		 */
		CVariant();

		/**
		 * Copy Constructor
		 * Create duplicate copy from another CVariant instance
		 * Memory is allocated and data is write from supplied
		 * This method call copy(const CVariant & var)
		 */
		CVariant(const CVariant & var);

		/**
		 * Move Constructor
		 */
		CVariant(CVariant && var);


		/**
		 * Construct a CVariant with size size
		 * If size is 0, no memory is allocated. pData is null
		 */
		CVariant(size_t size);

		/**
		 * Destroy Created CVariant by releasing its allocated resource
		 * This destructor calls clear method to clear its allocated 
		 * resource
		 */
		virtual ~CVariant();

		/**
		 * Copy Operator
		 */
		CVariant & operator = (const CVariant & var);

		/**
		 * Move Operator
		 */
		CVariant & operator = (CVariant && var);

		/**
		 * Allocate memory with size size
		 * if it is been allocated, free before.
		 * if size is 0 nothing done but return false
		 * @return 
		 * true if memory is successfully allocated otherwise false
		 */
		bool alloc(size_t size);

		/**
		 * Write to allocate dataSize
		 * @return
		 * if successfull write return true, otherwise false
		 */
		bool write(const void * pData);

		/**
		 * copy Data from CVariant into pData
		 * return true if internal data is not null otherwise false,
		 * no data is read.
		 * @return
		 * successfull write return true otherwise false
		 */
		bool read(void * pData);

		/**
		 * Release memory allocated and set internal to null
		 */
		void deAlloc();

		/**
		 * Return size of data
		 * CVariant get is Size when method set is called.
		 * If size == 0 no memory is allocated
		 */
		size_t getSize() const;

		/**
		 * Copy another instance of CVariant
		 */
		void copy(const CVariant & var);

		/**
		 * Move another instance to this
		 */
		void move(CVariant && var);

};

#endif
