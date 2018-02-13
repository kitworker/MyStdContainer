#ifndef ITERATOR_H
#define ITERATOR_H

//template<class Item>
class IIterator {
public:
    virtual ~IIterator();
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    //virtual Item * CurrentItem() const = 0;
    template<class Item>
    Item * CurrentItem() const {
    	assert(!"Incorrect overridden");
    	return NULL;
    }
protected:
    IIterator();
};

//template<class Item>
IIterator::IIterator() {
}

//template<class Item>
IIterator::~IIterator() {
}

#endif /* ITERATOR_H */
