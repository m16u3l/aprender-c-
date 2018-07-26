#include "lib_string.h"
#include <iostream>

using namespace std;
lib_string::lib_string(std::string t_value)
:value{t_value}
{
	
}

std::string lib_string::to_string()const
{
		return value;
}


bool lib_string::operator==(const lib_object& obj)const
{
	cout<<"string"<<endl;
	return value==((lib_string&)obj).value;
}