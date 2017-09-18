

// Chapter 20, Exercise 19: define a range-checked iterator for list (a bidirec-
// tional iterator)

//#include "std_lib_facilities.h"
//#include "Iterator.h"

#include <assert.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>

using namespace std;

template<class Item>
class Iterator {
public:
	virtual ~Iterator();
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Item * CurrentItem() const = 0;
protected:
	Iterator();
};

template<class Item>
Iterator<Item>::Iterator() {
}

template<class Item>
Iterator<Item>::~Iterator() {
}
//------------------------------------------------------------------------------

struct A {
	A(string mark) :
			mMark(mark) {
	}
	string mMark;
};

//------------------------------------------------------------------------------

template<class T>
class IteratorList: public Iterator<T> {
	typename list<T>::iterator curr;
	typename list<T>::iterator first;
	typename list<T>::iterator last;
public:
	virtual ~IteratorList() {}
	IteratorList(typename list<T>::iterator c, typename list<T>::iterator f,
			typename list<T>::iterator l) :
				curr(c), first(f), last(l) {
	}

	void  Init(typename list<T>::iterator c, typename list<T>::iterator f, typename list<T>::iterator l ) {
		curr = c;
		first = f;
		last = l;
	}

	// By GoF
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual T* CurrentItem() const;

	// Стратуструп
	T& operator*() {
		return *curr;
	}
	const T& operator*() const {
		return *curr;
	}
	T* operator->() {
		return &(*curr);
	}


	IteratorList& operator++();
	IteratorList& operator--();
};

template<typename T>
class ContainerList {
public:
	ContainerList() {
	}
	void PushBack(T car) {
		Cares.push_back(car);
	}

	typename list<T>::iterator Begin() {
		return Cares.begin();
	}

	typename list<T>::iterator End() {
		return Cares.end();
	}
private:
	list<T> Cares;
};

template<typename T>
class CollectionList {
public:
	CollectionList() :
		containList(), itList(containList.Begin(), containList.Begin(), containList.End()) { // my пустой itList тоже инит. копиями пустых итераторов
		// идея связать containList и itList на этапе создания коллекции (заранее)
	}
	void Add(T item) {
		containList.PushBack(item);
	}
	T* Get() {
		return itList.CurrentItem();
	}

	void First() {
		itList.Init(containList.Begin(), containList.Begin(), containList.End());
		itList.First();
	}

	void Next() {
		itList.Next();
	}

	bool IsDone() {
		return itList.IsDone();
	}

private:
	ContainerList<T> containList;
	IteratorList<T> itList;
};

//------------------------------------------------------------------------------

int main() {
	try {

		A* a1 = new A("bmw");
		A* a2 = new A("honda");
		A* a3 = new A("mazda");

		CollectionList<A*> coll;
		coll.Add(a1);
		coll.Add(a2);
		coll.Add(a3);

		cout  << " collection : \n";

		for(coll.First(); !coll.IsDone(); coll.Next()){
			A *a = *coll.Get();
			cout << a->mMark << "\n";
		}
//		 coll.Next(); //  assert error

	}

	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
	}
	catch (...) {
		cerr << "exception\n";
	}
}

//------------------------------------------------------------------------------

template<class T>
IteratorList<T>& IteratorList<T>::operator++() {
	++curr;
	if (curr == last)
		assert(!"iterator past end of list");
	return *this;
}

template<class T>
IteratorList<T>& IteratorList<T>::operator--() {
	if (curr == first)
		assert(!"iterator before begin of list");
	--curr;
	return *this;
}

//------------------------------------------------------------------------------

template<class T>
void IteratorList<T>::First() {
	curr = first;
}

template<class T>
void IteratorList<T>::Next() {

	if (curr != last)
		++curr;
	else
		assert(!"iterator past end of list");
}

template<class T>
bool IteratorList<T>::IsDone() const {
	return curr == last;
}

template<class T>
T* IteratorList<T>::CurrentItem() const {
	return &(*curr);
}
