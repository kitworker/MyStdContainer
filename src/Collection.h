/*
 * CollectionList.h
 *
 *  Created on: 18 ����. 2017 �.
 *      Author: KASYANOVNN
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_


template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> >
		class TContain>
class CollectionStl {
public:
	CollectionStl() :
			contain(), iter(contain) {
	}

	void Add(TData item) {
		contain.PushBack(item);
	}
	const TData& Get() {
		return iter.CurrentItem();
	}

	void First() {
		iter.First();
	}

	void Next() {
		iter.Next();
	}

	bool IsDone() {
		return iter.IsDone();
	}

	void Print() {
		for (First(); !IsDone(); Next()) {
			TData tmp = Get();
			assert(cout << tmp->mMark << "\n" && " debug");
		}
	}

public:
	ContainerStl<TData, TContain> contain;
	IteratorStl<TData, TContain> iter;
};

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> >
		class TContain>
class CollectionBack {
public:
	CollectionBack() :
			contain(), iterBck(contain) {
	}

	void Add(TData item) {
		contain.PushBack(item);
	}
	const TData& Get() {
		return (*iterBck.CurrentIterator() );
	}

	// Decoration for iterator:
	void End() {
		iterBck.End();
	}

	void Prev() {
		iterBck.Prev();
	}

	bool IsHead() {
		return iterBck.IsHead();
	}

	void Print() {
		for (End(); !IsHead(); Prev()) {
			TData tmp = Get();
			assert(cout << tmp->mMark << "\n" && " debug");
		}
	}

public:
	ContainerStl<TData, TContain> contain;
	IteratorBack<TData, TContain> iterBck;
};

#endif /* COLLECTION_H_ */
