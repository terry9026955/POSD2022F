#pragma once

#include "string"
#include <list>

class Iterator;

class Shape
{
public:
    virtual ~Shape() {};    // virtual destructor
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual Iterator *createDFSIterator() = 0;
    virtual Iterator *createBFSIterator() = 0;
    
    virtual void addShape(Shape *shape) {
        throw std::string("Uncomposite shape don't have method of addShape.");
    }
    
    virtual void deleteShape(Shape *shape) {
        throw std::string("Uncomposite shape don't have method of deleteShape.");
    }

    // For BFS/DFS iterator operations
    virtual std::list<Shape *> shapes() {
        return {};
    }
};