#pragma once

#include "shape.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./iterator/bfs_compound_iterator.h"

#include <list>
#include <iostream>
using namespace std;

class CompoundShape : public Shape
{
private:
    std::list<Shape *> _shapes;

public:
    CompoundShape(Shape **shapes, int size): _shapes(shapes, shapes + size) {}
    CompoundShape() {}
    ~CompoundShape() {
        for(std::list<Shape*>::iterator it = _shapes.begin(); it != _shapes.end(); it++){
            delete *it;
        }
    }

    double area() const override {
        double result = 0.0;
        for(auto shape_ptr : _shapes){
            result += shape_ptr->area();
        }
        return result;
    }

    double perimeter() const override {
        double sum = 0.0;
        for(std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); ++it){
            sum += (*it)->perimeter();
        }
        return sum;
    }

    std::string info() const override {
        std::string start = "CompoundShape (";
        std::string end = ")";
        std::string middle = "";

        for (auto it: _shapes){
            middle = middle+it->info()+", ";
        }

        middle.pop_back();
        middle.pop_back();
        return start+middle+end;
    }

    Iterator* createDFSIterator() override {
        return new DFSCompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    Iterator* createBFSIterator() override {
        return new BFSCompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    void addShape(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override {
        if(shape == this) {
            throw std::string("Shape can't kill itself");
        }

        for(auto it : _shapes) {
            if(it == shape) {
                _shapes.remove(it);
                break;
            }
        }

        // 原本的寫法:
        // Iterator* it = createBFSIterator();

        // for(it->first(); !it->isDone(); it->next()){
        //     if(it->currentItem()==shape){
        //         _shapes.remove(shape);
        //         break;
        //     }
        // }

        // if(it->isDone()){
        //     throw std::string("This type of shape don't find in compoundshape.");
        // }
    }

    // For Iterator Operations
    std::list<Shape *> shapes() override {
        return _shapes;
    }
};