/*
 * IteratorList.h
 *
 *  Created on: 18 ����. 2017 �.
 *      Author: KASYANOVNN
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_


#include "Container.h"

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> >
		 class TContain>
class IteratorStl: public IIterator {
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
	const TData& CurrentItem() const;
private:
	ContainerStl<TData, TContain> & container;
	typename ContainerStl<TData, TContain>::iterator curr;
};

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> >
		 class TContain>
class IteratorBack: public IIteratorBack{
	//typename IteratorBack<TData, TContain>::reverse_iterator rCurr;
	typedef typename TContain<TData>::reverse_iterator reverse_iterator;
	ContainerStl<TData, TContain> & container;
	reverse_iterator rCurr;
public:
	virtual ~IteratorBack() {
	}

	IteratorBack(ContainerStl<TData, TContain> &  c) :
		container(c), rCurr( c.rBegin()) {
	}

	// By GoF
	virtual void End(){}
	virtual void Prev(){}
	virtual bool IsHead() const { return false; }
	const TData& CurrentItem() const { return NULL; }

};

#include "Iterator.hpp"

#endif /* ITERATOR_H_ */
