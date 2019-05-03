#include <iostream>
#include "../../containers/XORList.h"

using namespace std;

int main()
{
	XORList<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	cout << a.find(4).first;
	a.removeAt(1);
	cout << a.find(2).first;
}
