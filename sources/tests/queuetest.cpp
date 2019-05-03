#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	while(a.size() != 0)
    {
        cout << a.front();
        a.pop();
    }
}
