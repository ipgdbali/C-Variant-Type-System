#include "CVariant.hpp"

void * CVariant::getPData()
{
	return this->m_pData;
}

/**
 * Default Constructor
 */
CVariant::CVariant() : CVariant(0)
{
}

CVariant::CVariant(size_t size) :
	m_pData(nullptr),m_Size(size)
{
	this->alloc(size);
}

/**
 * Virtual Destructor
 */
CVariant::~CVariant()
{
	this->deAlloc();
}

bool CVariant::alloc(size_t size)
{
	if(size == 0)
		return false;

	this->m_Size = size;

	// release previous allocated memory
	if(this->m_pData != nullptr)
		this->deAlloc();

	// reserve memory 
	this->m_pData = calloc(1,size);

	// return status
	if(this->m_pData != nullptr)
		return true; // success
	else
		return false; // unsuccessfull
}

bool CVariant::write(const void * pData)
{
	// if pData has been allocated before
	if(this->m_pData != nullptr)
	{
		// copy data
		memcpy(this->m_pData,pData,this->m_Size);

		// return true
		return true;
	}
	else
		// otherwise no copy and return false
		return false;
}

bool CVariant::read(void * pData)
{
	// if pData has been allocated before
	if(m_pData != nullptr)
	{
		// copy data 
		memcpy(pData,m_pData,this->m_Size);

		// return true
		return true;
	}
	else
		//otherwise do not copy data and return false
		return false;
}

void CVariant::deAlloc()
{
	// only de allocate memory if pData is null ptr and Size != 0
	if(this->m_pData != nullptr && this->m_Size != 0)
	{
		// release memory
		free(this->m_pData);

		// set internal data to null ptr and 0
		this->m_pData = nullptr;
		this->m_Size = 0;
	}
}

size_t CVariant::getSize() const
{
	return this->m_Size;
}
