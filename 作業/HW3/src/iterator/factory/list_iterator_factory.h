#pragma once

#include "./iterator_factory.h"
#include "../list_compound_iterator.h"
#include "../null_iterator.h"

class ListIteratorFactory : public IteratorFactory {
public:
    Iterator *createIterator() override {
        return new NullIterator();
    };
    
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) override {
        return new ListCompoundIterator<std::list<Shape *>::const_iterator>(begin, end);
    };
};