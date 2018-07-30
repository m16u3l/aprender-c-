#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int *p1;

	for (int i = 0; i < 10000; ++i)
	{
		p1 = new int;
	}

	p1 = new int[9999];	//esta memoria no es utilizable
	p1 = new int;

	cout << *p1 << endl;
	return 0;
}
