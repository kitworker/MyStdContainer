/*
 * IteratorList.h
 *
 *  Created on: 18 сент. 2017 г.
 *      Author: KASYANOVNN
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_


#include "Container.h"

template<typename T>
class ContainerList ;

template<class T>
class IteratorList: public IIterator<T> {
    ContainerList<T> & container;
    typename ContainerList<T>::iterator curr; // change part

public:
    virtual ~IteratorList() {}
    IteratorList(ContainerList<T> & c)
        : container(c), curr(c.Begin())
    { }

    // By GoF
    virtual void First();
    virtual void Next();
    virtual bool IsDone() const;
    virtual T* CurrentItem() const;

    // Stroustrup
    IteratorList& operator++();
    IteratorList& operator--();
    T& operator*() {
        return *curr;
    }
    const T& operator*() const {
        return *curr;
    }
    T* operator->() {
        return &(*curr);
    }
};


//--------------------------------------------------------

//template<class T>
template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> >
		 class TContain>
class IteratorStl: public IIterator<TData> {
public:
	virtual ~IteratorStl() {
	}
	IteratorStl(ContainerStl<TData, TContain> &  c) :
			container(c), curr(c.Begin()) {
	}

	// By GoF
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual TData* CurrentItem() const;
private:
	ContainerStl<TData, TContain> & container;
	typename ContainerStl<TData, TContain>::iterator curr;
};

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
void IteratorStl<TData, TContain>::First() {
    curr = container.Begin();
}

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
void IteratorStl<TData, TContain>::Next() {
   assert(curr != container.End() && "iterator past end of list" );
   ++curr;
}

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
bool IteratorStl<TData, TContain>::IsDone() const {
    return curr == container.End();
}

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
TData* IteratorStl<TData, TContain>::CurrentItem() const {
	assert(curr != container.End() && " collection is empty or need in advance to call First() ");
    return &(*curr);
}
#endif /* ITERATOR_H_ */
