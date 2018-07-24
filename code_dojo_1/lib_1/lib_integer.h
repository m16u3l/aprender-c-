#ifndef __LIB_INTEGER_H
#define __LIB_INTEGER_H

#include <string>
#include "lib_object.h"

class lib_integer: public lib_object 
{
	size_t value;
	
public:
	lib_integer(size_t value);
	std::string to_string() const;
};
#endif