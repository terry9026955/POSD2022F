#pragma once

#include "shape.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

#include <list>

class CompoundShape : public Shape
{
private:
    std::list<Shape *> _shapes;

public:
    CompoundShape(Shape **shapes, int size) {
        _shapes = std::list<Shape *>(shapes, shapes+size);
    }

    CompoundShape() {}

    ~CompoundShape() {
        _shapes.clear();
    }

    double area() const override {
        double result = 0;
        for (auto shape: _shapes) {
            result+=shape->area();
        }
    }

    double perimeter() const override {
        double result = 0;
        for (auto shape: _shapes) {
            result+=shape->perimeter();
        }
    }

    std::string info() const override {
        std::string infoString;
        infoString+="CompoundShape (";
        auto itBeforeEnd = _shapes.end();
        itBeforeEnd--;
        for (auto it = _shapes.begin(); it!=_shapes.end(); it++) {
            infoString += (*it)->info();
            if (it != itBeforeEnd) {
                infoString+=", ";
            }
        }
        infoString += ")";
        return infoString;
    }

    // Iterator* createDFSIterator() override {
    //     return new DFSCompoundIterator<std::list<Shape *>::iterator>(_shapes.begin(), _shapes.end());
    // }

    // Iterator* createBFSIterator() override {
    //     return new BFSCompoundIterator<std::list<Shape *>::iterator>(_shapes.begin(), _shapes.end());
    // }

    void addShape(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override {
        for (auto s: _shapes) {
            if (s->area() == shape->area() && s->perimeter() == shape->perimeter()){
                _shapes.remove(s);
                break;
            }
        }
    }

    std::list<Shape *> shapes() override {
        return _shapes;
    }

    
    // HW3
    Iterator *createIterator(IteratorFactory *factory) override {
        return factory->createIterator(_shapes.begin(), _shapes.end());
    }

    std::set<const Point*> getPoints() override {
        std::set<const Point*> points{};
        for (auto shape: _shapes) {
            auto tempPoints = shape->getPoints();
            points.insert(tempPoints.begin(), tempPoints.end());
        }
        return points;
    }

    void accept(ShapeVisitor* visitor) {
        visitor->visitCompoundShape(this);
    };
};