/*
 * Iterator.hpp
 *
 *  Created on: 13 февр. 2018 г.
 *      Author: knik
 */

#ifndef ITERATOR_HPP_
#define ITERATOR_HPP_


template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
void IteratorStl<TData, TContain>::First() {
    curr = container.Begin();
}

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
void IteratorStl<TData, TContain>::Next() {
   assert(curr != container.End() && "iterator past end of list" );
   ++curr;
}


template<typename TData, template<typename Tp, typename Alloc =std::allocator<Tp> > class TContain>
void IteratorBack<TData, TContain>::Prev() {
	assert(rCurr != container.rEnd() && "iterator past head of list" );
	++rCurr;
}

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
bool IteratorStl<TData, TContain>::IsDone() const {
    return curr == container.End();
}


template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
bool IteratorBack<TData, TContain>::IsHead() const {
	return rCurr == container.rEnd();
}


template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
const TData& IteratorStl<TData, TContain>::CurrentItem() const {
	assert(curr != container.End() && " collection is empty or need in advance to call First() ");
    return (*curr);
}

//template<typename TData, template<typename Tp, typename Alloc = std::allocator<Tp> > class TContain>
//const IteratorStl<TData, TContain>::iterator& IteratorStl<TData, TContain>::CurrentIterator() const{
//	return curr;
//}

//template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
////const iterator& IteratorStl<TData, TContain>::CurrentIterator() const {
//const iterator& IteratorStl<TData, TContain>::CurrentIterator() const {
//    return curr;
//}


template<typename TData, template<typename Tp, typename Alloc =std::allocator<Tp> > class TContain>
void IteratorBack<TData, TContain>::End()  {
	rCurr = container.rBegin();
}


#endif /* ITERATOR_HPP_ */
