#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int main ()
{
  string str = "algo que pasa xd";
  char * pch;
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
      cout << typeid(pch).name()<<endl;
      pch = strtok (NULL, " ,.-");
  }
  return 0;
}