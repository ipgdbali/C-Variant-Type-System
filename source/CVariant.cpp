#include "CVariant.hpp"

void * CVariant::getPData()
{
	return this->m_pData;
}

/**
 * Default Constructor
 * Init nullptr internal data with size 0
 */
CVariant::CVariant() : CVariant(0)
{
}

// Copy Constructor
CVariant::CVariant(const CVariant & var)
{
	this->copy(var);
}

CVariant::CVariant(CVariant && var)
{
	this->move(std::move(var));
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

CVariant & CVariant::operator = (const CVariant & var)
{
	this->copy(var);
	return *this;
}

CVariant & CVariant::operator = (CVariant && var)
{
	this->move(std::move(var));
	return *this;
}

bool CVariant::isNull()
{
	return this->m_pData == nullptr && this->m_Size == 0;
}

bool CVariant::isNotNull()
{
	return !(this->m_pData == nullptr && this->m_Size == 0);
}

bool CVariant::alloc(size_t size)
{
	if(size == 0)
		return false;

	// release previous allocated memory
	if(!this->isNull())
		this->deAlloc();

	this->m_Size = size;

	// allocate memory 
	this->m_pData = (unsigned char*)calloc(1,this->getSize());

	// return status
	if(!this->isNull())
		return true; // success
	else
		return false; // unsuccessfull
}

bool CVariant::write(const void * pData,size_t size,size_t offset)
{
	if(size == 0)
		size = this->getSize();

	// if pData has been allocated and offset + size dont exceeded allocated
	if(this->isNotNull() && (offset + size <= this->getSize()))
	{
		// copy data
		memcpy(this->m_pData + offset,pData,size);

		// return true
		return true;
	}
	else
		// otherwise no copy and return false
		return false;
}

bool CVariant::read(void * pData,size_t size,size_t offset)
{
	//If size is not specified, set all alocated
	if(size == 0)
		size = this->getSize();

	// if pData has been allocated before
	if(!this->isNull() && (offset + size <= this->getSize()))
	{
		// copy data 
		memcpy(pData,m_pData + offset,size);

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
	if(!this->isNull() && this->getSize() != 0)
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

void CVariant::copy(const CVariant & var)
{
	this->deAlloc();
	this->alloc(var.m_Size); // automatic deletin of old 
	this->write(var.m_pData);
}

void CVariant::move(CVariant && var)
{
	std::swap(m_pData,var.m_pData);
	std::swap(m_Size,var.m_Size);
}
