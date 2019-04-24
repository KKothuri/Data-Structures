#ifndef PAIR_H
#define PAIR_H

#define ull unsigned long long int

//Vector class to function like the STL vector class
template <class Obj1, class Obj2>

//Pair class to function like the STL pair class
class Pair
{
public:
	Obj1 first;
	Obj2 second;
	Pair(Obj1 f, Obj2 s) : first(f), second(s);
};

#undef ull

#endif