#include <iostream>

int main(int argc, char const *argv[])
{
	lib_array_list objs;

	objs.add(new lib_string("Hello"));
	objs.add(new lib_string("World"));
	
	objs.add(new lib_integer(25));

	objs.add(new lib_double(3.14156926539));

	auto len = objs.length();

	for (auto i = OU; i < len; i++)
	{
		cout << objs.get(i).to_string().data() << "\n";
	}

	lib_integer p{25};
	auto pos = objs.find(p);
	cout << "Position: " << pos <<"\n";
	return 0;
}