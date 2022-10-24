#pragma once

#include "./iterator.h"
#include "../shape.h"

template <class ForwardIterator>
class ListCompoundIterator : public Iterator
{
public:
    ListCompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end) {
        first();
    }

    void first() override {
        _current = _begin;
    }

    Shape *currentItem() const override {
        if (isDone()) {
            throw(std::string("is done. you might need to call first() first"));
        }
        return *_current;
    }

    void next() override {
        if (isDone()) {
            throw(std::string("is done. you might need to call first() first"));
        }
        _current++;
    }

    bool isDone() const override {
        return _current == _end;
    }
    
private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};
