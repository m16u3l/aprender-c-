#include <iostream>
#include "lib_object.h"
#include "lib_array_list.h"
#include "lib_integer.h"
#include "lib_string.h"
#include "lib_double.h"

using namespace std;

int main()
{
	lib_array_list objs;
	
	objs.add(new lib_string("Hello Friend"));
	objs.add(new lib_string("World Cruel"));
	objs.add(new lib_string("Yeah!"));
	objs.add(new lib_string("AAAA"));
	objs.add(new lib_integer(3));
	objs.add(new lib_integer(60));
	objs.add(new lib_double(3));
	objs.add(new lib_integer(0x41414141));
	
	auto len = objs.length();
	cout << "Tamano de la lista: " << len << endl; 
	for (auto i = 0U; i < len; i++)
	{
		cout << objs.get(i).to_string().data() << "\n";
	}

	lib_double p {3};
	lib_string p1{"3"};
	lib_integer p2{0x41414141}; 
	auto pos = objs.find(p);
	auto pos1 = objs.find(p1);
	auto pos2 = objs.find(p2);
	cout << "Position: " << pos << "\n";
	cout << "Position: " << pos1 << "\n";
	cout << "Position: " << pos2 << "\n";
	return 0;
}