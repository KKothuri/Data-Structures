#include <iostream>
#include "../../util/Vector.h"
#include "../../util/String.h"

using namespace std;

int main()
{
	Vector<String> arr(5, "Hello");
	cin >> arr[1];
	for (int i = 0; i < 5; i++)
	{
		if (i)
			arr[i] += arr[i - 1];
		cout << arr[i] << "\n";
	}
}