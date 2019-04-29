#include <iostream>
#include "../../util/Vector.h"

using namespace std;

int main()
{
	Vector<Vector<int>> arr(5, Vector<int>(4, 3));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}