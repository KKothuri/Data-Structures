#ifndef PAIR_H
#define PAIR_H

//Pair class to mimic the STL pair class
template <class Obj1, class Obj2>

class Pair
{
public:
	Obj1 first;
	Obj2 second;
	Pair() {};
	Pair(const Obj1& f, const Obj2& s) : first(f), second(s) {}
	Pair(const Pair& p) : first(p.first), second(p.second) {}
	Pair& operator= (const Pair& p)
	{
		first = p.first;
		second = p.second;
		return *this;
	}
	bool operator== (const Pair& p2) const
	{
		return first == p2.first && second == p2.second;
	}
	bool operator!= (const Pair& p1, const Pair& p2) const
	{
		return !(p1 == p2);
	}
	bool operator> (const Pair& p1, const Pair& p2) const
	{
		return p1.first > p2.first ? true : p1.first == p2.first ? p1.second > p2.second : false;
	}

	bool operator>= (const Pair& p1, const Pair& p2) const
	{
		return !(p1 < p2);
	}

	bool operator< (const Pair& p1, const Pair& p2) const
	{
		return p1.first < p2.first ? true : p1.first == p2.first ? p1.second < p2.second : false;
	}

	bool operator<= (const Pair& p1, const Pair& p2) const
	{
		return !(p1 > p2);
	}
};

template <class Obj1, class Obj2>

Pair<Obj1, Obj2> makePair(const Obj1& f, const Obj2& s)
{
	return Pair<Obj1, Obj2>(f, s);
}

#endif
