#ifndef CCSTRING_HPP
#define CCSTRING_HPP

#include "CStrongTyped.hpp" 

class CCString : public CStrongTyped
{
	private:

	protected:

	public:
		CCString();
		CCString(const char * val);

		// Copy Constructor
		CCString(const CStrongTyped & val);

		// Move Construtor
		CCString(CStrongTyped && val);


		void set(const char * val);
		void get(char * val);

		size_t length() const;

		operator const char *();
};

#endif
