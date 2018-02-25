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
			container(c), curr(c.Begin()) { }

	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	const TData& CurrentItem() const;
	typedef typename TContain<TData>::iterator iterator;
	const iterator& CurrentIterator() const { return curr; }
private:
	ContainerStl<TData, TContain> & container;
//	typename ContainerStl<TData, TContain>::iterator curr;
	iterator curr;
};

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> >
		 class TContain>
class IteratorBack: public IIteratorBack{
	typedef typename TContain<TData>::reverse_iterator reverse_iterator;
	ContainerStl<TData, TContain> & container;
	reverse_iterator rCurr;
public:
	virtual ~IteratorBack() { }

	IteratorBack(ContainerStl<TData, TContain> &  c) :
		container(c), rCurr( c.rBegin()) { }

	virtual void End();
	virtual void Prev();
	virtual bool IsHead() const;
	// TODO return iterator, but not return TData, it need deligieted in class Collection
	const reverse_iterator& CurrentIterator() const { return rCurr; }

};

#include "Iterator.hpp"

#endif /* ITERATOR_H_ */
