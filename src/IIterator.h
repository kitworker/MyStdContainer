#ifndef ITERATOR_H
#define ITERATOR_H

template<class Item>
class IIterator {
public:
    virtual ~IIterator();
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Item * CurrentItem() const = 0;
protected:
    IIterator();
};

template<class Item>
IIterator<Item>::IIterator() {
}

template<class Item>
IIterator<Item>::~IIterator() {
}

#endif /* ITERATOR_H */
