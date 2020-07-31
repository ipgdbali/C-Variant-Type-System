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

		void * getPData();

	public:

		/**
		 * Default Constructor
		 */
		CVariant();

		/**
		 * Construct a CVariant
		 */
		CVariant(size_t size);

		/**
		 * Destroy Created CVariant by releasing its allocated resource
		 * This destructor calls clear method to clear its allocated 
		 * resource
		 */
		virtual ~CVariant();

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
		 */
		size_t getSize() const;

};

#endif
