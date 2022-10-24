#pragma once

#include <list>

#include "shape.h"
#include "iterator.h"
#include "./find_first_visitor.h"

class CompositeShape : public Shape {
    friend class ShapeIterator;
public:
    CompositeShape(Shape** shapes, int size)
        :_shapes(shapes, shapes + size) {}
    
    ~CompositeShape() {
        for (auto shape_ptr : _shapes) {
            delete shape_ptr;
        }
    }

    double area() const override {
        double result = 0;
        for (auto shape_ptr : _shapes) {
            result += shape_ptr->area();
        }
        return result;
    }

    bool include(double const px, double const py) const override {
        for (std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); ++it) {
            if ((*it)->include(px, py)) {
                return true;
            }
        }
        return false;
    }

    Iterator* createIterator() override {
        return new ShapeIterator(this);
    }

    void add(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void remove(Shape* shape) override {
        _shapes.remove( shape );
    }

    void accept(FindFirstVisitor &visitor) override {
        visitor.visitCompositeShape(this);
    }    

private:
    std::list<Shape*> _shapes;
};