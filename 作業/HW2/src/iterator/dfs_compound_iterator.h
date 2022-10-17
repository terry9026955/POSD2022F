#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>
#include <stack>


class CompoundShape;

template<class ForwardIterator>

// DFS by Stack 寫法
class DFSCompoundIterator : public Iterator
{
public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end) {
        first();
    }

    void first() override {
        // To clear
        std::stack<Shape*> empty;
        std::swap(_shapesStack, empty);

        std::stack<Shape*> tempShape;

        for (ForwardIterator it = _begin; it != _end; ++it) {
            tempShape.push(*it);
        }

        for (; !tempShape.empty(); tempShape.pop()) {
            _shapesStack.push(tempShape.top());
        }
    }

    Shape* currentItem() const override {
        if(isDone()) {
            throw std::string("The element is done at the end of the point");
        } 
        
        return _shapesStack.top();
    }

    void next() override {
        if(isDone()) {
            throw std::string("No next element can iterate");
        } 

        std::stack<Shape *> tempShape;

        for (auto shapeIt: _shapesStack.top()->shapes()) {
            tempShape.push(shapeIt);
        }

        _shapesStack.pop();

        for (; !tempShape.empty(); tempShape.pop()) {
            _shapesStack.push(tempShape.top());
        }
    }

    bool isDone() const override {
        return _shapesStack.empty();
    }

private:
    ForwardIterator _begin;
    ForwardIterator _end;
    // ForwardIterator _current;
    std::stack<Shape*> _shapesStack;
};