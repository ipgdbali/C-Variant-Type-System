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
 * CVariant enables storing any kind of data.
 * This functionality is achieved by using dynamic memory allocation at runtime
 *
 */
class CVariant
{
	private:
		void * m_pData;
		size_t m_DataSize;

	protected:

	public:

		//Contruc an empty CVariant
		CVariant();
		virtual ~CVariant();

		//Copy Constructor
		CVariant(const CVariant & value);
		//Copy Operator
		CVariant & operator = (CVariant & value);

		//Move Constructor
		CVariant(CVariant && value);
		//Move Operator
		CVariant& operator = (CVariant && value);

		//Construct with some value
		CVariant(const void * pData,size_t dataSize);

		/*
		 * Set CVariant with data from another CVariant)
		 */
		void set(const CVariant & value);

		/*
		 * Set CVariant Data with data
		 */
		void set(const void * pData,size_t dataSize);

		/**
		 * Return size of data
		 */
		size_t getSize();

		/**
		 * copy Data from CVariant into pData
		 *
		 */
		void get(void * pData);

		/**
		 * Clearing internal's allocated data
		 */
		void clear();
};

#endif
