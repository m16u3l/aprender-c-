#ifndef __LIB_DOUBLE_H
#define __LIB_DOUBLE_H

#include <string>
#include "lib_object.h"
class lib_double: public lib_object
{
	double value;
	
public:
	lib_double(double value);
	std::string to_string() const;
};
#endif