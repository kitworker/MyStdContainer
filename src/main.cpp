#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <vector>


using namespace std;

#include "Data.h"

#include "IIterator.h"
//------------------------------------------------------------------------------
#include "Iterator.h"
//--------------X---------------------------------------------------------------
#include "Container.h"
//------------------------------------------------------------------------------

#include "Collection.h"


int main() {
    try {

        A* a1 = new A("bmw");
        A* a2 = new A("honda");
        A* a3 = new A("mazda");


        CollectionList<A*> coll;
        coll.Add(a1);
        coll.Add(a2);
        coll.Add(a3);

        cout  << " simple collection on list	: \n";
        for(coll.First(); !coll.IsDone(); coll.Next()){
            A *a = *coll.Get();
            cout << a->mMark << "\n";
        }

        //------------------------------------------------------

        CollectionStl<A*, list> collList;
        collList.Add(a1);
        collList.Add(a2);
        collList.Add(a3);

        cout  << " collection on template list  : \n";
        collList.Print();

        CollectionStl<A*, vector> collVector;
        collVector.Add(a1);
        collVector.Add(a2);
        collVector.Add(a3);

        cout  << " collection on  template vector : \n";
        collVector.Print();
        //collVector.Next();
        //A *a = *collVector.Get();

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
    assert(curr != container.End() && "iterator past end of list");
    ++curr;
    return *this;
}

template<class T>
IteratorList<T>& IteratorList<T>::operator--() {
    assert(curr != container.Begin() && "iterator before begin of list");
    --curr;
    return *this;
}

//------------------------------------------------------------------------------

template<class T>
void IteratorList<T>::First() {
    curr = container.Begin();
}

template<class T>
void IteratorList<T>::Next() {
   assert(curr != container.End() && "iterator past end of list" );
   ++curr;
}

template<class T>
bool IteratorList<T>::IsDone() const {
    return curr == container.End();
}

template<class T>
T* IteratorList<T>::CurrentItem() const {
	assert(curr != container.End() && " collection is empty or need in advance to call First() ");
    return &(*curr);
}
