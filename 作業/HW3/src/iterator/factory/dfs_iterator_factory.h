#pragma once

#include "./iterator_factory.h"
#include "../../shape.h"

class DFSIteratorFactory : public IteratorFactory {
public:
    Iterator *createIterator() override;
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) override;
};