#ifndef VECTOR_H
#define VECTOR_H

#define ull unsigned long long int

//Vector class to mimic the STL vector class
template <class Object>

class Vector
{
public:
	//Iterator base class
	class Iterator;

	//ForwardIterator for inorder traversal
	class ForwardIterator : public Iterator;

	//BackwardIterator for reverse traversal
	class BackwardIterator : public Iterator;
private:
	static const ull maxsize = 4611686018427387903;
	ull size;
	Object* elements;
	ull capacity;
	static ForwardIterator end = new Object;
	static BackwardIterator rend = new Object;
public:
	Vector() : size(0), capacity(0), elements(NULL) {}
	Vector(ull size);
	Vector(const Vector& v);
	~Vector() { if (elements) delete[] elements; }
	Vector& operator= (const Vector& p)
		bool operator== (const Vector& p1, const Vector& p2) const;
	Object& operator[] (ull index);
	ull max_size() const { return maxsize; }
	ull size() const { return size; }
	ull capacity() const { return capacity; }
	void resize(ull size);
	void push_back(Object& x);
	void pop_back();
	void clear() { if (elements) delete[] elements; elements = capacity = size = NULL; }
	void erase(ull i);
	void erase(ull i, ull j);
	ForwardIterator begin() { return ForwardIterator(elements); }
	ForwardIterator end() { return end; }
	BackwardIterator rbegin() { return ForwardIterator(elements + size - 1); }
	BackwardIterator rend() { return rend; }
};

template <class Object>

class Vector<Object>::Iterator
{
	friend class Vector<Object>;
protected:
	Object* ptr;
	Iterator(Object* p) : ptr(p) {};
public:
	Iterator() : ptr(NULL) {}
	Iterator(Iterator p) { ptr = p.isNull() ? NULL : &(*p) }
	bool operator== (const Iterator& it1, const Iterator& it2)
	{
		return (it1.isNull() && it2.isNull()) || *it1 == *it2;
	}
	Iterator& operator= (const Iterator& it)
	{
		ptr = it.isNull() ? NULL : &(*p);
		return *this;
	}
	Object* operator->() { return ptr; }
	Object& operator*();
	bool isNull() { return ptr; }
};

template <class Object>

Object& Vector<Object>::Iterator::operator*()
{
	try
	{
		if (ptr)
			return *ptr;
		else throw 1;
	}
	catch (int x)
	{
		if (x == 1)
			cout << "NULL Iterator\n";
	}
}

//ForwardIterator for inorder traversal
template <class Object>

class Vector<Object>::ForwardIterator : public Vector<Object>::Iterator
{
	friend class Vector<Object>;
protected:
	ForwardIterator(Object* p) : Iterator(p) {};
public:
	ForwardIterator() : Iterator() {}
	ForwardIterator(Iterator p) : Iterator(p) {}
	ForwardIterator& operator= (const Iterator& it)
	{
		ptr = it.isNull() ? NULL : &(*p);
		return *this;
	}
	void operator++();
};

template <class Object>

void Vector<Object>::ForwardIterator::operator++()
{
	try
	{
		if (*ptr == *end)
			throw 1;
		if (ptr != elements + size - 1)
			ptr++;
		else
			ptr = &(*end);
	}
	catch (int x)
	{
		if (x == 1)
			cout << "Already at end.\n";
	}
}

//BackwardIterator for reverse traversal
template <class Object>

class Vector<Object>::BackwardIterator : public Vector<Object>::Iterator
{
	friend class Vector<Object>;
protected:
	BackwardIterator(Object* p) : Iterator(p) {};
public:
	BackwardIterator() : Iterator() {}
	BackwardIterator(Iterator p) : Iterator(p) {}
	BackwardIterator& operator= (const Iterator& it)
	{
		ptr = it.isNull() ? NULL : &(*p);
		return *this;
	}
	void operator++();
};

template <class Object>

void Vector<Object>::BackwardIterator::operator++()
{
	try
	{
		if (*ptr == *rend)
			throw 1;
		if (ptr != elements)
			ptr--;
		else
			ptr = &(*rend);
	}
	catch (int x)
	{
		if (x == 1)
			cout << "Already at rend.\n";
	}
}

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

Vector& Vector<Object>::operator= (const Vector& p)
{
	resize(p.size());
	for (int i = 0; i < p.size(); i++)
		elements[i] = p[i];
}

template <class Object>

bool Vector<Object>::operator== (const Vector& p1, const Vector& p2) const
{
	bool ans = p1.size == p2.size;
	for (int i = 0; i < p1.size(); i++)
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
		if (size = 0)
			throw 1;
		size--;
	}
	catch (int ec)
	{
		if (ec == 1)
			cout << "No elements in Vector\n";
	}
}

void Vector<Object>::erase(ull i)
{
	try
	{
		if (i < 0 || i >= size)
			throw 1;
		for (int t = i; t < size - 1; t++)
			elements[t] = elements[t + 1];
		size--;
	}
	catch (int ec)
	{
		if (ec == 1)
			cout << "Index out of Bounds\n";
	}
}

void Vector<Object>::erase(ull i, ull j)
{
	try
	{
		if (i < 0 || i > j || j >= size)
			throw 1;
		for (int t = i; t < size - j - 1; t++)
			elements[t] = elements[t + j - i + 1];
		size -= j - i + 1;
	}
	catch (int ec)
	{
		if (ec == 1)
			cout << "Indices out of Bounds\n";
	}
}

#undef ull

#endif