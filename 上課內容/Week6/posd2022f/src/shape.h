#pragma once
#include <string>
#include "./iterator.h"
#include "./null_iterator.h"
// #include "./find_first_visitor.h"

class FindFirstVisitor;

class Shape {
public:
    // virtual: dynamic binding
    virtual double area() const = 0;

    virtual bool include(double const px, double const py) const {
        return false;  // dummy value
    }

    virtual void add(Shape *) {
        throw std::string("cannot add shape");
    }

    virtual void remove(Shape *) {
        throw std::string("cannot remove shape");
    }

    virtual Iterator* createIterator() {
        return new NullIterator();
    }

    virtual void accept(FindFirstVisitor& visitor) {}

    virtual ~Shape() {}
};