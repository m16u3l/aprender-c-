#ifndef __LIB_STRING_H
#define __LIB_STRING_H

#include <string>
#include "lib_object.h"

class lib_string: public lib_object
{
	std::string value;
	
public:
	lib_string(std::string value);
	std::string to_string() const;
};
#endif
