#include <iostream>

using namespace std;

int& mayor(int& a, int& b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main(int argc, char const *argv[])
{
	int x, y;
	cin >> x >> y;

	mayor(x, y) = 3;

	cout << x << " " << y <<endl;
	return 0;
}