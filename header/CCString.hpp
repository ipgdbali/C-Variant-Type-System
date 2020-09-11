#ifndef CCSTRING_HPP
#define CCSTRING_HPP

#include "CStrongTyped.hpp" 

class CCString : public CStrongTyped
{
	public:

		static const char * const TYPE_ID;

		// Default Constructor
		CCString();

		// Construct CCStrong from const char *
		CCString(const char * val);

		// Copy Constructor
		CCString(const CCString & val);

		// Move Construtor
		CCString(CCString && val);

		//setter
		void set(const char * val);
		CCString & operator = (const char * val);

		//gettter
		void get(char * val);

		size_t length() const;

	protected:

	private:


};

#endif
