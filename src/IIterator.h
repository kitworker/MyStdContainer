#ifndef ITERATOR_H
#define ITERATOR_H

class IIterator {
public:
    virtual ~IIterator();
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    template<class Item>
    Item * CurrentItem() const {
    	assert(!"Incorrect overridden");
    	return NULL;
    }
protected:
    IIterator();
};

IIterator::IIterator() {
}

IIterator::~IIterator() {
}

#endif /* ITERATOR_H */
