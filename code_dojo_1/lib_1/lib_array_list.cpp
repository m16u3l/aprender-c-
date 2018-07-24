#include "lib_array_list.h"
#include <cstdio>

lib_array_list::lib_array_list()
:len{0}, sizememory{4}, objs{new lib_object[4]}
{
	
}

void lib_array_list::add(lib_object* obj)
{
	if (len<sizememory)
	{
		objs[len] = *obj;
		len++;
	}
	else
	{
		size_t aux;
		aux = 2*sizememory;
		auto array_aux = new lib_object[aux];
		for(size_t i = 0; i < len; i++)
		{
			array_aux[i] = objs[i];
		}		
		delete []objs;
		objs = array_aux;
		objs[len++] = *obj;
		sizememory = aux;
	}
}

int lib_array_list::find(lib_object& obj)
{
	return 0;	
}

lib_object lib_array_list::get(size_t pos)
{
	return lib_object{};
}

size_t lib_array_list::length()
{
		return 0;	
}
