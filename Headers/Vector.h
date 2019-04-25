#ifndef VECTOR_H
#define VECTOR_H

#define ull unsigned long long int

//Vector class to mimic the STL vector class
template <class Object>

class Vector
{
protected:
	static ull maxsize = 4611686018427387903;
	ull size;
	Object* elements;
	ull capacity;
public:
	Vector() : size(0), capacity(0), elements(NULL) {};
	Vector(ull size);
	Vector(const Vector& v);
	~Vector() { if(elements) delete[] elements; }
	Object& operator[] (ull index);
	ull max_size() { return maxsize; }
	ull size() { return size; }
	ull capacity() { return capacity; }
	void resize(ull size);
	void push_back(Object& x);
	void pop_back();
};

template <class Object>

Vector<Object>::Vector(ull size)
{
	try
	{
		if (size < 0)
			throw size;
		else
		{
			this.size = size;
			capacity = size;
			elements = capacity ? new Object[capacity] : NULL;
		}
	}
	catch (ull x)
	{
		cout << "Invalid initialisation size of " << x << " for a Vector.\nInitialising with default constructor.\n";
		Vector();
	}
}

template <class Object>

Vector<Object>::Vector(const Vector& v)
{
	size = v.size;
	capacity = v.capacity;
	elements = capacity ? new Object[capacity] : NULL;
	for (ull i = 0; i < size; i++)
		element[i] = v[i];
}

template <class Object>

Object& Vector<Object>::operator[] (ull index)
{
	try
	{
		if (index >= size)
			throw index;
		else return elements[index];
	}
	catch (ull x)
	{
		cout << "Invalid index " << x << ".\n";
		Vector();
	}
}

template <class Object>

void Vector<Object>::resize(ull size)
{
	capacity = size;
	Object* temp = capacity ? new Object[capacity] : NULL;
	for (ull i = 0; i < min(size, this.size); i++)
		temp[i] = elements[i];
	if (elements)
		delete[] elements;
	elements = temp;
	this.size = size;
}

template <class Object>

void Vector<Object>::push_back(Object& x)
{
	if (capacity > size)
		elements[size++] = x;
	else
	{
		try
		{
			if (capacity * 2 > maxsize)
				throw 1;
			capacity *= 2;
			Object* temp = new Object[capacity];
			for (ull i = 0; i < size; i++)
				temp[i] = elements[i];
			temp[size++] = x;
			delete[] elements;
			elements = temp;
		}
		catch (int ec)
		{
			if (ec == 1)
				cout << "Max size reached\n";
		}
	}
}

template <class Object>

void Vector<Object>::pop_back()
{
	try
	{
		if (size <= 0)
			throw 2;
		size--;
	}
	catch (int ec)
	{
		if (ec == 2)
			cout << "No elements in Vector\n";
	}
}

#undef ull

#endif