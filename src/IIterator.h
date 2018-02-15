#ifndef ITERATOR_H
#define ITERATOR_H

class Accessor {
public:
    template<class Item>
    Item * CurrentItem() const {
    	assert(!"Incorrect overridden");
    	return NULL;
    }
};

class IIterator : public Accessor {
public:
    virtual ~IIterator();
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;

protected:
    IIterator();
};

class IIteratorBack : public Accessor {
public:
    virtual ~IIteratorBack() {}
    virtual void End() = 0;
    virtual void Prev() = 0;
    virtual bool IsHead() const = 0;

protected:
    IIteratorBack() {}
};

IIterator::IIterator() {
}

IIterator::~IIterator() {
}

#endif /* ITERATOR_H */
