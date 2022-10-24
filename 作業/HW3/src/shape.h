#pragma once

#include "./iterator/factory/iterator_factory.h"
#include "./point.h"
#include <string>
#include <list>
#include <set>

class ShapeVisitor;

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual ~Shape() {};

    virtual void addShape(Shape *shape) {
        throw std::string("Uncomposite shape don't have method of addShape.");
    };

    virtual void deleteShape(Shape *shape) {
        throw std::string("Uncomposite shape don't have method of deleteShape.");
    };

    // Maybe here can use 'throw error'
    virtual std::list<Shape *> shapes() {
        return {}; 
    };

    virtual Iterator* createIterator(IteratorFactory * factory) {
        return factory->createIterator();
    };

    virtual std::set<const Point*> getPoints() = 0;
    
    virtual void accept(ShapeVisitor* visitor) = 0;
};
