#ifndef CTYPEDVARIANTADAPTER_HPP
#define CTYPEDVARIANTADAPTER_HPP

#include "CTypedVariant.hpp"
#include <map>

using namespace std;

class CTypedVariantAdapter
{
	private:
		CTypedVariant & m_TypedVariant;
		size_t m_TypeVariantId;
		bool m_TypeChangeable;

		static map<const char *,size_t> m_MapperStringIdToId;
		static size_t getTypeVariantId(const char * strIdName);

	protected:
		CTypedVariantAdapter(CTypedVariant & typedVariant,const char * pStringTypedVariant,bool typeChangeable = true);

		CTypedVariant & getTypedVariant();

	public:


		size_t getTypeVariantId() const;

};


#endif
