#ifndef LIB_ARRAY_LIST_H
#define LIB_ARRAY_LIST_H
#include "lib_object.h"
class lib_array_list
{
	size_t len;
	size_t sizememory;
	lib_object** objs;//es un array que cada tipo es de lib_object
	
public:
	
	lib_array_list();
	void add(lib_object* obj);
	int find(const lib_object& obj) const;
	lib_object& get(size_t pos);
	size_t length()const;
};
#endif