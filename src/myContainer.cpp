//============================================================================
// Name        : myContainer.cpp
// Author      : Kasianov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Chapter 20, Exercise 19: define a range-checked iterator for list (a bidirec-
// tional iterator)

#include "std_lib_facilities.h"
#include "Iterator.h"


template<class T>
class IteratorList_rc : public Iterator<T> {
	typename list<T>::iterator curr;
	typename list<T>::iterator first;
	typename list<T>::iterator last;
public:
 	virtual ~IteratorList_rc() {}
	IteratorList_rc(typename list<T>::iterator c, typename list<T>::iterator f, typename list<T>::iterator l)
		: curr(c), first(f), last(l) { }

	T& operator*() { return *curr; }
	const T& operator*() const { return *curr; }
	T* operator->() { return &(*curr); }

	IteratorList_rc& operator++();
	IteratorList_rc& operator--();

	//bool operator==(const l_iterator_rc& other) { return curr==other.curr; }
	//bool operator!=(const l_iterator_rc& other) { return !(*this==other); }

	/************************************************************************/
	public:
	 virtual void Next();
	 virtual void First();
	 virtual bool IsDone() const;
	 virtual T* CurrentItem() const;

	 typename list<T>::iterator Curr() {
		return curr;
	 }
};

template<class T>
T* IteratorList_rc<T>::CurrentItem() const {
	return &(*curr); //  error if(curr == nullptr) return 0;
}

//------------------------------------------------------------------------------
template<class T>
IteratorList_rc<T>& IteratorList_rc<T>::operator++()
{
	++curr;
	if (curr==last) error("iterator past end of list");
	return *this;
}

//------------------------------------------------------------------------------
template<class T>
IteratorList_rc<T>& IteratorList_rc<T>::operator--()
{
	if (curr==first) error("iterator before begin of list");
	--curr;
	return *this;
}

template<class T>
void IteratorList_rc<T>::First() {
	curr = first;
	// return this->Next()
}

template<class T>
void IteratorList_rc<T>::Next() {

	if (curr != last)
		++curr;
	else
		error("iterator past end of list");
	//return *this;
}

template <class T>
bool IteratorList_rc<T>::IsDone() const {
	return curr == last ;
}

//------------------------------------------------------------------------------
struct A {
	A(int i1, int i2, string mark) : a(i1), b(i2), mMark(mark) { }
	int a;
	int b;
	string mMark;

};

template <typename T>
class ConstainerList {
public:
	ConstainerList() {
	}
	void PushBack(T car) {
		Cares.push_back(car);
	}

	typename list<T>::iterator  Begin() {
		return Cares.begin();
	}

	typename list<T>::iterator End() {
		return Cares.end();
	}
private:
	 list<T> Cares;
};

template< typename T>
class CollectionList {
public:
	CollectionList() :myLa(), myIta_rc(myLa.Begin(), myLa.Begin(), myLa.End()) { // my пустой myIta_rc тожет инит. копиями пустых итераторов
				// идея связать myLa и myIta_rc на этапе создания коллекции (зарание)
	}
	void Add(T item) {
		myLa.PushBack(item);
	}
	void First() {
		myIta_rc.First();
	}
	void Next() {
		myIta_rc.Next();
	}

	T* Get() {
		return myIta_rc.CurrentItem();
	}

private:
	ConstainerList<T> myLa;
	IteratorList_rc<T> myIta_rc;
};

template< typename T>
class TestConsructorIteratorRef {
public:
	TestConsructorIteratorRef(typename list<T>::iterator  iterByMyContain) : mRefIt(iterByMyContain) {
		//++iterByMyContain;			// инкрементируется только в конструкторе
	}

	void testNext() {

		cout << "Ref test :" << mRefIt->mMark <<  "\n";
		++mRefIt;
	}

private:
	typename list<T>::iterator   mRefIt;

};


int main()
	try {


		A a1(0,1, "bmw");
		A a2(1,2, "honda");
		A a3(2,3, "lada");

		//  [9/15/2017 KASYANOVNN]
		CollectionList<A> coll;

		ConstainerList<A> myLa;

		TestConsructorIteratorRef<A> test(myLa.Begin());

		myLa.PushBack(a1);
		myLa.PushBack(a2);
		myLa.PushBack(a3);
		myLa.PushBack(a3);
		myLa.PushBack(a3);
		myLa.PushBack(a3);

		coll.Add(a1);
		coll.Add(a2);
		coll.Add(a3);

		coll.First();
		//col.Next();
		//coll.Get();
		//cout << "test" << coll.Get()->mMark << "\n";

		// Проблема сосбетвенным контейнером
	//	IteratorList_rc<A> myIta_rc(myLa.Begin(), myLa.Begin(), myLa.End());

		//TestConsructorIteratorRef<A> test(myIta_rc.Curr());
		test.testNext();
		//myIta_rc.Next();

		test.testNext();
		//myIta_rc.Next();

		test.testNext();
		//myIta_rc.Next();
//
//		test.testNext();
//		//myIta_rc.Next();

		//test.foo(myLa.End() );

		//for (myIta_rc.First(); !myIta_rc.IsDone(); myIta_rc.Next()) {
		//	A* tmp = myIta_rc.CurrentItem();
		//	cout << tmp->mMark << ' ' << tmp->b << "\n";
		//	//test.foo(myIta_rc.Curr() );
		//}
}

catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

