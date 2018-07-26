#ifndef __LIB_DOUBLE_H
#define __LIB_DOUBLE_H
#include "lib_object.h"
#include <string>

class lib_double: public lib_object
{
	double value;
	
public:
	lib_double(double value);
	std::string to_string() const;
	bool operator ==(const lib_object&)const override;
};
#endif