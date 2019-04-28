#include <iostream>
#include "Pair.h"
#include "Vector.h"
int main()
{
	Vector<Pair<int, int>> v;
	v.push_back(makePair(2, 3));
}