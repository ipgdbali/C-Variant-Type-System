#include "CSimpleType.hpp"
#include "CCString.hpp"
#include <cassert>

int main(int argc,char * argv[])
{

	CCString s;
	char * str2;

	s = "Apa Kabar";
	assert(s.length() == 9);

	char str[200] = "Holla";
	assert(strcmp(str,"Holla") == 0);
	str2 = str;
	assert(strcmp(str2,"Holla") == 0);
	
	s.get((char**)str2);
	assert(strcmp(str,"Apa Kabar") == 0);

	return 0;
}
