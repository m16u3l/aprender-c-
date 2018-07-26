#include <iostream>
#include "lib_object.h"
#include "lib_array_list.h"
#include "lib_string.h"
#include "lib_double.h"
#include "lib_integer.h"


using namespace std;

int main()
{
	lib_array_list objs;
	
	objs.add(new lib_string("Hello"));
	objs.add(new lib_string("World"));
	objs.add(new lib_integer(25));
	objs.add(new lib_double(3.14156926539));
	
	auto len = objs.length();
	for (auto i = 0U; i < len; i++)
	{
		cout << objs.get(i).to_string().data() << "\n";
	}

	lib_integer p { 25 };
	auto pos = objs.find(p);
	cout << "Position: " << pos << "\n";
	
	return 0;
}
