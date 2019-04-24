#ifndef VECTOR_H
#define VECTOR_H

#define ull unsigned long long int

//Vector class to function like the STL vector class
template <class Object>

class Vector
{
protected:
	ull size;
	Object* elements;
	ull capacity;
public:
	Vector() : size(0), capacity(0), elements(NULL) {};
	Vector(ull size)
	{
		try
		{
			if (size < 0)
				throw size;
			else
			{
				this.size = size;
				capacity = size > 1 ? size : 1;
				elements = new Object[capacity];
			}
		}
		catch (ull x)
		{
			cout << "Invalid initialisation size of " << x << " for a Vector.\nInitialising with default constructor.\n";
			Vector();
		}
	}
};

#undef ull

#endif