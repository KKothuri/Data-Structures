#include <iostream>
#include "../../util/Pair.h"
#include "../../util/Vector.h"
int main()
{
    Vector<int> arr(20, 1);
    for(int i = 0; i < 20; i++)
        std::cout << arr[i] << "\n";
}