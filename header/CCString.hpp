#ifndef CCSTRING_HPP
#define CCSTRING_HPP

#include "CStrongTyped.hpp" 

class CCString : public CStrongTyped
{
	public:

		static const char * const TYPE_ID;

		// Default Constructor
		CCString();

		// Copy Constructor
		CCString(const CCString & var);
		CCString(const CStrongTyped & var);
		CCString(const CTypedVariant & var);


		// Move Construtor
		CCString(CCString && val);

		//
		// Setter
		//
		
		// Construct CCStrong from const char *
		CCString(const char * val);
		void set(const char * val);
		CCString & operator = (const char * val);

		//gettter
		void get(char * val);
		size_t length() const;

	protected:

	private:


};

#endif
