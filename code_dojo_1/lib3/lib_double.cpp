#include "lib_double.h"
#include <iostream>
#include <string>

using namespace std;

lib_double::lib_double(double value):value{value}
{
	
}
std::string lib_double::to_string()const
{
		return std::to_string(value);
	
}

bool lib_double::operator ==(const lib_object& obj)const
{
	cout<<"double"<<endl;
	return value==((lib_double&)obj).value;
}