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

#endif /* COLLECTION_H_ */
