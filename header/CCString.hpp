#ifndef CCSTRING_HPP
#define CCSTRING_HPP

#include "CTypedVariant.hpp" 

class CCString : public CTypedVariant
{
	private:

	protected:

	public:
		CCString();
		CCString(const char * val);

		// Copy Constructor
		CCString(const CTypedVariant & val);

		// Move Construtor
		CCString(CTypedVariant && val);


		void set(const char * val);
		void get(char * val);

		size_t length() const;

		operator const char *();
};

#endif
