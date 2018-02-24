/*
 * ContainerList.h
 *
 *  Created on: 18 ����. 2017 �.
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

	IContainer(){}	// TODO �� ���������� ������� ��������� ���������, ������?
private:
};

template<typename TData, template<typename _Tp,	typename _Alloc = std::allocator<_Tp> > class TContain>
class ContainerStl: public IContainer<TData, TContain> {
	ContainerStl(const ContainerStl&) ;
	ContainerStl& operator=(const ContainerStl&) ;
public:

	ContainerStl() {	}
	virtual ~ContainerStl() {	}

	typedef typename TContain<TData>::iterator iterator; // TODO ���������� ����������

	virtual void PushBack(TData item) {
		items.push_back(item);
	}

	virtual iterator Begin() {
		return items.begin();
	}

	typedef typename TContain<TData>::reverse_iterator reverse_iterator;
	virtual reverse_iterator rBegin() {
		return items.rbegin();
	}


	virtual iterator End() {
		return items.end();
	}

	virtual reverse_iterator rEnd() {
		return items.rend();
	}
private:
	TContain<TData> items;
};


#endif /* CONTAINER_H_ */
