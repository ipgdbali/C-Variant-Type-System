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
 * CVariant enables user to store data on heap
 * This functionality is achieved by using dynamic memory allocation at runtime
 * User specify size to be allocated on custructor or alloc method.
 * If memory has been allocated while calling alloc,deAlloc is called to free
 * previous memory before allocating new memory
 * Supplying size to 0 will do nothing.
 * On succes CVariant::alloc return true.
 * 
 * Whether memory allocation status is not known at specific memont,
 * use isNull or isNotNull method. Null means memory has not been allocated 
 * and its size is 0
 *
 * On destruction / destructor called, method deAlloc is called. This method 
 * release allocated memory.
 * Memory is release when destrutor is called or by calling deAlloc method
 *
 * To write us method CVariant::write. Specific memory to be written along 
 * with size and its offset.
 * So as write, read also has same signature thus has same meaning
 *
 * Duplication, use method CVariant::copy, Copy Construcor, Copy Operator (=&)
 * To move, use method CVariant::move,Move Constructor and Move operator (=&&)
 * There is no way for CVariant instances to point the same memory
 *
 */
class CVariant
{
	private:
		/**
		 * Pointer to data
		 * Size of allocated memory stored in m_Data size member
		 */
		unsigned char * m_pData;

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
		 * Construct a CVariant with size size
		 * if no size supplied this constructor will act as default constructor
		 * which means no memory is allocated. 
		 */
		CVariant(size_t size = 0);

		/**
		 * Copy Constructor
		 * Create duplicate copy from another CVariant instance
		 * Memory is allocated and data is write from supplied
		 * This method call CVariant::copy(const CVariant & var)
		 */
		CVariant(const CVariant & var);

		/**
		 * Move Constructor
		 * Move data from var to this.
		 * No memory is allocated but swapped.
		 * This method call CVariant::move(CVariant && var)
		 */
		CVariant(CVariant && var);



		/**
		 * Destroy Created CVariant by releasing its allocated resource
		 * This destructor calls CVariant::deAlloc()
		 * resource
		 */
		virtual ~CVariant();

		/**
		 * Copy Operator
		 * Make duplicate of CVariant instance
		 * This method call CVariant::copy
		 */
		CVariant & operator = (const CVariant & var);

		/**
		 * Move Operator
		 * Move data from var to this
		 * This method call CVariant::move
		 */
		CVariant & operator = (CVariant && var);

		/**
		 * Test condition whether memory has been allocated
		 * If memory has been successfully allocated,
		 * pData is not null and this method return false
		 */
		bool isNull();

		/**
		 * Test condition whether memory has been allocated
		 * If memory has been successfully allocated,
		 * pData is not null and this method return true
		 */
		bool isNotNull();

		/**
		 * Allocate memory with sizes size
		 * if memory has been allocated, memory is freed by calling deAlloc
		 * if size == 0 nothing done, return false.
		 * sucessfully allocated memory return true
		 */
		bool alloc(size_t size);

		/**
		 * Write data to Internal memory with sizes size and internal offsets
		 * offset.
		 * If size == 0 then this->getSize() is used
		 */
		bool write(const void * pData,size_t size = 0,size_t offset = 0);

		/**
		 * copy Data from CVariant into pData
		 * return true if internal data is not null otherwise false,
		 * and no data is read.
		 * if size == 0 then size = this->getSize();
		 * @return
		 * successfull write return true otherwise false
		 */
		bool read(void * pData,size_t size = 0,size_t offset = 0);

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
		 * If this still not yet allocated, copy will alocated it.
		 */
		void copy(const CVariant & var);

		/**
		 * Move another instance to this
		 */
		void move(CVariant && var);

};

#endif
