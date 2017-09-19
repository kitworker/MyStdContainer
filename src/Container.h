/*
 * ContainerList.h
 *
 *  Created on: 18 сент. 2017 г.
 *      Author: KASYANOVNN
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_


#include "Iterator.h"


template<typename T>
class ContainerList {
public:
    typedef typename list<T>::iterator iterator;

    ContainerList() {
    }
    void PushBack(T car) {
        Cares.push_back(car);
    }

    iterator Begin() {
        return Cares.begin();
    }

    iterator End() {
        return Cares.end();
    }
private:
    list<T> Cares;
};

//----------------------------------------------------------------

template<typename TData, template< typename _Tp, typename _Alloc = std::allocator<_Tp> > class TContain >
class IContainer {
public:
	virtual ~IContainer(){}
	typedef typename TContain<TData>::iterator iterator;

	virtual void PushBack(TData item)=0;
	virtual iterator Begin()=0;
	virtual iterator End()=0;

	IContainer(){}	// TODO не получается сделать приватным приватным, почему?
private:
};

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
class ContainerStl: public IContainer<TData, TContain> {
	ContainerStl(const ContainerStl&) ;
	ContainerStl& operator=(const ContainerStl&) ;
public:

	ContainerStl() {	}
	virtual ~ContainerStl() {	}

	typedef typename TContain<TData>::iterator iterator; // TODO повтороное объявление

	virtual void PushBack(TData item) {
		items.push_back(item);
	}

	virtual iterator Begin() {
		return items.begin();
	}

	virtual iterator End() {
		return items.end();
	}
private:
	TContain<TData> items;
};


#endif /* CONTAINER_H_ */
