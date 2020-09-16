#ifndef CCSTRING_HPP
#define CCSTRING_HPP

#include "CSimpleType.hpp" 

class CCString : public CSimpleType<char*>
{
	public:

		// Default Constructor
		CCString();

		// Copy Constructor
		CCString(const CCString & var);
		CCString(const CSimpleType<char*> & var);
		CCString(const CStrongTyped & var);
		CCString(const CTypedVariant & var);


		// Move Construtor
		CCString(CCString && val);

		//
		// Setter
		//
		
		// Construct CCStrong from const char *
		CCString(const char * val);
		CCString & operator = (const char * val);
		virtual bool set(const char * val);

		//
		// Getter
		//
		virtual bool get(char ** val);
		size_t length() const;

	protected:

	private:

};

#endif
