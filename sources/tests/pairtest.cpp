#include <iostream>
#include "../../util/Pair.h"
int main()
{
	Pair<int, int> a, c;
	a.first = 1;
	a.second = 2;
	Pair<int, int> b(a);
	c = b = a;
	std::cout << c.first << " " << c.second << " " << (c == a);
}