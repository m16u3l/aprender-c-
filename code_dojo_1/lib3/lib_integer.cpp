#include "lib_integer.h"
#include <iostream>

using namespace std;

lib_integer::lib_integer(size_t value):value{value}
{
	
}
std::string lib_integer::to_string()const
{
		return std::to_string(value);
}
bool lib_integer::operator==(const lib_object& obj)const
{
	cout<<"integer"<<endl;
	return value==((lib_integer&)obj).value;
}